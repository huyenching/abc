// Thuc h�nh bang bam
// Viet chuong tr�nh tu dien Anh-Viet don gian dua tr�n bang bam tham d� tuyen t�nh. Moi muc tu trong tu dien gom tu tieng Anh (kh�a) v� nghia tieng Viet (gi� tri).
// Y�u cau: Ho�n thien chuong tr�nh C++ d� cho b�n duoi (dien c�c c�u lenh C++ v�o nhung cho ba cham).
// Y�u cau bo sung:
// Viet h�m tra ve so muc tu hien c� trong tu dien.
// Viet h�m cap nhat nghia tieng Viet cua mot tu tieng Anh dang c� trong tu dien.
// Viet h�m x�a mot muc tu dang c� trong tu dien.
// Cai tien de c� kiem tra tr�ng lap tu tieng Anh khi ch�n muc tu moi v�o tu dien (neu truoc d� chua l�m).
// Cai tien de kh�ng ph�n biet chu hoa chu thuong doi voi c�c tu tieng Anh (neu truoc d� chua l�m).
#include <iostream>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

// Muc tu trong tu dien
struct MucTu
{
   string tuTiengAnh;
   string nghiaTiengViet;
};

struct TuDien
{
   MucTu *table;  // Con tro toi bang bam
   int tableSize; // Kich thuoc bang bam, so phan tu
   bool *trong;   // Neu trong[i] == true thi vi tri i trong bang bam dang trong
};

// Ham bam anh xa tu tieng Anh sang mot vi tri trong bang bam:
//   1. Cong cac ky tu
//   2. Chia cho kich thuoc bang bam va lay phan du
int hamBam(string tuTiengAnh, int tableSize)
{
   int hashVal = 0;
   for (int i = 0; i < tuTiengAnh.size(); i++)
      hashVal += tuTiengAnh[i];

   return hashVal % tableSize;
}

// Ham khoi tao tu dien
void KhoiTaoTD(TuDien &td, int size = 101)
{ // Kich thuoc bang bam ngam dinh la 101
   td.tableSize = size;
   td.table = new MucTu[size];
   td.trong = new bool[size];
   for (int i = 0; i < size; i++)
      td.trong[i] = true;
}

// Ham huy tu dien
void huyTD(TuDien &td)
{
   delete[] td.table;
   delete[] td.trong;
}

// Chen muc tu vao tu dien
void chenMucTu(TuDien &td, MucTu mt)
{
   int hashVal = hamBam(mt.tuTiengAnh, td.tableSize);
   while (td.trong[hashVal]==false)
      hashVal = (hashVal + 1) % td.tableSize;
   td.table[hashVal] = mt;
   td.trong[hashVal] = false;
}

// Lay nghia tieng Viet
string nghiaTiengViet(TuDien &td, string tuTiengAnh)
{
   int hashVal = hamBam(tuTiengAnh, td.tableSize);
   while (td.trong[hashVal]==false && td.table[hashVal].tuTiengAnh != tuTiengAnh)
      hashVal = (hashVal + 1) % td.tableSize;
   if (td.trong[hashVal]==false)
      return td.table[hashVal].nghiaTiengViet;
}

// Ham tra ve so muc tu trong tu dien
int CountMT(TuDien &td)
{
   int count = 0;
   for (int i = 0; i < td.tableSize; i++)
      if (td.trong[i]==false)
         count++;
   return count;
}

// Ham cap nhat nghia tieng Viet cua mot tu tieng Anh
void CapNhatNghia(TuDien &td, string tuTiengAnh, string nghiaTiengViet)
{
   int hashVal = hamBam(tuTiengAnh, td.tableSize);
   while (td.trong[hashVal]==false && td.table[hashVal].tuTiengAnh != tuTiengAnh)
      hashVal = (hashVal + 1) % td.tableSize;
   if (td.trong[hashVal]==false)
      td.table[hashVal].nghiaTiengViet = nghiaTiengViet;
}

// Ham kiem tra trung lap tu tieng Anh khi chen muc tu moi vao tu dien
bool CheckTrungLap(TuDien &td, string tuTiengAnh)
{
   int hashVal = hamBam(tuTiengAnh, td.tableSize);
   while (td.trong[hashVal]==false && td.table[hashVal].tuTiengAnh != tuTiengAnh)
      hashVal = (hashVal + 1) % td.tableSize;
   if (td.trong[hashVal])
      return true;
   else
      return false;
}

// Ham xoa muc tu khoi tu dien
void XoaMucTu(TuDien &td, string tuTiengAnh)
{
   int hashVal = hamBam(tuTiengAnh, td.tableSize);
   while (td.trong[hashVal]==false && td.table[hashVal].tuTiengAnh != tuTiengAnh)
      hashVal = (hashVal + 1) % td.tableSize;
   if (td.trong[hashVal]==false)
      td.trong[hashVal] = true;
}

// Ham in ra tu dien
void InRaTuDien(TuDien &td)
{
   for (int i = 0; i < td.tableSize; i++)
      if (td.trong[i]==false)
         cout << td.table[i].tuTiengAnh << ": " << td.table[i].nghiaTiengViet << endl;
}

//Ham chuan hoa
string ChuanHoa(string &wordCH){
	for(int i=0; i<wordCH.size(); i++){
   			wordCH[i] = tolower(wordCH[i]);
	}
	return wordCH;
}

int main()
{
    TuDien td;
    KhoiTaoTD(td);
	
    // Tao mot vai muc tu
    MucTu mt1, mt2, mt3;
    mt1.tuTiengAnh     = "computer";
    mt1.nghiaTiengViet = "may tinh";
    mt2.tuTiengAnh     = "memory";
    mt2.nghiaTiengViet = "bo nho";
    mt3.tuTiengAnh     = "hard disk";
    mt3.nghiaTiengViet = "dia cung";
	
    // Chen cac muc tu vao tu dien
    chenMucTu(td, mt1);
    chenMucTu(td, mt2);
    chenMucTu(td, mt3);

    string tuTA, nghiaTV;

    // Yeu cau nhap tu tieng Anh de tra cuu tu dien
    cout << "Nhap tu tieng Anh: ";
    getline(cin, tuTA);
	
    // Tim nghia tieng Viet
    nghiaTV = nghiaTiengViet(td, tuTA);
	
    // In ket qua tra cuu
    if (nghiaTV == "")		
        cout << "Tu vua nhap khong co trong tu dien" << endl;
    else		
        cout << "Nghia cua tu vua nhap la: " << nghiaTV << endl;
	
    huyTD(td);

    return 0;
}

