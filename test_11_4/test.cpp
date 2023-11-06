#define  _CRT_SECURE_NO_WARNINGS 1
#include"PriorityQueue.h"
#include"test.h"

int main()
{
	
	
		/*myqueue::queue<int> q1;
		q1.push(1);
		q1.push(1);
		q1.push(1);
		q1.push(1);
		q1.push(1);

		while (!q1.empty())
		{
			cout << q1.front() << endl;
			q1.pop();
		}
		cout << endl;
	*/

	/*myPriorityQueue::Priority_queue<int> q1;
	q1.push(1);
	q1.push(2);*/
	/*list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	cout << l[0] << endl;*/


	myPriorityQueue::Priority_queue<int> q1;
	q1.push(189);
	q1.push(25);
	q1.push(355);
	q1.push(4);

	while (!q1.empty())
	{
		cout << q1.top() << endl;
		q1.pop();
	}
	cout << endl;


	return 0;
}