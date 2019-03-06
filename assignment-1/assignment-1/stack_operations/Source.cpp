#include<iostream>
#include<cstdlib>
using namespace std;

struct Stack
{
	int top;
	int *s;
	int size;
};

class stack1
{
	struct Stack st;
public:
	stack1()
	{
		st.top = -1;
		st.s = NULL;
		st.size = 0;
	}
	void get_size(int a)
	{
		st.size = a;
		st.s = new int[a];
	}

	bool isfull()
	{
		return(st.top == (st.size - 1));
	}
	bool isempty()
	{
		return(st.top == -1);
	}
	int pop()
	{
		int x = -999;
		if (!isempty())
			x = st.s[st.top--];
		else
		{
			cout << "stack is empty" << endl;
			return(x);
		}
	}
	void push(int a)
	{
		if (!isfull())
			st.s[++st.top] = a;
		else
			cout << "stack is full" << endl;
	}
	void display()
	{
		for (int i = 0; i <= st.top; i++)
			cout << st.s[i] << " ";
	}
	void dstack()
	{
		delete st.s;
	}
};
int main()
{
	stack1 st1;
	int x,ch,y;
	cout << "enter size of stack :"<<endl;
	cin >> x;
	st1.get_size(x);
	while (1)
	{
		cout << "enter your choice :" << "1.push" << endl << "2.pop" << endl << "3.display" << endl << "4.exit";
		cin >> ch;
		switch (ch)
		{
		case 1: cout << "enter element to be pushed : "<<endl;
			cin >> x;
			st1.push(x);
			break;
		case 2:y = st1.pop();
			cout << "poped element is " << x << endl;
			break;
		case 3: st1.display();
			break;
		case 4: break;
		}
		if(ch == 4)
			break;
	}
	system("pause");
}