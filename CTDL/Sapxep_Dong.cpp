#include<iostream>
using namespace std;

typedef struct A
{
	int soluong;
	int *array;
} Dong;

void init(Dong &d, int max = 10001)
{
	d.soluong = 0;
	d.array = new int[max];
}

void push(Dong &d, int x)
{
	d.soluong++;
	int i = d.soluong;
	d.array[i] = x;
	while(d.array[i/2] < d.array[i] && i/2 > 0)
	{
		swap(d.array[i/2], d.array[i]);
		i = i / 2;
	}
}

void pop(Dong &d)
{
	int i = 1;
	d.array[i] = d.array[d.soluong];
	d.soluong--;
	while(i*2 <= d.soluong || i*2+1 <= d.soluong)
	{
		if(d.array[i] > d.array[2*i] && d.array[i] > d.array[2*i+1])
			break;
		if(d.array[2*i] > d.array[2*i+1])
		{
			swap(d.array[i], d.array[2*i]);
			i = 2*i;
		}
		else
		{
			swap(d.array[i], d.array[2*i+1]);
			i = 2*i+1;
		}
	}
}

void print(Dong d)
{
	cout << "Dong:";
	for(int i = 1; i <= d.soluong; i++)
		cout << " " << d.array[i];
	cout << endl;
}

int main()
{
	Dong d;
	int a[] = {37, 30, 25, 29, 21, 18};
	init(d);
	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
		push(d, a[i]);
	print(d);
	pop(d);
	print(d);
	pop(d);
	print(d);
	pop(d);
	print(d);

	return 0;
} 
