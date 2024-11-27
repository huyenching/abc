#include <iostream>
#include<vector>
using namespace std;

typedef struct vec {
    int size;
    int max;
    int *mang;
}Vec_to;

// 1.Khoi tao vector
void khoitao(Vec_to &vec)
{
	vec.size =0;
	vec.max=50;
	vec.mang = new int[vec.max];
}
// 2.Xoa bien vecto
void xoavecto(Vec_to & vec){
	delete[] vec.mang;
}
// 3.Kiem tra vector rong
bool kiemtra(Vec_to & vec){
	return (vec.size ==0);
}

// 4.Cap nhat phan tu
int capnhat(Vec_to &vec)
{
	return vec.size;
}
//tang dung luong vecto
void tangdungluong(Vec_to &vec, int x){
	if(vec.size>=x) return ;
	int *ptr=vec.mang;
	vec.mang= new int[x];
	for(int i=0;i<vec.size;i++){
		vec.mang[i]=*(ptr+i);
	}
	delete[] ptr;
	vec.max=x;
}
// 5.Chen vao cuoi vector
void themcuoi(Vec_to &vec, int x){
	if(vec.size==vec.max){
		tangdungluong(vec,vec.max+=1);
	}
		vec.mang[vec.size]=x;
		vec.size++;

}
//6.chen vao dau vecto
void themdau(Vec_to &vec,int x)
{
	if(vec.size==vec.max){
		tangdungluong(vec,vec.max+=1);
	}
	{
		for(int i=vec.size;i>0;i--)
		{
			vec.mang[i]=vec.mang[i-1];
		}
		vec.mang[0]=x;
		vec.size++;
	}
}
//7.them hop li trong vecto
void themhoply(Vec_to &vec,int x)
{
int index=vec.size;
	if(vec.size==vec.max){
		tangdungluong(vec,vec.max+=1);
	}
	for(int i=0;i<vec.size;i++){
		if(vec.mang[i]>x){
			index =i;
			break;
		}
	}
	for(int i=vec.size;i>index;i--){
		vec.mang[i]=vec.mang[i-1];
	}
	vec.mang[index]=x;
	vec.size+=1;
}
//8 xoa phan tu o vtri i cua vecto
void xoaphantu(Vec_to &vec,int k)
	{
	for(int i=k;i<vec.size-1;i++)
	{
		vec.mang[i]=vec.mang[i+1];
	}
	vec.size-=1;
}
//9.in noi dung vecto
void In(Vec_to &vec)
{
	for(int i=0;i<vec.size;i++)
	{
		cout<<vec.mang[i]<<" ";
}
	cout<<endl;
}
//10 tim kiem x trong vecto
bool timkiem(Vec_to &vec,int x){
	for(int i=0;i<vec.size;i++){
		if(vec.mang[i]==x) return true;
	}
	return false;
}
//11.sao  chep vecto
void khoitao1(Vec_to &vec2){
	
}
void saochep(Vec_to &vec2, Vec_to &vec)
{
	vec.size= vec2.size;
	vec.max= vec2.max;
	vec2.mang = new int[vec.max];
	if(int i=0;i<vec.size;i++){
		vec.mang[i]=vec2.mang[i];
	}
}
void nhap(Vec_to &vec){
	int n;
	cout<<"nhap gia tri n: ";
	cin>>n;
	vec.size=n;
	vec.max=100;
	vec.mang=new int[100];
	for(int i=0;i<vec.size;i++){
		cin>>vec.mang[i];
	}
}
int main(){
	Vec_to vec;	
	nhap(vec);
	In(vec);
	int k;
	if(kiemtra(vec)){
		cout<<"True";
	}
	else cout<<"false";
	cout<<"\nNhap k:"; cin>>k;
	cout<<"vecto sau khi them cuoi:";
	themcuoi(vec,k);
	In(vec);
	int b;
	cout<<"nhap b:"; cin>>b;
	cout<<"vecto sau khi them dau:";
	themdau(vec,b);
	In(vec);
	int x;
	cout<<"Nhap x: "; cin>>x;
	cout<<"vecto sau khi them hop li:";
	themhoply(vec,x);
	In(vec);
	int y;
	cout<<"nhap y: ";cin>>y;
	cout<<"vecto sau khi xoa: ";
	xoaphantu(vec,y);
	In(vec);
	int z;
	cout<<"nhap z:"; cin>>z;
	if(timkiem(vec,z)) {
		cout<<"true";
	}
	else cout<<"false";
	return 0;
}
