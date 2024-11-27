 // Thuc hanh cay nhi phan tim kiem

#include <iostream>
#include <string>

using namespace std;

// Kieu cua cac nut tren cay (chua thong tin ve mot sinh vien).
struct Node
{
	int maSV;     // Ma sinh vien
	string hoTen; // Ho ten sinh vien
	Node * left;  // Con tro toi nut con trai
	Node * right; // Con tro toi nut con phai
};

// Cay nhi phan tim kiem (chua thong tin sinh vien)
struct SVTree
{
	Node * root; // Con tro toi nut goc cua cay
};

// Ham khoi tao cay (ban dau cay rong)
void treeInit(SVTree & tree);

// Ham huy (xoa het cac nut tren cay)
void treeDestroy(SVTree & tree);

// Kiem tra cay co rong hay khong
bool treeIsEmpty(SVTree & tree);

// Xoa het cac nut tren cay
void treeMakeEmpty(SVTree & tree);

// Xoa rong cay (t la goc cua cay)
void treeMakeEmpty(Node * & t);

// Chen mot sinh vien moi vao cay
void treeInsert(SVTree & tree, int maSV, string hoTen);

// Chen mot sinh vien moi vao cay (t la goc cua cay)
void treeInsert(int maSV, string hoTen, Node * & t);

// Tim sinh vien theo ma SV
Node * treeSearch(SVTree & tree, int maSV);

// Tim sinh vien theo ma SV (t la goc cua cay)
Node * treeSearch(int maSV, Node * t);

// YEU CAU THUC HANH
//   1. Khai bao cac ham duyet cay theo thu tu truoc, giua va sau
//   2. Khai bao cac ham dem so nut, so nut la va so nut co du 2 con

// VIET CODE CUA BAN O DAY
// ...
//1. khai bao cac ham duyet cay theo thu tu truoc, giua va sau
void duyettruoc (Node*t);
void duyetgiua (Node*t);
void duyetsau (Node *t);
//2. khai bao cac ham dem so nut, so nut la va so nut co du 2 con
int demnut(Node *t);
int demnutla(Node *t);
int demnut2con(Node *t);
int main()
{
	SVTree tree;
	treeInit(tree);
	Node*t;
	// YEU CAU THUC HANH
	//   1. Viet code chen chen 7-8 sinh vien vao cay
	//   2. Viet code tim sinh vien theo ma sinh vien:
	//       - Neu tim thay, in ho ten sinh vien len man hinh
	//       - Neu khong tim thay, thong bao khong tim duoc
	//   3. Viet code duyet cay theo thu tu truoc, giua va sau
	//   4. Viet code dem so nut, so nut la va so nut co du 2 con
	//   5. Viet code xoa rong cay
	//   6. Viet code kiem tra xem cay da rong hay chua
	
	// VIET CODE CUA BAN O DAY
	// ...
	//1. chen 7-8 sinh vien vao cay
	treeInsert(tree,2257,"Huyen Chinh");
	treeInsert(tree,2547,"Pham Ngoc");
	treeInsert(tree,2245,"Tien Dat");
	treeInsert(tree,1553,"Huyen Trang");
	treeInsert(tree,3522,"Phung Cuong");
	treeInsert(tree,2134,"Van Truong");
	treeInsert(tree,1724,"Dong Vu");
	cout<<"Da chen xong\n";
	//2. tim sinh vien theo ma sinh vien
	int MSV;
	cout<<"Nhap ma sinh vien can tim: "; cin>>MSV;
	if(treeSearch(MSV,tree.root)){
		cout<<"Da tim thay sinh vien co MSV "<<MSV;
		Node*sv=treeSearch(MSV,tree.root);
		cout<<"\nHo ten sinh vien co MSV "<<MSV<<": "<<sv->hoTen;
	}
	else 
		cout<<"Khong tim thay";
	//3. duyet truoc, giua va sau
	cout<<"\n\nDuyet cay theo thu tu truoc:"<<endl;
	duyettruoc(tree.root);
	cout<<"\nDuyet cay theo thu tu giua:"<<endl;
	duyetgiua(tree.root);
	cout<<"\nDuyet cay theo thu tu sau:"<<endl;
	duyetsau(tree.root);
	
	//4 Viet code dem so nut, so nut la va so nut co du 2 con
	cout<<"\n\nSo nut tren cay: "<<demnut(tree.root);
	cout <<"\nSo nut la tren cay: "<<demnutla(tree.root);
	cout<<"\nSo nut co du 2 con: "<<demnut2con(tree.root);
	//5. xoa rong cay
	treeMakeEmpty(tree);
	//6.Kiem tra cay da rong hay chua
	if(tree.root==NULL) cout<<"\n\nCay rong";
	else cout<<"\nCay chua rong"; 
	treeDestroy(tree);
	
	return 0;
}

void treeInit(SVTree & tree)
{
	tree.root = NULL;
}

void treeDestroy(SVTree & tree)
{
	treeMakeEmpty(tree);
}

bool treeIsEmpty(SVTree & tree)
{
	return (tree.root == NULL);
}

void treeMakeEmpty(SVTree & tree)
{
	treeMakeEmpty(tree.root);
}

void treeMakeEmpty(Node * & t)
{
	if (t == NULL)           // Cay da rong roi thi thoat ra
		return;
	
	treeMakeEmpty(t->left);  // Xoa rong cay con trai
	treeMakeEmpty(t->right); // Xoa rong cay con phai
	delete t;			     // Xoa nut goc
	t = NULL;                // Khi cay rong thi phai cho t bang NULL
}

void treeInsert(SVTree & tree, int maSV, string hoTen)
{
	treeInsert(maSV, hoTen, tree.root);
}

void treeInsert(int maSV, string hoTen, Node * & t)
{
	if (t == NULL) // Cay dang rong thi nut moi se thanh nut goc
	{
		t = new Node;
		t->maSV = maSV;
		t->hoTen = hoTen;
		t->left = NULL;
		t->right = NULL;
	}
	else if (maSV < t->maSV)
		treeInsert(maSV, hoTen, t->left);
	else if (maSV > t->maSV)
		treeInsert(maSV, hoTen, t->right);
	else
		; // Ma SV da ton tai, khong lam gi ca
}

Node * treeSearch(SVTree & tree, int maSV)
{
	return treeSearch(maSV, tree.root);
}

Node * treeSearch(int maSV, Node * t)
{
	if (t == NULL)
		return NULL;
	
	if (maSV < t->maSV)
		return treeSearch(maSV, t->left);
	else if (maSV > t->maSV)
		return treeSearch(maSV, t->right);
	else
		return t;
}

// YEU CAU THUC HANH
//   1. Dinh nghia cac ham duyet cay theo thu tu truoc, giua va sau
//   2. Dinh nghia cac ham dem so nut, so nut la va so nut co du 2 con

// VIET CODE CUA BAN O DAY
// ...
//duyet truoc
void duyettruoc(Node *t){
	if (t!=NULL){
		cout << t->hoTen << " MSV: "<< t->maSV<<endl;
		duyettruoc(t -> left);
		duyettruoc(t -> right);	
	}
}
//duyet giua
void duyetgiua(Node *t){
	if(t!=NULL){
		duyetgiua(t -> left);
		cout << t->hoTen << " MSV: "<< t->maSV<<endl;
		duyetgiua(t -> right);
	}
}
//duyet sau
void duyetsau(Node *t){
	if (t!=NULL){
		duyetsau(t -> left);
		duyetsau(t -> right);
		cout << t->hoTen << " MSV: "<< t->maSV<<endl;
	}
}
//dem nut
int demnut(Node*t){
	if(t==NULL)
		return 0;
	else
		return 1 + demnut(t->left)+ demnut(t->right);
}
bool kiemtranutla(Node*t){
	return (t->left==NULL)&&(t->right==NULL);
}
//nut la
int demnutla(Node*t){
	if(t==NULL) return 0;
	else
	{
		if(kiemtranutla(t))
			return 1;
		else
			return demnutla(t -> left) + demnutla(t -> right);
	}
}
//nut co du 2 la
int demnut2con(Node*t){
	if(t==NULL) return 0;
	int x= demnut2con(t->left), y=demnut2con(t->right);
	if ((t->left!=NULL)&&(t->right!=NULL)) return 1+x+y;
}
/*
void the(TREE &t, TREE &T){
	if(T->left !=NULL){
		the(t,T->left);
	}
	else {
		t->Data=T->Data;
		t=T;
		T=T->right;
	}
}
void xoa(TREE &t, int data){
	if(t==NULL){
		return ;
	}
	else{
		if(data<t->Data){
			xoa(t->left,data);
		}
		else if(data>t->Data){
			xoa(t->right,data);
		}
		else{
			Node *p=t;
			if(t->left==NULL){
				t=t->right;
			}
			else if(t->right==NULL){
				t=t->left;
			}
			else the(p,t->right);
		}
	}
}
