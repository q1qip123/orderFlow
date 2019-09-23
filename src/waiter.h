using namespace std;

#include <iostream>
#include <string>
#include <ccpp_orderData.h>

class Waiter {
public:
	Waiter(int, string);
	~Waiter();
	receiveOrder(int, string, int);
	deliverOrder(int, string, int);
private:
	string _name;
	int _publishCnt;
	int _subscribeCnt;
	bool _isBusy;
	DDSEntityManager entity_manager;



};
