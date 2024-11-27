#include<iostream>
using namespace std;
typedef struct a{
	int data;
	a*link
}node;
typedef struct b{
	node *dau;
	node *cuoi;
	int size;
}Queue;
void khoitao(Queue &q){
	q.dau=NULL;
	q.cuoi=NULL;
	q.size=0;
}
//them phan tu
void them(Queue &q,int x){
	node *temp=new node;
	temp ->data=x;
	temp ->link=q.dau;
	q.dau=temp;
}
//xoa phan tu
void xoacuoi(Queue &q, int &x){
	node *p=q.dau;
	node *t=q.cuoi;
	while (T->link!=q.cuoi){
		t=t->link;
	}
	q.dau=t;
	x=p->data;
	delete(p);
}
