#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

double set_similarity(set<int> a,set<int> b)
{
	double pub = 0;
	set<int>::const_iterator it;
	for (it=a.begin();it!=a.end();it++)
	{
		if(b.count(*it))
			pub++;
	}
	return 100 * pub / (a.size() + b.size() - pub);
}

int main()
{
	vector<set<int> > AllSet;
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
		AllSet.push_back(TmpSet);
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

	return 0;
}
