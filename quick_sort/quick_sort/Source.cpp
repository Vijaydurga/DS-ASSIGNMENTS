#include<iostream>
#include<cstdlib>
using namespace std;
class quick
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
		quick_sort(0, n);
	}
	void swap(int &x, int &y)
	{
		int temp;
		temp = x;
		x = y;
		y = temp;
	}
	void quick_sort(int low, int high)
	{
		int pivot = a[low];
		int i, j;
		i = low + 1; j = high;
		if (low < high)
		{
			while (1)
			{
				while (i <= high && a[i] < pivot)
					i++;
				while (j >= 0 && a[j] > pivot)
					j--;
				if (i < j)
					swap(a[i], a[j]);
				else
					break;
			}
			swap(a[low], a[j]);
			quick_sort(low, j - 1);
			quick_sort(j + 1, high);
		}
	}
	void display()
	{
		for (int i = 1; i <= n; i++)
			cout << a[i] << " ";
	}
};
int main()
{
	quick q;
	q.get_data();
	q.display();
	system("pause");
}