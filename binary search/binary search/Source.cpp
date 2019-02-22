#include<iostream>
#include<cstdlib>
void binary_search(int);
using namespace std;
int n,low=0,high=0;
int *a,ele;
void get_data()
{
	cout << "enter number of elements : " ;
	cin >> n;
	a = new int[n];
	cout << "enter integer elements" << endl;
	for(high=0;high<n;high++)
	cin >> a[high];
	cout << "enter element to be searched : ";
	cin >> ele;
	high = n-1;
	binary_search(ele);
}
void  binary_search(int ele)
{
	cout <<" HERE" << endl;
	
	
	while (low <=high)
	{
		int mid = (low + high) / 2;
		cout << " HERE 2 " << endl;
		if (ele > a[mid])
			low = mid + 1;
		else if (ele < a[mid])
			high = mid - 1;
		else {
			cout << "element found at location" << mid << endl;
			break;
		}
	}
	if (low > high)
		cout << "element not found";
}
int main()
{
	get_data();
	system("pause");
}