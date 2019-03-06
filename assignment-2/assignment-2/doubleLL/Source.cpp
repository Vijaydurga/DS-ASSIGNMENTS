#include<iostream>

#include<cstdlib>



using namespace std;



struct node

{

	int data;

	struct node *prev;

	struct node *next;

};



class _DLL_ {

	struct node *start;

public:

	_DLL_();

	void insert_first(int);

	void insert_last(int);

	void insert_after(int, int);

	void insert_before(int, int);

	int delete_first();

	int delete_last();

	void delete_specific(int);

	void travel_forward();

	void travel_backward();

	~_DLL_();

};



_DLL_::_DLL_() {

	start = NULL;

}



void _DLL_::insert_first(int ele) {

	struct node *temp;

	temp = new node;

	temp->data = ele;

	temp->prev = NULL;

	temp->next = start;

	if (start != NULL)

		start->prev = temp;

	start = temp;

}



void _DLL_::insert_last(int ele) {

	struct node *temp, *curr;

	temp = new node;

	temp->data = ele;

	temp->next = NULL;

	if (start == NULL)

	{

		temp->prev = NULL;

		start = temp;

	}

	else

	{

		curr = start;

		while (curr->next != NULL)

			curr = curr->next;

		temp->prev = curr;

		curr->next = temp;

	}

}



void _DLL_::insert_after(int sel, int ele)

{

	struct node *temp, *curr;

	if (start != NULL)

	{

		curr = start;

		while (curr->next != NULL && curr->data != sel)

			curr = curr->next;

		if (curr != NULL)

		{

			temp = new node;

			temp->data = ele;

			temp->prev = curr;

			temp->next = curr->next;

			if (curr->next != NULL)

				curr->next->prev = temp;

			curr->next = temp;

		}

		else

			cout << "element not found" << endl;

	}

	else

		cout << "list empty" << endl;

}



void _DLL_::insert_before(int sel, int ele)

{

	struct node *temp, *curr;

	if (start != NULL)

	{

		curr = start;

		while (curr->next != NULL && curr->data != sel)

			curr = curr->next;

		if (curr != NULL)

		{

			temp = new node;

			temp->data = ele;

			temp->prev = curr->prev;

			temp->next = curr;

			if (curr->prev != NULL)

				curr->prev->next = temp;

			else

				start = temp;

		}

		else

			cout << "element not found" << endl;

	}

	else

		cout << "list empty" << endl;

}



int _DLL_::delete_first()

{

	int x = -999;

	if (start != NULL)

	{

		struct node *temp;

		temp = start;

		if (temp->next != NULL)

			temp->next->prev = NULL;

		start = temp->next;

		x = temp->data;

		delete temp;

	}

	else

		cout << "list empty" << endl;

	return x;

}



int _DLL_::delete_last()

{

	int x = -999;

	struct node *curr, *temp;

	if (start != NULL)

	{

		curr = start;

		while (curr->next != NULL)

			curr = curr->next;

		x = curr->data;

		if (curr->prev != NULL)

			curr->prev->next = NULL;

		else

			start = NULL;

		delete curr;

	}

	else

		cout << "list empty" << endl;

	return x;

}



void _DLL_::delete_specific(int ele)

{

	struct node *curr, *temp;

	if (start != NULL)

	{

		curr = start;

		while (curr != NULL&&curr->data != ele)

			curr = curr->next;

		if (curr != NULL)

		{

			if (curr->prev != NULL)

				curr->prev->next = curr->next;

			else

				start = curr->next;

			if (curr->next != NULL)

				curr->next->prev = curr->prev;

			delete curr;

		}

		else

			cout << "element not found" << endl;

	}

	else

		cout << "list empty" << endl;

}



void _DLL_::travel_forward() {

	struct node *curr;

	if (start != NULL)

	{

		curr = start;

		while (curr != NULL)

		{

			cout << curr->data;

			curr = curr->next;

		}

	}

	else

		cout << "list empty" << endl;

}



void _DLL_::travel_backward() {

	struct node *curr;

	if (start != NULL)

	{

		curr = start;

		while (curr->next != NULL)

			curr = curr->next;

		while (curr != NULL)

		{

			cout << curr->data;

			curr = curr->prev;

		}

	}

	else

		cout << "list empty" << endl;

}





_DLL_::~_DLL_() {

	struct node *temp;

	while (start != NULL) {

		temp = start;

		start = temp->next;

		delete temp;

	}

}





void main()

{

	_DLL_ l1;

	cout << "insert elements:";

	l1.insert_first(1);

	l1.insert_after(1, 2);

	l1.insert_before(2, 3);

	l1.insert_last(4);

	cout << "print forward:" << endl;

	l1.travel_forward();

	cout << "print backward";

	l1.travel_backward();

	cout << "deleting elements:";

	l1.delete_last();

	cout << "print forward:" << endl;

	l1.travel_forward();

	system("pause");

}