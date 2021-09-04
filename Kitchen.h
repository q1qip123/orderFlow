#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include <ccpp_OrderData.h>
#include <DDSEntityManager.h>

#include <example_main.h>

using namespace DDS;
using namespace OrderData;
using namespace std;

class Kitchen {
public:
	Kitchen(int, string, string);
	~Kitchen();
	void makeOrder();
	void finishOrder(int, string, int);
private:
	string _name;
	int _publishCnt;
	int _subscribeCnt;
	bool _isBusy;
	DDSEntityManager entity_manager;

	DataWriter_var dwriter;
	orderDataWriter_var OrderDataWriter;
	
	DataReader_var dreader;
	orderDataReader_var OrderReader;


};
