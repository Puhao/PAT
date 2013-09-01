#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

double set_similarity(vector<int> &a,vector<int> &b)
{
	int pub = 0;
	vector<int>::const_iterator it_a, it_b;
	it_a = a.begin();
	it_b = b.begin();
	while(it_a != a.end() && it_b != b.end())
	{
		if(*it_a == *it_b)
		{
			pub++;
			it_a++;
			it_b++;
		}
		else if(*it_a < *it_b)
		{
			it_a++;
		}
		else
			it_b++;
	}
	return 100.0 * pub / (a.size() + b.size() - pub);
}

void print_vector(vector<vector<int> > &v)
{
	vector<vector<int> >::const_iterator it;
	std::vector<int>::const_iterator it_int;
	for (it = v.begin(); it != v.end(); it++)
	{
		for(it_int=it->begin();it_int!=it->end();it_int++)
		{
			cout << *it_int << ' ';
		}
		cout << endl;
	}
	return;
}
int main()
{
	vector<vector<int> > AllSet;
	set<int> TmpSet;
	int num,cnt;
	cin >> num;
	int index = 0;
	int tmp;
	while(index != num)
	{
		TmpSet.clear();
		cin >> cnt;
		while (cnt--)
		{
			cin >> tmp;
			TmpSet.insert(tmp);
		}
		vector<int> OneSet(TmpSet.begin(),TmpSet.end());
		AllSet.push_back(OneSet);
		index++;
	}
	cin >> num;
	int one,two;
	while(num--)
	{
		cin >> one >> two;
		double resutl = set_similarity(AllSet[one-1],AllSet[two-1]);
		cout << setiosflags(ios::fixed)<< setprecision(1) <<resutl << "%" << endl;
	}
	//print_vector(AllSet);
	return 0;
}
