 #include <iostream>
using namespace std;

struct dong{
	int soluong;
	int *arr;
};

void khoiTao(dong &d){
	d.soluong=0;
	d.arr=new int[1000];
}

void them(dong &d,int x){
	int p=d.soluong+1;
	d.arr[p]=x;
	while(d.arr[p/2]>d.arr[p]){
		if(p!=1){int tmp=d.arr[p];
		d.arr[p]=d.arr[p/2];
		d.arr[p/2]=tmp;
		p=p/2;
		}
		else break;
	}
	d.soluong++;
}
	
void xoa(dong &d){
	int p=1;
	d.arr[p]=d.arr[d.soluong];
	d.soluong--;
	while(p*2<=d.soluong || p*2+1<=d.soluong){
	if(d.arr[2*p]>d.arr[p*2+1]){
		int tmp=d.arr[p];
		d.arr[p]=d.arr[2*p+1];
		d.arr[2*p+1]=tmp;
		p=2*p+1;
	}
	if(d.arr[p]<d.arr[2*p] && d.arr[p]<d.arr[2*p+1]){
		break;
	}
	else {
		int tmp=d.arr[p];
		d.arr[p]=d.arr[2*p];
		d.arr[2*p]=tmp;
		p=2*p;
	}
}
}
int main(){
	dong d;
	khoiTao(d);
	them(d,26);
	them(d,7);
	them(d,1);
	them(d,36);
	them(d,10);
	them(d,5);
	them(d,3);
	for(int i=1;i<d.soluong+1;i++){
		cout<<d.arr[i]<<" ";
	}
	xoa(d);
	xoa(d);
	cout<<endl;
	for(int i=1;i<d.soluong+1;i++){
		cout<<d.arr[i]<<" ";
	}
	return 0;
}
