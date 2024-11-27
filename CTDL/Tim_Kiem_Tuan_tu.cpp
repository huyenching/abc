#include<iostream>

using namespace std;
 int timkiem(int a[], int k, int n)
 {
 	for(int i=0;i<n;i++)
 	{
		if(a[i]==k) return i;
 		
 }
 return -1;
}
int main()
{
 	int a[100];
 	int n;
	float k;
 	cout<<"Nhap n:"; cin>>n;
 	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]=";
 		cin>>a[i];
	 }
	 cout<<"Nhap k:"; cin>>k;
	cout<<"Vi tri cua "<<k<<" la: "<<timkiem(a,k,n);
 	return false ;
 }
