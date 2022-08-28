#include <bits/stdc++.h>
using namespace std;
int main() {
//   Default Max Heap
//    priority_queue<int> pq;
//	 For Min heap, put vector<int> , greater<int>
	priority_queue<int , vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    while(!pq.empty()) {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}
