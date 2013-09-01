#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct student
{
	long long int id;
	int virtue;
	int talent;
	int grade;
	student(long long int i,int v,int t,int g):id(i),virtue(v),talent(t),grade(g){}
	/* data */
};

bool compare_method(const student &a,const student &b)
{
	if (a.grade == b.grade)
	{
		if ((a.virtue + a.talent) == (b.virtue + b.talent))
		{
			if (a.virtue == b.virtue)
			{
				return a.id < b.id;
			}
			else
				return a.virtue > b.virtue;
		}
		else
			return ((a.virtue + a.talent) > (b.virtue + b.talent));
	}
	else
		return a.grade < b.grade;
}

int main()
{
	int num,low,high;
	cin >> num >> low >> high;
	int count = 0;
	long long int id;
	int virtue;
	int talent;
	vector<student> stu;
	while(num--)
	{
		//cin >> id >> virtue >> talent;
		scanf("%lld %d %d",&id,&virtue,&talent);
		if ((virtue < low) || (talent < low))
		{
			continue;
		}
		count++;
		if ((virtue >= high) && (talent >= high))
		{
			stu.push_back(student(id,virtue,talent,0));
		}
		else if ((virtue >= high) && (talent < high))
		{
			stu.push_back(student(id,virtue,talent,1));
		}
		else if ((virtue < high) && (talent < high) && (virtue >= talent))
		{
			stu.push_back(student(id,virtue,talent,2));
		}
		else
		{
			stu.push_back(student(id,virtue,talent,3));
		}		
	}
	sort(stu.begin(), stu.end(),compare_method);
	cout << count << endl;
	vector<student>::const_iterator it;
	for(it = stu.begin(); it != stu.end(); it++)
		//cout << it->id << " " << it->virtue << ' ' << it->talent << endl;
		printf("%lld %d %d\n", it->id,it->virtue,it->talent);
	return 0;
}