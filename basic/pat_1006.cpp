#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;
	int num;
	cin >> num;
	while (num) {
		s.push(num%10);
		num = num/10;
	}
	if (s.size() == 3) {
		for (int i = 0; i < s.top(); i++) {
			cout << "B";
		}
		s.pop();
	}
	if (s.size() == 2) {
		for (int i = 0; i < s.top(); i++) {
			cout << "S";
		}
		s.pop();
	}
	if (s.size() == 1) {
		for (int i = 1; i <=s.top(); i++) {
			cout << i;
		}
		s.pop();
		cout << endl;
	}
	return 0;
}