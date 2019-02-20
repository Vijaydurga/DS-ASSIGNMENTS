#include<iostream>
#include<cstdlib>
using namespace std;
class selection
{
	int *a;
	int n;
public:
	void get_data()
	{
		cout << "enter no. of elements";
		cin >> n;
		a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
	}
	void selection_sort()
	{
		for (int i = 0; i < n; i++)
		{
			int loc = i, j = i + 1;
			while (j <= n - 1)
			{
				if (a[j] < a[loc])
					loc = j;
				j++;
			}
			swap(a[i], a[loc]);
		}
	}
		void swap(int &x,int &y)
			{
			int temp;
			temp = x;
			x = y;
			y = temp;
		}
	void display()
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
	}
};
int main()
{
	selection s;
	s.get_data();
	s.selection_sort();
	s.display();
	system("pause");
}