#include<iostream>

#include<cstdlib>



using namespace std;



struct node

{

	int data;

	struct node *next;

};



class _list_ {

	struct node *start;

public:

	_list_();

	void insert_first(int);

	void insert_last(int);

	void insert_after(int, int);

	void insert_before(int, int);

	int delete_first();

	int delete_last();

	void delete_specific(int);

	void travel_forward();

	void travel_backward();

	void reverse();

	~_list_();



	friend void print(struct node *);

};



_list_::_list_() {

	start = NULL;

}



void _list_::insert_first(int ele) {

	struct node *temp;

	temp = new node;

	temp->data = ele;

	temp->next = start;

	start = temp;

}



void _list_::insert_last(int ele) {

	struct node *temp, *curr;

	temp = new node;

	temp->data = ele;

	temp->next = NULL;

	if (start != NULL)

	{

		curr = start;

		while (curr->next != NULL)

			curr = curr->next;

		curr->next = temp;

	}

	else

		start = temp;



}



void _list_::insert_after(int sel, int ele)

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

			temp->next = curr->next;

			curr->next = temp;

		}

		else

			cout << "element not found" << endl;

	}

	else

		cout << "list empty" << endl;

}



void _list_::insert_before(int sel, int ele)

{

	struct node *temp, *curr;

	if (start != NULL)

	{

		if (start->data == sel)

		{

			temp = new node;

			temp->data = ele;

			temp->next = start;

			start = temp;

		}

		else

		{

			curr = start;

			while (curr->next != NULL && curr->data != sel)

				curr = curr->next;

			if (curr != NULL)

			{

				temp = new node;

				temp->data = ele;

				temp->next = curr->next;

				curr->next = temp;

			}

			else

				cout << "element not found" << endl;

		}

	}

	else

		cout << "list empty" << endl;

}



int _list_::delete_first()

{

	int x = -999;

	if (start != NULL)

	{

		struct node *temp;

		temp = start;

		start = start->next;

		x = temp->data;

		delete temp;

	}

	else

		cout << "list empty" << endl;

	return x;

}



int _list_::delete_last()

{

	int x = -999;

	if (start != NULL)

	{

		if (start->next == NULL)

		{

			x = start->data;

			delete start;

			start = NULL;

		}

		else

		{

			struct node *curr;

			curr = start;

			while (curr->next->next != NULL)

				curr = curr->next;

			x = curr->next->data;

			delete curr->next;

			curr->next = NULL;

		}

	}

	else

		cout << "list empty" << endl;

	return x;

}



void _list_::delete_specific(int ele)

{

	struct node *curr, *temp;

	if (start != NULL)

	{

		if (start->data == ele)

		{

			temp = start;

			start = temp->next;

			delete temp;

		}

		else

		{



			curr = start;

			while (curr->next != NULL&&curr->next->data != ele)

				curr = curr->next;

			if (curr->next != NULL)

			{

				temp = curr->next;

				curr->next = temp->next;

				delete temp;

			}

			else

				cout << "element not found" << endl;

		}

	}

	else

		cout << "list empty" << endl;

}



void _list_::travel_forward() {

	struct node *curr;

	if (start != NULL)

	{

		curr = start;

		while (curr != NULL)

		{

			cout << curr->data << endl;

			curr = curr->next;

		}

	}

	else

		cout << "list empty" << endl;

}



void _list_::travel_backward() {

	if (start != NULL)

		print(start);

}



void print(struct node *curr) {

	if (curr != NULL)

	{

		print(curr->next);

		cout << curr->data << endl;

	}

}



void _list_::reverse() {

	struct node *rev = NULL, *temp;

	if (start != NULL)

	{

		if (start->next != NULL)

		{

			while (start != NULL)

			{

				temp = start;

				start = temp->next;

				temp->next = rev;

				rev = temp;

			}

			start = rev;

		}

	}

	else

		cout << "no reverse" << endl;

}



_list_::~_list_() {

	struct node *temp;

	while (start != NULL) {

		temp = start;

		start = temp->next;

		delete temp;

	}

}





void main()

{

	_list_ l1;

	l1.insert_first(1);

	l1.insert_after(1, 2);

	l1.insert_before(2, 3);

	l1.insert_last(4);

	l1.travel_forward();

	l1.travel_backward();

	l1.delete_last();

	l1.travel_forward();

	system("pause");

}