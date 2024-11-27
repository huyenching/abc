#include<iostream>
using namespace std;
	struct Diem {
		float Dqt, Dt;
	};
	int main(){
		Diem a;
		cout<<"Nhap dqt:"; cin>>a.Dqt;
		cout<<"Nhap dt:"; cin>>a.Dt;
		float Dtk=(a.Dqt+a.Dt)/2;
		cout<<"Diem tong ket: "<<Dtk;
		return 0;
}
