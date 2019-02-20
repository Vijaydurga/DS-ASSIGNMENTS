#include<iostream>
#include<cstdlib>

using namespace std;
class merge
{
	int *a;
	int n;
	int flag = 0;
public:
	void get_data()
	{
		cout << "enter no. of elements" << endl;
		cin >> n;
		a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
	}
	void merge_sort()
	{
		int i, j;
		for (i = 0; i < n - 1; i++)
		{
			flag = 0;
			for (j = 0; j < n - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					swap(a[j], a[j + 1]);
					flag = 1;
				}
			}
			if (flag == 0)
			{
				cout << "already sorted ";
				break;
			}
		}
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
		for (int i = 0; i < n; i++)
			cout << a[i] << endl;
	}
};
int main()
{
	merge m;
	m.get_data();
	m.merge_sort();
	m.display();
	system("pause");
}