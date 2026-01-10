#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

struct RESULT
{
    int cnt;
    int IDs[5];
};

struct Order {
	int mID;
	int size;
	
	int status;
	int sequence;
	vector<int> madeDrinks;
	
	Order() {}
	Order(int id, int sz, int st, int seq) 
        : mID(id), size(sz), status(st), sequence(seq) {}
};

struct OrderComp {
	bool operator()(const Order& a, const Order& b) const {
		// 남은 음료의 개수가 많은 주문이 우선순위
		if(a.size != b.size) return a.size > b.size;
		
		// 남은 음료의 개수가 같다면 먼저 들어온 주문이 우선순위
		return a.sequence < b.sequence;
	}
};

int sequence;
int remaindOrder;
map<int, Order> orderMap;
set<Order, OrderComp> orderSet;
queue<int> drinkQueue[11];

void init(int N)
{
	sequence = 0;
	remaindOrder = 0;
	map<int, Order>().swap(orderMap);
	set<Order, OrderComp>().swap(orderSet);
	for(int i=1; i<=N; ++i) queue<int>().swap(drinkQueue[i]);
	
    return;
}

int order(int mID, int M, int mBeverages[])
{
	Order newOrder(mID, M, 1, ++sequence);
	
	orderMap[mID] = newOrder;
	orderSet.insert(newOrder);
	for(int i=0; i<M; ++i) drinkQueue[mBeverages[i]].push(mID);
	
    return ++remaindOrder;
}

int supply(int mBeverage)
{
	int mID;
	while(true) {
		if(drinkQueue[mBeverage].empty()) return -1;
		
		mID = drinkQueue[mBeverage].front();
		drinkQueue[mBeverage].pop();
		if(orderMap[mID].status != -1) break;
	}
	
	Order* target = &orderMap[mID];
	
	orderSet.erase(*target);
	target->madeDrinks.push_back(mBeverage);
	
	if(--(target->size)) orderSet.insert(*target);
	else {
		target->status = 0;
		--remaindOrder;
	}
	
    return mID;
}

int cancel(int mID)
{
	Order* target = &orderMap[mID];
	
	if(target->status == 0 || target->status == -1) return target->status;
	
	--remaindOrder;
	orderSet.erase(*target);
	target->status = -1;
	
	for(int drink : target->madeDrinks) supply(drink);
	
	return target->size;
}

int getStatus(int mID)
{
	Order* target = &orderMap[mID];
	
    if(target->status == 0 || target->status == -1) return target->status;
    return target->size;
}

RESULT hurry()
{
    RESULT res;
	
	set<Order, OrderComp>::iterator iter = orderSet.begin();
	int loopCnt = remaindOrder < 5 ? remaindOrder : 5;
	
	res.cnt = loopCnt;
	for(int i=0; i<loopCnt; ++i) {
		res.IDs[i] = iter->mID;
		iter++;
	}

    return res;
}
