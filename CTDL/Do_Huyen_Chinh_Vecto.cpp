
// Thuc hanh Vector 

#include <iostream>

using namespace std;

typedef int T;

struct Vector {
    int size;
    int capacity;
    T * array;
};

// Khoi tao vector
void vecInit(Vector & vec, int initCapacity = 16);

// Huy vector
void vecDestroy(Vector & vec);

// Sao chep vector
void vecCopy(Vector & vec2, Vector & vec);

// Lay kich thuoc vector
int  vecGetSize(Vector & vec);

// Lay dung luong vector
int vecGetCapacity(Vector & vec);

// Kiem tra vector rong
bool vecIsEmpty(Vector & vec);

// Lay phan tu
T vecGetElem(Vector & vec, int index);

// Cap nhat phan tu
void vecSetElem(Vector & vec, int index, T newValue);

// Tang dung luong vector
void vecExpand(Vector & vec, int newCapacity);

// Cat bo dung luong du thua cua vector
void TrunCate(Vector & vec);

// Chen vao cuoi vector
void vecPushBack(Vector & vec, T newElement);

// Chen vao giua vector
void vecInsert(Vector & vec, int pos, T newElement);

// Xoa phan tu cuoi vector
void vecPopBack(Vector & vec);

// Xoa tat ca cac phan tu
void vecClear(Vector & vec);

// Xoa phan tu o giua vector
void vecErase(Vector & vec, int pos);

// In cac phan tu cua vector len man hinh
void output(Vector & vec);

// Tim kiem tuan tu tren vector
int LinearSearch(Vector & vec, int x);

// Sap xep theo thu tu tang dan
void IncreaseSort(Vector & vec);

// Tim kiem nhi phan tren vector
int BinarySearch(Vector & vec, int y); 

// Xoa cac phan tu tu vi tri pos1 den pos2
void DeleteP1toP2(Vector & vec, int pos1, int pos2);

int main()
{
	// Khai bao bien vector
	Vector vec;	

	// Khoi tao vector
	vecInit(vec);

	// Chen mot so phan tu vao cuoi vector
	vecPushBack(vec, 4); // 4
	vecPushBack(vec, 8); // 4 8
	vecPushBack(vec, 3); // 4 8 3
	vecPushBack(vec, 9); // 4 8 3 9
	vecPushBack(vec, 5); // 4 8 3 9 5
	
	// YEU CAU THUC HANH
	//   Viet code goi cac ham da viet de lam cac viec sau:
	//     1. In dung luong cua vector len man hinh
    //     2. Cat bo phan dung luong du thua cua vector
    //     3. In kich thuoc va dung luong cua vector xem co bang nhau hay khong
    //     4. In tat ca cac phan tu cua vector len man hinh
    //     5. Tim kiem tuan tu tren vector
    //     6. Tim kiem nhi phan tren vector (hay tao mot vector khac
	//        chua cac phan tu sap xep tang dan)
	//     7. Xoa cac phan tu nam o cac vi tri tu pos1 den pos2 tren vector
	
	// VIET CODE CUA BAN O DAY...
    // 1
	cout<<"1.Dung luong cua vector la: "<<vecGetCapacity(vec);

    // 2
    cout<<"\n2.Cat bo dung luong du thua cua vector";
    TrunCate(vec);

    // 3
    cout<<"\n3.\nKich thuoc vector: "<<vecGetSize(vec);
	cout<<"\nDung luong cua vector: "<<vecGetCapacity(vec);

    // 4
    cout<<"\n4.In cac phan tu cua vector:"; output(vec);

    // 5
    cout<<"\n5.Tim kiem tuan tu tren vector";
    T x;
    cout<<"\nNhap phan tu can tim kiem tuan tu: "; cin>>x;
    int pos = LinearSearch(vec, x);
    if (pos == -1) cout<<"Khong tim thay phan tu can tim kiem";
    else cout<<"Tim thay phan tu can tim kiem tai vi tri: "<<pos;

    // 6
    cout<<"\n6.Tao mot vector khac va tim kiem nhi phan:";
    Vector vec2;
    vecCopy(vec2, vec);
    int y;
    IncreaseSort(vec2);
    cout<<"\nTao vector 2 va sap xep cac phan tu theo thu tu tang dan:"; 
	output(vec2);
    cout<<"\nNhap phan tu can tim kiem nhi phan: "; cin>>y;
    int p = BinarySearch(vec2, y);
    if(p == -1) cout<<"Khong tim thay phan tu can tim kiem";
    else cout<<"Tim thay phan tu can tim kiem tai vi tri: "<<p;

    // 7
    cout<<"\n7.Xoa cac phan tu nam o cac vi tri tu pos1 den pos2 tren vector 2";
    int pos1, pos2;
    cout<<"\nNhap pos 1: "; cin>>pos1;
    cout<<"Nhap pos 2: "; cin>>pos2;
    DeleteP1toP2(vec2, pos1, pos2);
    cout<<"In cac phan tu cua vector sau khi xoa:";
    output(vec2);
    
	// Huy vector
	vecDestroy(vec);
	
	return 0;
}

void vecInit(Vector & vec, int initCapacity) {
    vec.size = 0;
    vec.capacity = initCapacity;
    vec.array = new T[vec.capacity];
}

void vecDestroy(Vector & vec) {
    delete[] vec.array;
}

void vecCopy(Vector & vec2, Vector & vec) {
    if (&vec2 != &vec) {
        vec2.size = vec.size;
        vec2.capacity = vec.capacity;
        // delete[] vec2.array;
        vec2.array = new T[vec2.capacity];
    
        for (int i = 0; i < vec2.size; i++)
            vec2.array[i] = vec.array[i];
    }
}

int vecGetSize(Vector & vec) {
    return vec.size;
}

bool vecIsEmpty(Vector & vec) {
    return (vec.size == 0);
}

T vecGetElem(Vector & vec, int index) {
    return vec.array[index];
}

void vecSetElem(Vector & vec, int index, T newValue) {
    vec.array[index] = newValue;
}

void vecExpand(Vector & vec, int newCapacity) { 
    if (newCapacity <= vec.size)
        return;
    
    T * old = vec.array;
    vec.array = new T[newCapacity];
    for (int i = 0; i < vec.size; i++)
        vec.array[i] = old[i];
    
    delete[] old;
    
    vec.capacity = newCapacity;
}

void vecPushBack(Vector & vec, T newElement) {
    if (vec.size == vec.capacity)
        vecExpand(vec, 2 * vec.capacity);
    
    vec.array[vec.size] = newElement;

    vec.size++;
}

void vecInsert(Vector & vec, int pos, T newElement) {
    if (vec.size == vec.capacity)
        vecExpand(vec, 2 * vec.capacity);

    for (int i = vec.size; i > pos; i--)
        vec.array[i] = vec.array[i - 1];

    vec.array[pos] = newElement;

    vec.size++;
}

void vecPopBack(Vector & vec) {
    vec.size--;
}

void vecClear(Vector & vec) {
    vec.size = 0;
}

void vecErase(Vector & vec, int pos) {
    for (int i = pos; i < vec.size - 1; i++)
        vec.array[i] = vec.array[i + 1];

    vec.size--;
}

// YEU CAU THUC HANH
//   Dinh nghia cac ham thuc hien cac viec sau:
//     1. Lay dung luong cua vector
//     2. Cat bo phan dung luong du thua cua vector
//     3. In tat ca cac phan tu cua vector len man hinh
//     4. Tim kiem tuan tu tren vector
//     5. Tim kiem nhi phan tren vector (gia su vector da sap xep tang dan)
//     6. Xoa cac phan tu nam o cac vi tri tu pos1 den pos2 tren vector

// VIET CODE CUA BAN O DAY...

void output(Vector & vec) {
    for (int i = 0; i < vec.size; i++) {
        cout<< " " << vec.array[i] ;
    }
}

int vecGetCapacity(Vector & vec) {
    return vec.capacity;
}

void TrunCate(Vector & vec) {
    T * old = vec.array;
    vec.array = new T[vec.size];
    for (int i = 0; i < vec.size; i++)
        vec.array[i] = old[i];
    
    delete[] old;
    
    vec.capacity = vec.size;
}

int LinearSearch(Vector & vec, T x) {
    for (int i = 0; i < vec.size; i++) {
        if (vec.array[i] == x) return i;
    }
    return -1;
}

void IncreaseSort(Vector & vec) {
    for (int i = 0; i < vec.size - 1; i++) {
        for (int j = i + 1; j < vec.size; j++) {
            if (vec.array[i] > vec.array[j]) {
                T temp = vec.array[i];
                vec.array[i] = vec.array[j];
                vec.array[j] = temp;
            }
        }
    }
}

int BinarySearch(Vector & vec, T x) {
    int l= 0, r = vec.size - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (vec.array[mid] == x) return mid;
        else if (vec.array[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

void DeleteP1toP2(Vector & vec, int pos1, int pos2) {
    for (int i = pos2; i >= pos1; i--) {
        vecErase(vec, i);
    }
}
