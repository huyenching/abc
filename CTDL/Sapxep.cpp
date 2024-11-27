#include<iostream>
using namespace std;
void LuaChon(float *A, int n){
	float tg
	for(int i=0;i<n-1;i++){
		int max=i;
		for(int j=i+1;j<n;j++){
			if(A[max]<A[j]){
				max=j;
			}
		}
		if(max!=i)
		{
			tg=A[i];
			A[i]=A[max];
			A[max]=tg;
		}
	}
}
void sxchen(float *A, int n){
	int k;
	float temp;
	for(int i=0;i<n-1;i++){
		temp=A[i+1];
		for(k=i;k>=0;k--){
			if(A[temp]<A[k]){
				A[k+1]=A[k];
			}
			else break;
		}
		A[k+1]=temp;
	}
}
void noibot(float*A, int n){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=n-1-i;j>i;j--){
			if(a[j]>a[j-1]){
				temp=A[j];
				A[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
}
void hoatron(float &A, int n){
	
}
int main(){

}

