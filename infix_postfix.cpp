#include<iostream>
#include<cstdlib>
#define size 30
using namespace std;
struct stack
{
	int top;
	char *s;
}st;
class stack1
{
public:
	stack1()
	{
		st.top = -1;
		st.s = new char[size];
	}
	void push(char a)
	{
		if (st.top == (size - 1))
		   cout << "stack is full";
		else
			st.s[++st.top]=a;
	}
	char pop()
	{
		if (st.top == -1)
			cout << "stack is empty";
		else
			return(st.s[st.top--]);
	}
	char peak()
	{
		if (st.top == -1)
			cout << "stack is empty";
		else
			return(st.s[st.top]);
	}
	int precedence(char ch1)
	{
		if (ch1 == '*' || ch1 == '/')
			return 3;
		else if (ch1 == '+' || ch1 == '-')
			return 2;
		else
			return 1;
	}
};
int main()
{
	stack1 st1;
	char c[30], ch;
	int i = 0;
	cin >> c;
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
		{
				
			if (st1.precedence(c[i]) <= st1.precedence(st1.peak()))
			{
				while(st1.precedence(c[i]) <= st1.precedence(st1.peak()))
					cout << st1.pop(); 
					st1.push(c[i]);
			st1.push(c[i]);
		}
		else if (c[i] == '(' || c[i] == '{' || c[i] == '[' || c[i] == ')' || c[i] == ']' || c[i] == '}')
			st1.push(c[i]);
		else
			cout << c[i];
	}
	system("pause");
}