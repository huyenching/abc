#include<iostream>

using namespace std;
typedef struct v{
	int top;
	int *mang;
}Stack;
//khoi tao
void khoitao(Stack &s){
	s.top=0;
	s.mang=new(int[50]);
}
//dem so ptu
int dem(Stack &s){
	return s.top;
}
//day phan tu
void dayptu(Stack &s, int x){
	s.mang[s.top]=x;
	s.top++;
}
// lay phan tu
void laypt(Stack &s,int &x){
	x=s.mang[s.top-1];
	s.top--;
}
int main(){
	return 0;
}

