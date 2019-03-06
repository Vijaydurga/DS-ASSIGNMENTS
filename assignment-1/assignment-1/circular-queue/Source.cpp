#include <iostream>



using namespace std;



struct _CQ_ {

	int rear;

	int front;

	int *s;

	int size;

}q;



class CQ {

	struct  _CQ_ q;

public:

	CQ();

	void insert(int);

	void deque();

	void display();

	void getsize(int);



};



CQ::CQ() {

	q.rear = -1;

	q.front = -1;

	q.s = NULL;

}



void CQ::getsize(int n) {

	q.size = n;

	q.s = new int[n];

}



void CQ::insert(int val) {

	if ((q.front == 0 && q.rear == q.size - 1) || (q.front == q.rear + 1))

	{

		cout << "Queue Overflow \n";

	}

	else {

		if (q.front == -1)

		{

			q.front = 0;

			q.rear = 0;

		}

		else

		{

			if (q.rear == q.size - 1)

				q.rear = 0;

			else

				q.rear = q.rear + 1;

		}

		cout << "insert element:" << endl;

		q.s[q.rear] = val;

	}

}

void CQ::deque() {

	if (q.front == -1)

	{

		cout << "Queue Underflow\n";

	}

	cout << "Element deleted from queue is : " << q.s[q.front] << endl;

	if (q.front == q.rear)

	{

		q.front = -1;

		q.rear = -1;

	}

	else

	{

		if (q.front == q.size - 1)

			q.front = 0;

		else

			q.front = q.front + 1;

	}

}

void CQ::display() {

	int front_pos = q.front, rear_pos = q.rear;

	if (q.front == -1)

	{

		cout << "Queue is empty\n";

		return;

	}

	cout << "Queue elements :\n";

	if (front_pos <= rear_pos)

	{

		while (front_pos <= rear_pos)

		{

			cout << q.s[front_pos] << "  ";

			front_pos++;

		}

	}

	else

	{

		while (front_pos <= q.size - 1)

		{

			cout << q.s[front_pos] << "  ";

			front_pos++;

		}

		front_pos = 0;

		while (front_pos <= rear_pos)

		{

			cout << q.s[front_pos] << "  ";

			front_pos++;

		}

	}

	cout << endl;

}

void main() {

	CQ c;

	int n;

	cin >> n;

	c.getsize(n);

	c.insert(3);

	c.insert(2);

	c.insert(6);

	c.display();

	c.deque();

	c.insert(4);

	c.insert(5);

	c.display();

	system("pause");

}