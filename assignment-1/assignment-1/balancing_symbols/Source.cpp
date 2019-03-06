#include<iostream>

#include<cstdlib>

#define size 30

using namespace std;

struct stack
{
	int top;
    char *s;
};
class stack1
{
   struct stack st;
public:
  stack1()
  {
	  st.top = -1;
      st.s = new char[size];
  }
  bool isfull()
  {
	  if (st.top == (size - 1))
          return true;
	  return false;
  }
  bool isempty()
  {
	return(st.top == -1);
  }
  char pop()
  {
	  char x = -999;
       if (!isempty())
          x = st.s[st.top--];
      else
	    cout << "stack is empty" << endl;
    return(x);
  }
  char peak()
  {
   char x = -999;
   if (!isempty())
     x = st.s[st.top];
   else
    cout << "stack is empty" << endl;
   return(x);
  }
  void push(char a)
  {
	  if (isfull())
		  cout << "stack is full" << endl;
	  else
		  st.s[++st.top] = a;
  }
	~stack1()
	{
		delete st.s;
	}

};
int main()

{
	stack1 st;
	char x[10], ch, ch1;
	int i = 0, flag = 0;
	cout << "enter symbols : " << endl;
		cin >> x;
    for (i = 0; x[i] != '\0'; i++)
    {
     ch = x[i];
	 switch (ch)

	 {

	 case '(':

	 case '[':

	 case '{': st.push(ch);

		 break;

	 case ')':

	 case ']':

	 case '}': {

		 ch1 = st.peak();

		 if ((ch1 == '(' && ch == ')') || (ch1 == '{'&& ch == '}') || (ch1 == '['&& ch == ']'))

			 st.pop();

		 else
			 flag = 1;
	 }

	 default:break;
	 }
        if (flag == 1)
     	{
           cout << "unbalanced string" << endl;
          	break;
        }
     	
	
}

	if (flag == 0)

		cout << "string is balanced" << endl;

	system("pause");
}