#include <iostream>
#include <iomanip>   // De can chinh viec in an tren man hinh
#include <vector>
#include <string>
using namespace std;

// Dao gia tri cua hai bien x va y (dung trong sap xep chon va noi bot).
template <typename T>
void doiCho(T &x, T &y) {
	T tmp = x;
	x = y;
	y = tmp;
}

// Sap xep day xau a tang dan (dung sap xep chon hoac noi bot).
void sapXep(vector<string> &a) {
	for(int i = 0; i < a.size() - 1; i++){
		for(int j = 1 + i; j < a.size(); j++){
			if (a[i]<a[j]) doiCho(a[i], a[j]);
		}
	}
}
// Sap xep day xau b theo thu tu giam dan cua cac gia tri (so lan xuat
// hien) trong day f.
void sapXepGiam(vector<string> &b, vector<int> &f) {
	for(int i = 0; i < f.size() - 1; i++){
		for(int j = i + 1; j < f.size(); j++){
			if(f[i]<f[j]){
				doiCho(f[i], f[j]);
				doiCho(f[i], f[j]);
			}
		}
	}
}
int main()
{
// Khai bao cac vector a, b, f
    vector<string> a;
    vector<string> b;
    vector<int> f;
// Nhap so xau va cac xau tu ban phim
    int n; 
    string s;
    cout <<"Nhap n = "; cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
  		getline(cin, s);
  		a.push_back(s);
  	}
// Sap xep day xau a tang dan
    sapXep(a);
// Xay dung cac day b va f
    int dem = 0, vt = 0;
    for(int i = 0; i < a.size(); i++){
   		if(b.empty()){
   			b.push_back(a[i]);
	   		}
	   	if(a[i] != b[vt]){
	   		b.push_back(a[i]);
	   		f.push_back(dem);
	   		dem = 0;
	   		vt++;
       	}
       	dem++;
       	if(i == a.size() - 1){
       	 	b.push_back(a[i]);
       	 	f.push_back(dem);
	   	}
    }
// Sap xep day xau b theo thu tu giam dan cua cac gia tri trong day f
    sapXepGiam(b, f);
// In ket qua len man hinh
    cout << "Sap xep:\n";
    for(int i = f.size()-1; i >=0; i--){
   		cout << b[i] << " " <<f[i] << endl;
   	}
	return 0;
}
