#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <thread>
#include <Waiter.h>

#include <ccpp_OrderData.h>
#include <DDSEntityManager.h>
#include <vortex_os.h>
#include <semaphore.h>  

using namespace DDS;
using namespace OrderData;
using namespace std;


Waiter::Waiter(int id, string name, string partition){
	int length = partition.length();
	char partition_c_str[length +1 ];
	strcpy(partition_c_str, partition.c_str());

	entity_manager.createParticipant(partition_c_str);
	_name = name;
	_isBusy = false;

	orderTypeSupport_var mt = new orderTypeSupport();
	entity_manager.registerType(mt.in());

 	char odr_in_name[] = "odr_in";
	char odr_out_name[]  = "odr_out";
	entity_manager.createTopic(odr_in_name, odr_out_name);

	entity_manager.createPublisher();
	entity_manager.createSubscriber();

	sem_init(&waiter_sem, 0, 1); 

}

Waiter::~Waiter(){
	entity_manager.deletePublisher();
	entity_manager.deleteSubscriber();
	entity_manager.deleteTopic();
	entity_manager.deleteParticipant();
}

void Waiter::receiveOrder(int id, string dish, int amount){
	sem_wait(&waiter_sem);

	Topic_var odr_in = entity_manager.getOdrIn();
	entity_manager.createWriter(odr_in.in());
	
	dwriter = entity_manager.getWriter();
	OrderDataWriter = orderDataWriter::_narrow(dwriter.in());
	
	order OdrInstance;
	OdrInstance.customerID = id;
	OdrInstance.dish = DDS::string_dup(dish.c_str());
	OdrInstance.amount = amount;
	
	cout << endl << "Waiter : " << _name << " received Order " << endl;
	cout << "Received order from customer" << OdrInstance.customerID << endl;
	cout << "Dish : " << OdrInstance.dish << endl;

	ReturnCode_t status = OrderDataWriter->write(OdrInstance, DDS::HANDLE_NIL);
	checkStatus(status, "OrderDataWriter::write1");

	os_time delay_1s = { 1, 0 };
	os_nanoSleep(delay_1s);

	entity_manager.deleteWriter(OrderDataWriter.in());
	sem_post(&waiter_sem);
}

void Waiter::deliverOrder(){
	os_time delay_1s = { 1, 0 };
	os_time delay_200ms = { 0, 200000000 };

	Topic_var odr_out = entity_manager.getOdrOut();
	entity_manager.createReader(odr_out.in());
	
	dreader = entity_manager.getReader();
	OrderReader = orderDataReader::_narrow(dreader.in());
	checkHandle(OrderReader.in(), "orderDataReader::_narrow");

	orderSeq orderList;
	SampleInfoSeq infoSeq;
		
	bool orderFinished = false;
	int count = 0;
	ReturnCode_t status = -1;
	
	while (count < 50)
	{
		status = OrderReader->take(orderList, infoSeq, LENGTH_UNLIMITED, ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
		checkStatus(status, "orderDataReader::take");
		for (ulong j = 0; j < orderList.length(); j++)
		{
			if (infoSeq[j].valid_data){
				sem_wait(&waiter_sem);
				cout << endl << _name << " deliver " << orderList[j].dish << " to  customer" << orderList[j].customerID << endl;
				os_nanoSleep(delay_1s);
				sem_post(&waiter_sem);
			}
		}
		status = OrderReader->return_loan(orderList, infoSeq);
		checkStatus(status, "orderDataReader::return_loan() failed");
		os_nanoSleep(delay_200ms);
		count++;
	}
	entity_manager.deleteReader(OrderReader.in());
}

struct OrderList{
	int customerID;
        string dish;
        int amount;
};

int main(int argc, char *argv[])
{
	vector <struct OrderList> order_list;
	struct OrderList order;

	fstream file;
	char buffer[200];
	file.open("input.txt", ios::in);

	if(!file)
		cout << "Error happens while open file";
	else
	{
		char *p;
		const char * delim = " ";
		int icount = 0;
	 	
		while (!file.eof()){
			file.getline(buffer, sizeof(buffer));
			p = strtok(buffer, delim);
			while(p){
				if (icount % 3 == 0)
					order.customerID = atoi(p);
				else if (icount % 3 == 1)
					order.dish = p;
				else
					order.amount = atoi(p);
				icount++;
				p = strtok(NULL, delim);
			}
			if (strcmp(buffer, "\0") != 0)
				order_list.push_back(order);
		}
		file.close();	
	}


	Waiter waiter1(1, "waiter1", "order");
	thread mthread1(&Waiter::deliverOrder, ref(waiter1));
	for (int i = 0; i < order_list.size(); i++){
		waiter1.receiveOrder(order_list[i].customerID, order_list[i].dish, order_list[i].amount);

	}
	mthread1.join();
	return 0;



}
