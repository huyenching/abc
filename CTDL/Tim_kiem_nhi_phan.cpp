#include<iostream>

using namespace std;
 int timkiem(int a[], int x, int n)
 {
 	int left=0; int right=n-1;
 	while(left<=right){
 		int mid=(left+right)/2;
 		if(a[mid]==x)
 			return mid;
 		else if(a[mid]<x)
 			left=mid+1;
 		else 
 			right=mid-1;
	 }
 return -1;
}
int main()
{
 	int a[100];
 	int n,x;
 	cout<<"Nhap n:"; cin>>n;
 	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]=";
 		cin>>a[i];
	 }
	 cout<<"Nhap k:"; cin>>x;
	cout<<"Vi tri cua "<<x<<" la: "<<timkiem(a,x,n);
 	return 0;
 }
