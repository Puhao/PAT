#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int num;
	vector<int> v;
	cin >> num;
	int tmp;
	int sum = 0;
	float avg = 0;
	double result = 0;
	for (int i=0; i<num; i++) {
		cin>>tmp;
		v.push_back(tmp);
		sum += tmp;
	}
	avg = float(sum) / v.size();
	vector<int>::iterator it;
	for(it = v.begin(); it < v.end(); it++) {
		result += pow((*it - avg),2);
	}
	result = result / v.size();
	result = sqrt(result);
	cout << fixed << setprecision(5) << result << endl;
	return 0;
}