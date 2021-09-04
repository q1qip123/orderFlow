#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include <ccpp_OrderData.h>
#include <DDSEntityManager.h>

#include <semaphore.h>  

using namespace DDS;
using namespace OrderData;
using namespace std;

class Waiter {
public:
	Waiter(int, string, string);
	~Waiter();
	void receiveOrder(int, string, int);
	void deliverOrder();
private:
	string _name;
	int _publishCnt;
	int _subscribeCnt;
	bool _isBusy;

	sem_t waiter_sem;

	DDSEntityManager entity_manager;

	DataWriter_var dwriter;
	orderDataWriter_var OrderDataWriter;
	
	DataReader_var dreader;
	orderDataReader_var OrderReader;


};
