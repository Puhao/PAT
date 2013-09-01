#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>

using namespace std;


void dating(string a,string b,string c,string d)
{
	int day = -1;
	int hour = -1;
	int min = -1;
	for(int i=0;i<a.size();i++)
	{
		if (a[i] == b[i]) 
		{
			if (day == -1)
			{
				if(a[i] >= 'A' && a[i] <= 'G')
				{
					day = a[i] - 'A';
				}
			}
			else if (hour == -1)
			{
				if(a[i] >= 'A' && a[i] <= 'N')
				{
					hour = a[i] - 'A' + 10;
					break;
 				}
 				else if (isdigit(a[i]))
 				{
 					hour = a[i] - '0';
 					break;
 				}
 			}
		}
	}

	string Week[] = {"MON", "TUE", "WED", "THU", "FRI","SAT","SUN"};
	for(int i=0;i<c.size();i++)
	{
		if ( (c[i] == d[i]) && (isalpha(c[i])) )
		{
			min = i;
			break;
		}

	}
	cout.fill('0');
	cout << Week[day] << " " << setw(2) << hour << ":" << setw(2) << min << endl;
	return;

}

int main()
{
	//string StrAray[] = {"3485djDkxh4hhGE", "2984akDfkkkkggEdsb", "s&hgsfdk", "d&Hyscvnm"};
	string StrAray[4];
	for(int i=0;i<4;i++)
		cin >> StrAray[i];
	dating(StrAray[0],StrAray[1],StrAray[2],StrAray[3]);
	return 0;
}