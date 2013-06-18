#include <iostream>
#include <cmath>
using namespace std;

char Num[100000];
int carry = 0;

int Add(int num, int cnt) {
	if (cnt <= 0) 
		return 0;
	int sum = 0;
	sum = num * cnt + carry;
	carry = sum / 10;
	return sum%10;
}

int main() {
	//memset(Num,'\0',10000);
	int num;
	int cnt;
	cin >> num >> cnt;
	if ((num == 0) || (cnt == 0)) {
		cout << "0" << endl;
		return 0;
	}
	for (int i = cnt; i > 0; i--) {
		Num[i-1] = Add(num,i) + '0';
	}
	if (carry > 0)
		cout << carry;
	for (int i = 0; i < cnt ; i++) {
		cout << Num[i];
	}
	cout << endl;
	return 0;
}