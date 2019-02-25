#include<iostream>
#include<cstdlib>
using namespace std;
class merge
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
		merge_sort(0, n);
	}
	void merge_sort(int low, int high)
	{
		int mid;
		if (low < high)
		{
			mid = (low + high) / 2;
			merge_sort(low, mid);
			merge_sort(mid + 1, high);
			merge_(low, mid, high);
		}
	}
	void merge_(int l1s, int l1e, int l2e)
	{
		int l2s = l1e + 1;
		int *l3, i, j, k;
		l3 = new int[l2e - l1s + 1];
		i = l1s;
		j = l2s; k = 0;
		while (i <= l1e && j <= l2e)
		{
			if (a[i] > a[j])
				l3[k++] = a[j++];
			else
				l3[k++] = a[i++];
		}
		while (i <= l1e)
			l3[k++] = a[i++];
		while (j <= l2e)
			l3[k++] = a[j++];
		while (l2e >= l1s)
			a[l2e--] = l3[--k];
		delete l3;
	}
	void display()
	{
		for (int i = 1; i <= n; i++)
			cout << a[i] << " ";
	}
};
int main()
{
	merge m;
	m.get_data();

	m.display();
	system("pause");
}