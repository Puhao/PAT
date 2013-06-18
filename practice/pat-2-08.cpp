#include <iostream>
using namespace std;

unsigned int Calcu(int op, int a, int b)
{
	switch(op)
	{
		case 0:
			return a+b;
		case 1:
			return a-b;
		case 2:
			return a*b;
		case 3:
			return a/b;
		default:
			return 0;
	}
}
char Operation(int op)
{
	switch(op)
	{
		case 0:
			return '+';
		case 1:
			return '-';
		case 2:
			return '*';
		case 3:
			return '/';
		default:
			return '!';
	}
}
bool calculate(int a, int b, int c, int d)
{
	float tmp = 0;
	for(int i=0; i < 4; i++)
	{
		for(int j=0; j < 4; j++)
		{
			for (int k=0; k<4; k++)
			{
				tmp = Calcu(k,c,d);
				tmp = Calcu(j,b,tmp);
				tmp = Calcu(i,a,tmp);
				if (tmp == 24)
				{
				//	cout << "24 = ";
					cout << a;
					cout << Operation(i);
					cout << "(";
					cout << b;
					cout << Operation(j);
					cout << "(";
					cout << c;
					cout << Operation(k);
					cout << d;
					cout << ")";
					cout << ")" << endl;
					return true;
				}
				tmp = Calcu(k,c,d);
				tmp = Calcu(j,b,tmp);
				tmp = Calcu(i,tmp,a);
				if (tmp == 24)
				{
					cout << "(";
					cout << b;
					cout << Operation(j);
					cout << "(";
					cout << c;
					cout << Operation(k);
					cout << d;
					cout << ")";
					cout << ")";
					cout << Operation(i);
					cout << a << endl;
					return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	float a,b,c,d;
	cin >> a >> b >> c >> d;
	if(!calculate(a,b,c,d))
	{
		cout << "Error Answer" << endl;
	}
	return 0;

}