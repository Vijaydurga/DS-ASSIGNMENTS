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
			st.s[++st.top]= a;
		else
			cout << "stack is full"<<endl;
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
	int x;
	st1.get_size(6);
	st1.push(5);
	x = st1.pop();
	//st1.display();
	x = st1.pop();
	getchar();
}