#include <iostream>
#include <string>
#include <stack>

using namespace std;

void print_num(int a)
{
	if (a == 0)
	{
		cout << "000";
		return;
	}
	if (a < 10)
	{
		cout << "00" << a ;
		return;
	}
	if (a < 100)
	{
		cout << "0" << a ;
		return;
	}
	cout << a ;
	return;
}

int main()
{
	int a,b;
	stack<int> s;
	cin >> a >> b;
	int c;
	bool Pos = true;
	c = a + b;
	if (c < 0)
	{
		Pos = false;
		c = -c;
	}
	if (c == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	while (c>0)
	{
		int tmp;
		tmp = c % 1000;
		s.push(tmp);
		c = c / 1000;
	}
	if (Pos == false)
		cout << "-";

	if (s.size() == 1)
	{
		cout << s.top() << endl;
		return 0;
	}
	cout << s.top() << ",";
	s.pop();
	while (s.size()>1)
	{
		print_num(s.top());
		cout << ",";
		s.pop();
	}
	print_num(s.top());
	cout << endl;
	return 0;


}