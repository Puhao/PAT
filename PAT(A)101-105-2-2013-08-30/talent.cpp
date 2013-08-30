#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
	long long int id;
	int virtue;
	int talent;
	student(long long int i,int v,int t):id(i),virtue(v),talent(t){}
	/* data */
};

bool compare_less(const student &a,const student &b)
{
	return ((a.virtue + a.talent) > (b.virtue + b.talent));
}

int main()
{
	int num,low,high;
	cin >> num >> low >> high;
	int count = 0;
	long long int id;
	int virtue;
	int talent;
	vector<student> stu[4];
	while(num--)
	{
		cin >> id >> virtue >> talent;
		if ((virtue < low) || (talent < low))
		{
			continue;
		}
		count++;
		if ((virtue >= high) && (talent >= high))
		{
			stu[0].push_back(student(id,virtue,talent));
		}
		else if ((virtue >= high) && (talent < high))
		{
			stu[1].push_back(student(id,virtue,talent));
		}
		else if ((virtue < high) && (talent < high) && (virtue >= talent))
		{
			stu[2].push_back(student(id,virtue,talent));
		}
		else
		{
			stu[3].push_back(student(id,virtue,talent));
		}		
	}
	for(int i=0;i<4;i++)
	{
		sort(stu[i].begin(), stu[i].end(),compare_less);
	}
	cout << count << endl;
	for(int i=0;i<4;i++)
	{
		vector<student>::const_iterator it;
		for(it = stu[i].begin(); it != stu[i].end(); it++)
		{
			cout << it->id << " " << it->virtue << ' ' << it->talent << endl;
		}
	}

	return 0;
}