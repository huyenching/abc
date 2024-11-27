#include<iostream>
using namespace std;
typedef struct a{
	int Data;
	a*left,*right;
}Node;
typedef Node*TREE;
void khoitao(TREE &t){
	t=NULL;
}
/*
TREE khoitao(){
	TREE tree=NULL;
	return tree;
}*/
//kiem tra nut x co ton tai khong
bool kiemtra(TREE &t, int x){
	if (t == NULL)
		return NULL;
	
	if (x < t->Data)
		return kiemtra(t->left,x);
	else if (x > t->Data)
		return kiemtra(t->right,x);
	else
		return t;
}
//them nut vao cay
void themnut(TREE &t, int x){
	t=new Node;
	t->Data=x;
	t->left=NULL;
	t->right=NULL;
}
void thempt(TREE &t,int x){
	if(t==NULL){
		themnut(t,x);
	}
	else if(x<t->Data){
		thempt(t->left,x);
	}
	else if(x>t->Data){
		thempt(t->right,x);
	}
}

//xoa nut tren cay
void xoacay(Node * & t)
{
	if (t != NULL) {          // Cay khong rong thi thuc hien 
	xoacay(t->left);  		// Xoa rong cay con trai
	xoacay(t->right);		 // Xoa rong cay con phai
	delete t;			     // Xoa nut goc
	t = NULL; }          	  // Khi cay rong thi phai cho t bang NULL
}
//xay dung cay nhi phan
void xaycay(TREE &t, int *a, int n){
	for(int i=0;i<n;i++){
		thempt(t,a[i]);
	}
}
//duyet cay
void duyettruoc(Node *t){
	if(t!=NULL){
	cout<<t->Data<<" ";
	duyettruoc(t->left);
	duyettruoc(t->right);
}
}
void duyetgiua(Node*t){
	if(t!=NULL){
	duyetgiua(t->left);
	cout<<t->Data<<" ";
	duyetgiua(t->right);
}
	
}
void duyetsau(Node*t){
	if(t!=NULL){
	duyetsau(t->left);
	duyetsau(t->right);
	cout<<t->Data<<" ";
}
}

//viet hoan chinh cay nhi phan tim kiem 
//dinh nghia
//khoi tao
//tim kiem 
//them nut
//xoa toan bo cay
//ham main xay dung cay tim kiem tu day so da nhap

int main(){
	TREE t;
	khoitao(t);
	int n,*a,x;
	cout<<"Nhap so luong phan tu: ";cin>>n;
	a= new int[n];
	cout<<"\nNhap cac phan tu trong mang: \n";
	for(int i=0;i<n;i++){
		cout<<"A["<<i+1<<"] =";
		cin>>a[i];
	}
	xaycay(t,a,n);
	//7. duyet truoc, giua va sau
	cout<<"\n\nDuyet cay theo thu tu truoc:"<<endl;
	duyettruoc(t);
	cout<<"\nDuyet cay theo thu tu giua:"<<endl;
	duyetgiua(t);
	cout<<"\nDuyet cay theo thu tu sau:"<<endl;
	duyetsau(t);
	cout<<"\nNhap x can tim kiem: ";cin>>x;
	if(kiemtra(t,x)){
		cout<<"Ton tai!";
	}
	else{
		cout<<"Khong ton tai!";
	}
	return 0;
}
//nhan xet: hinh dang cay nhi phan tim kiem duoc co lien quan gi dem day so da nhap:
/*tra loi: hinh dang cay nhi phan co lien quan den viec dem day so da nhap bang cach 
duyet cay va luu tru gia tri cua moi nut vao mot danh sach hoac mang*/ 

 //xoa nut de thanh cay tim kiem 
//them con phai cua con phai, them trai cua cay con trai, them trai cua con phai , them phai cua con trai
