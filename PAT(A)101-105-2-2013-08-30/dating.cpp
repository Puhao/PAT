#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>

using namespace std;


void dating(string a,string b,string c,string d)
{
	char FstLet,SecLet;
	int count = 0;
	for(int i=0;i<a.size();i++)
	{
		if ((a[i] == b[i]) && (isupper(a[i])))
		{
			if (count == 0)
			{
				count = 1;
				FstLet = a[i];
			}
			if (count == 1)
			{
				count = 2;
				SecLet = a[i];
			}
		}
	}
	string Week[] = {"MON", "TUE", "WED", "THU", "FRI","SAT","SUN"};
	int hour,minu;
	if (isdigit(SecLet))
		hour = SecLet - '0';
	else
		hour = SecLet - 'A' + 10;
	count = 0;
	for(int i=0;i<c.size();i++)
	{
		if ( (c[i] == d[i]) && (isalpha(c[i])) )
		{
			if (count == 0)
			{
				count = 1;
				minu = i;
			}
		}

	}
	cout.fill('0');
	cout << Week[FstLet - 'A'] << " " << setw(2) << hour << ":" << setw(2) << minu << endl;
	return;

}

int main()
{
	string StrAray[] = {"3485djDkxh4hhGE", "2984akDfkkkkggEdsb", "s&hgsfdk", "d&Hyscvnm"};
	dating(StrAray[0],StrAray[1],StrAray[2],StrAray[3]);
	return 0;
}