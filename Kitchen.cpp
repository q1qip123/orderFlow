#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <Kitchen.h>

#include <ccpp_OrderData.h>
#include <DDSEntityManager.h>
#include <vortex_os.h>

//#include "example_main.h"
using namespace DDS;
using namespace OrderData;
using namespace std;


Kitchen::Kitchen(int id, string name, string partition){
	int length = partition.length();
	char partition_c_str[length +1 ];
	strcpy(partition_c_str, partition.c_str());

	entity_manager.createParticipant(partition_c_str);
	_name = name;
	_isBusy = false;

	orderTypeSupport_var mt = new orderTypeSupport();
	entity_manager.registerType(mt.in());

	char odr_in_name[] = "odr_in";
	char odr_out_name[] = "odr_out";
	entity_manager.createTopic(odr_in_name, odr_out_name);

	entity_manager.createPublisher();
	entity_manager.createSubscriber();
	
}

Kitchen::~Kitchen(){
	entity_manager.deletePublisher();
	entity_manager.deleteSubscriber();
	entity_manager.deleteTopic();
	entity_manager.deleteParticipant();
}

void Kitchen::finishOrder(int id, string dish, int amount){
	Topic_var odr_out = entity_manager.getOdrOut();
	entity_manager.createWriter(odr_out.in());

	dwriter = entity_manager.getWriter();
	OrderDataWriter = orderDataWriter::_narrow(dwriter.in());

	order OdrInstance;
	OdrInstance.customerID = id;
	OdrInstance.dish = DDS::string_dup(dish.c_str());
	OdrInstance.amount = amount;
	
	ReturnCode_t status = OrderDataWriter->write(OdrInstance, DDS::HANDLE_NIL);
	checkStatus(status, "orderDataWriter::write1");

	cout << "Order : " << dish << " is finished. " << endl;
	cout << "Ask waiter1 to deliver the dish"  << endl;

	os_time delay_1s = { 1, 0 };
	os_nanoSleep(delay_1s);

	entity_manager.deleteWriter(OrderDataWriter.in());
}

void Kitchen::makeOrder(){
	os_time delay_200ms = { 0, 200000000 };
	os_time delay_1s = { 1, 0 };

	Topic_var odr_in = entity_manager.getOdrIn();
	entity_manager.createReader(odr_in.in());

	cout << "initializing data reader.." << endl;
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
				cout << "Received order : " << orderList[j].dish << ", staring cooking ..."  << endl;
				os_nanoSleep(delay_200ms);
				finishOrder((int) orderList[j].customerID, (string) orderList[j].dish, (int) orderList[j].amount);

			}
		}
		status = OrderReader->return_loan(orderList, infoSeq);
		checkStatus(status, "orderDataReader::return_loan() failed");
		os_nanoSleep(delay_200ms);
		count++;
	}
	entity_manager.deleteReader(OrderReader.in());

}

int main(int argc, char *argv[])
{
	Kitchen kitchen(1, "kitchen", "order");
	kitchen.makeOrder();	
}
