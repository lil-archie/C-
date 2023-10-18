#define  _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"


void  test_queue()
{
	myContainer::queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(4);
	q1.push(5);
	q1.push(6);
	q1.push(7);


	while (!q1.empty())
	{
		cout << q1.front() << endl;
		q1.pop();
	}
	cout << endl;


}

void test_stack()
{
	myContainer::stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);


	while (!s1.empty())
	{
		cout << s1.back() << endl;
		s1.pop();
	}
	cout << endl;

}


int main()
{
	test_queue();
	test_stack();
	return 0;
}