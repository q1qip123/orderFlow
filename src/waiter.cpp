using namespace DDS;
using namespace orderData;

#include <iostream>
#include <string>
#include <Waiter.h>
#include <ccpp_orderData.h>
Waiter::Waiter(int id, string name){
	entity_manager.createParticipant(name);
	_publishCnt = 0;
	_name = name;
	_isBusy = false;

	MsgTypeSupport_var mt = new MsgTypeSupport();
	entity_manager.registerType(mt.in());

	char orderReceived[] = "orderReceived";
	entity_manager.createTopic(orderReceived);
	entity_manager.createPublisher();
	entity_manager.createWriter();

	char orderDeliver[] = "orderDeliver";
	entity_manager.createTopic(orderDeliver);
	entity_manager.createSubscriber();
	entity_manager.createReader();

}

Waiter::~Waiter(){
	entity_manager.deleteWriter();
        entity_manager.deletePublisher();
	entity_manager.deleteReader();
	entity_manager.deleteSubscriber();
        entity_manager.deleteTopic();
        entity_manager.deleteParticipant();
}

Waiter::receiveOrder(int id, string dish, int amount){
	DataWriter_var dwriter;
	MsgDataWriter_var OrderDataWriter;
	_publishCnt += 1;

	if (_publishCnt == 1){
		dwriter = mgr.getWriter();
		OrderWriter = MsgDataWriter::_narrow(dwriter.in());
	}

	order OdrInstance;
	OdrInstance.customerID = id;
	OdrInstance.dish = DDS::string_dup(dish);
	OdrInstance.amount = amount;
	
	ReturnCode_t status = OrderDataWriter->write(OdrInstance, DDS::HANDLE_NIL);
	checkStatus(status, "MsgDataWriter::write1");

	cout << endl << "Waiter : " << _name << "received Order " << endl;
	cout << "Received order from customer" << OdrInstance.customerID << endl;
	cout << "Dish : " << OdrInstance.dish << endl;
}

Waiter::deliverOrder(int id, string dish, int amount){
	DataReader_var dreader;
	MsgDataReader_var OrderReader;
	_subscribeCnt += 1;

	if (_subscribeCnt == 1){
		dreader = mgr.getReader();
        	OrderReader = MsgDataReader::_narrow(dreader.in());
		checkHandle(MsgReader.in(), "MsgDataReader::_narrow");
	}

	MsgSeq orderList;
	SampleInfoSeq infoSeq;
		
	bool orderFinished = false;
	int count = 0;
	ReturnCode_t status = -1;
	while (count < 50)
	{
		status = OrderReader->take(orderList, infoSeq, LENGTH_UNLIMITED, ANY_SAMPLE_STATE, ANY_VIEWSTATE, ANY_INSTANCE_STATE);
		checkStatus(status, "msgDataReader::take");
		for (DDS:Ulong j = 0; j < orderList.length(); j++)
		{
			if (infoSeq[j].valid_data){
				cout << "Deliver " << orderList[j].dish << " to " << orderList[j].customerID << endl;
			}
		}
		status = OrderReader->return_loan(orderList, infoSeq);
		checkStatus(status, "MsgDataReader::return_loan() failed");
		os_nanoSleep(delay_200ms);
		count++;
	}

}


int main(argc, char *argv[])
{

	

}
