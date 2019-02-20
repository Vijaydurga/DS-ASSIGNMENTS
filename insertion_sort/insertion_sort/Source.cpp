#include<iostream>
#include<cstdlib>
using namespace std;
class insertion
{
	int *a;
	int n;
public:
	void get_data()
	{
		cout << "enter no. of elements" << endl;
		cin >> n;
		a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
	}
	
	void insertion_sort()
	{
		int i , j ,temp;
		for (i = 1; i <= n-1; i++)
		{
			j = i - 1;
			temp = a[i];
			while (j >= 0 && a[j + 1] < a[j])
			{
				a[j + 1] = a[j];
				a[j] = temp;
				j--;
			}
		}
	}
	void display()
	{
		for (int i = 0; i < n ; i++)
			cout << a[i]<<" ";
	}
};
 int main()
{
	insertion i;
	i.get_data();
	i.insertion_sort();
	i.display();
	system("pause");

}