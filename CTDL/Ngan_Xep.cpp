#include<iostream>
#include<stack>
using namespace std;

int main(){
//chuyen doi nhi phan 
	int n;
	cout<<"nhap n:";cin>>n;
	stack<int> st;
	if(n!=0){
		st.push(n%2);
		n=n/2;
	}
	if(!st.empty){
		cout<<st.top();
		st.pop();
	}
	return 0;
}
