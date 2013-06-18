#include <iostream>
#include <map>
#include <cmath>
using namespace std;
bool IsPrem(long int num)
{
	if(num < 2)
		return false;
	if(num == 2)
		return true;
	for(long int i=2; i <= sqrt(num); i++)
	{
		if (num%i == 0)
			return false;
	}
	return true;

}
int main()
{
	map<long int,int> num_map;
	long int num;
	long int tmp;
	cin >> num;
	tmp = num;
	if (num == 1)
	{
		cout << "1=1" << endl;
		return 0;
	}
	long int i = 2;
	while(i <= tmp)
	{
		if(!IsPrem(i))
		{
			i++;
			continue;
		}
		else
		{
			if (tmp%i)
			{
				i++;
				continue;
			}
			else
			{
				num_map[i]++;
				tmp = tmp / i;
			}
		}
	}
	cout << num << "=";
	map<long int,int>::iterator it;
	for(it = num_map.begin(); it != num_map.end(); it++)
	{
		if(it != num_map.begin())
		{
			cout << "*";
		}
		if(it->second == 1)
		{
			cout << it->first;
		}
		else
		{
			cout << it->first << "^" << it->second;
		}
	}
	cout << endl;
	return 0;
}