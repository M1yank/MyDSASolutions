#include<bits/stdc++.h>
using namespace std;

class MyDS
{	
	private:
	deque<int> dq;
	public:
	void insertMin(int x){
		dq.push_front(x);
	}
	void insertMax(int x){
		dq.push_back(x);
	}
	int getMin(){
		return dq.front();
	}
	int getMax(){
		return dq.back();
	}
	int extractMin(){
		int x=dq.front();
		dq.pop_front();
		return x;
	}
	int extractMax(){
		int x=dq.back();
		dq.pop_back();
		return x;
	}
};


int main()
{
	MyDS m;
	m.insertMax(20);
	m.insertMin(5);
	cout<<m.getMax();
	cout<<endl<<m.getMin();
	return 0;
}
