#include <iostream>
#include <queue>

using namespace std;

int main()
{ 
    // Tao hang doi uu tien chua cac so nguyen
    priority_queue<int> pq;
    // Chen lan luot vao hang doi uu tien: 26, 12, 7, 3, 8, 33, 17, 46
    pq.push(26);
    pq.push(12);
    pq.push(7);
    pq.push(3);
    pq.push(8);
    pq.push(33);
    pq.push(17);
    pq.push(46);
	
    // Rut cac phan tu ra khoi hang doi uu tien va in len man hinh
    while(!pq.empty())
    {
    	cout<<pq.top()<<" ";
    	pq.pop();
	}
    return 0;
}
