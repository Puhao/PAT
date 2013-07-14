#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
using namespace std;

#define LEN 1001
float Poloy[3][LEN];

int main()
{
	//memset(Poloy,0,sizeof(Poloy));
	int k, pos;
	float value;
	cin >> k;
	while(k > 0)
	{
		cin >> pos >> value;
		k--;
		Poloy[0][pos] = value;
	}
	cin.get();
	cin >> k;
	while (k >0)
	{
		cin >> pos >> value;
		k--;
		Poloy[1][pos] = value;
	}
	cin.get();

	for (int i=0; i<LEN; i++)
	{
		Poloy[2][i] = Poloy[0][i] + Poloy[1][i];
	}
	int count = 0;
	for(int i=0; i< LEN; i++)
	{
		if (Poloy[2][i] !=0)
			count++;
	}
	cout << count;
	for(int j=LEN - 1; j >=0; j--)
	{
		if (Poloy[2][j] != 0)
			//cout << " " << j  << " " << Poloy[2][j];
			printf(" %d %.1f",j,Poloy[2][j]);
	}
	cout << endl;
	return 0;
}