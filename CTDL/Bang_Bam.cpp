#include<iostream>
using namespace std;
typedef struct A{
	int *Data;
	int *ktra;
	int size;
}HashTb;
void khoitao(HashTb &b){
	b.Data=new int[10];
	b.ktra=new int[10];
	b.size=10;
	for(int i=0;i<b.size;i++){
		b.ktra[i]=0;
		}
}
void chenvtri(HashTb &b,int x){
	int i= x%b.size;
	while(b.ktra[i]==1){
		i++;
		i=i%b.size;
	}
	b.Data[i]=x;
	b.ktra[i]=1;
	
}
void gapdoi(HashTb &b){
	int *temp1=b.Data;
	int *temp2=b.ktra;
	b.Data=new int[b.size*2];
	b.ktra=new int [b.size*2];
	for(int i=0;i<b.size*2;i++){
		b.ktra[i]=0;
	}
	b.size*=2;
	for(int i=0;i<b.size/2;i++){
		if(temp2[i]==1)
		khoitao(tb,temp1[i]);
	delete[]temp1;
	delete[]temp2;
	}
}
/*int hash(int size){
	int hashVal=0;
	for(int i=0;i<)
}*/
int main(){
	//so n phan tu nhap tu ban phim thuc hien xay dung hang bam de luu tru so nguyen 
	int n;
	int a[n];
	do{
		cout<<"Nhap n: ";cin>>n;
	}while(n<=0 || n>23);
	for(int i=0;i<n;i++){
		cout<<"So thu "<<i+1<<" la: ";
		cin>>a[i];
	}
	
	return 0;
}
