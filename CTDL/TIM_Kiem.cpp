#include<iostream>

using namespace std;
int timkiem(int a[], int x, int n){
	int l=0; int r=n-1;
	while(l<=r)
	{
		int mid=(r+l)/2;
		if(a[mid]==x){
			return mid;}
		else if (a[mid]>x)
			l=mid+1;
		else r=mid-1;
		}
	return -1;
}
int main(){
	int a[1000];
	int x,n;
	cout<<"Nhap n"; cin>>n;
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"] =";
		cin>>a[i];
	}
	cout<<"Nhap x"; cin>>x;
	cout<<"Vi tri cua "<<x<<" la:"<<timkiem(a,x,n);
	return 0;
}
