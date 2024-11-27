#include<iostream>
using namespace std;
typedef struct a{
	int Data;
	a *link;
}Node ;
struct  List{
	a*head;
};;
//1.khoi tao
void khoitao(List &l){
	l.head=NULL;
}
//2.huy bo danh sach
void huyboList(List &l) {
if(l.head!=NULL){
	while (l.head != NULL) {
		Node* temp = l.head;
		l.head = l.head->link;
		delete temp;
		}
	}
}
//3.dem so phan tu trong danh sach
int dem(List &l)
{
 	int count = 0;
	Node* temp = l.head;
	while (temp != NULL) {
	count++;
	temp = temp->link;
}
	return count;
}
//4.Them dau
void themdau(List &l,int x){
	Node *temp=new Node;
	temp ->Data=x;
	temp ->link=l.head;
	l.head=temp;
}
//5.them cuoi
void themcuoi(List &l, int x){
	Node *temp=new Node;
	temp->Data=x;
	Node *ptr=l.head;
	while(ptr->link!=NULL){
		ptr=ptr->link;
	}
	ptr->link=temp;
	temp->link=NULL;
	}
//6.Them phan tu co noi dung x vao sau phan tu co dia chi la p trong danh sach
void themptu(List &l, Node* p, int x) {
    if (p == NULL) {
        cout << "Phan tu P khong ton tai trong danh sach" << std::endl;
        return;
    }

    Node* newNode = new Node;
    newNode->Data = x;
    newNode->link = p->link;
    p->link = newNode;
}
//7.xoa phan tu tai vi tri co dia chi la p trong danh sach
void xoa(List &l, Node* p) {
    if (l.head == NULL || p == NULL) {
        return;
    }

    if (l.head == p) {
        l.head = p->link;
        delete p;
        return;
    }

    Node* b = l.head;
    while (b->link != NULL && b->link != p) {
        b = b->link;
    }

    if (b->link == p) {
        b->link = p->link;
        delete p;
    }
}
//8.kiem tra xem co ton tai hay khong phan tu co noi dung x trong danh sach
bool kiemtra(List &l,int x){
	Node *ptr=l.head;
	while(ptr!=NULL){
		if(ptr->Data==x){
			return true;
		}
		ptr=ptr->link;
	}
	return false;
}
//in
void in(List &l){
	while(l.head!=NULL){
		cout<<l.head->Data<<" ";
		l.head=l.head->link;
	}
	
}
int main(){
	List l;
	khoitao(l);
    themdau(l, 3);
    themdau(l, 2);
    themdau(l, 1);
    themcuoi(l, 4);
    cout << "So phan tu cua danh sach: " <<dem(l) <<endl;
//them
    Node* p = l.head->link;
	int k;
	cout<<"Nhap k:";cin>>k;
	cout << "Danh sach sau khi them phan tu "<<k<<" vao sau P: ";
	themptu(l,p,k);
    in(l);
//xoa
    xoa(l,p);
    cout << "\nDanh sach sau khi xoa phan tu tai P: "<<endl;
    in(l);
//kiem tra
    int x ; 
    cout<<"Nhap x:";cin>>x;
    if (kiemtra(l, x)) {
        cout << "Phan tu " << x << " ton tai trong danh sach" <<endl;
    }
	else {
    	cout << "Phan tu " << x << " khong ton tai trong danh sach" <<endl;
    }	
	return 0;
}
