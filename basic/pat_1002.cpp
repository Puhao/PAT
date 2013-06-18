#include <iostream>
#include <string>
#include <stack>

using namespace std;

string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main(){
	stack<int> s;
	int sum = 0;
	char src_input[100];
	char *p = src_input;
	cin >> src_input;
	while(*p != '\0') {
		sum += *p - '0';
		p++;
	}
	while(sum != 0) {
		int tail = sum % 10;
		s.push(tail);
		sum = sum / 10;
	}
	while ( s.size() != 1 ) {
		cout << num[s.top()] << " ";
		s.pop();
	}
	cout << num[s.top()];
	s.pop();
	return 0;
}