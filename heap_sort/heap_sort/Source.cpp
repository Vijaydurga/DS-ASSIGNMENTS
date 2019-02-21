#include<iostream>
#include<cstdlib>
using namespace std;
class heap
{
	int *a;
	int n;
public:
	void get_data()
	{
		cout << "enter no. of elemets";
		cin >> n;
		a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
	}
	void heap_sort()
	{
		for (int i = (n / 2 - 1); i >= 0; i--)
			build_heap(i, n);
		for (int j = 1; j <= n - 1; j++)
			{
				swap(a[0], a[n - j]);
				build_heap(0, n - j);
			}
	}
	void build_heap(int i, int n)
	{
		int temp = a[i], c;
		for ( ; 2 * i + 1; i = c)
		{
			c = 2 * i + 1;
			if (c + 1 < n && a[c + 1] > a[c])
				c++;
			if (a[c] > temp)
				a[i] = a[c];
			else
				break;
		}
		a[i] = temp;
	}
	void swap(int &x, int &y)
	{
		int temp;
		temp = x;
		x = y;
		y = temp;
	}
	void display()
	{
		for (int i =0 ; i < n; i++)
			cout << a[i] << " ";
	}
};
int main()
{
	heap h;
	h.get_data();
	h.heap_sort();
	h.display();
	system("pause");
}