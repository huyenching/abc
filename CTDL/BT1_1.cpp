#include<iostream>
#include<cmath>
using namespace std;
//su dung de quy tinh giai thua n
int giaithua1(int n){
	if(n==0) {
		return 1;}
	return (giaithua1(n-1)*n);}
//khong su dung de quy tinh giai thua n

int giaithua2(int n){
	int gt=1;
	int i;
	for(i=1;i<=n;i++){
		gt=gt*i;
	}
	return gt;
}

int main(){
	int n;
	cout<<"Nhap n:"; cin>>n;
	cout<<n<<"!= "<<giaithua1(n)<<endl;
	cout<<n<<"!= "<<giaithua2(n);
	return 0;
}

