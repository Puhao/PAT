#include <iostream>
#include <string>
using namespace std;

void exchange(char *p, char *q) {
	if ((p == NULL)||(q == NULL))
		return;
	while(p < q)  {
		char tmp = *q;
		*q = *p;
		*p = tmp;
		p++;
		q--;
	}
	return;
}
int main() {
	string str;
	getline(cin,str);
	char *p = &str[0];
	char *q = &str[str.size() - 1];
	exchange(p,q);
	char *pStart, *pEnd;
	pStart = &str[0];
	pEnd = &str[0];
	while (*pStart != '\0') {
		if (*pStart == ' ') {
			pStart++;
			pEnd++;
			continue;
		}
		else if ((*pEnd == ' ')||(*pEnd == '\0') ) {
			pEnd--;
			exchange(pStart,pEnd);
			pStart = ++pEnd;
		}
		else {
			pEnd++;
		}
	}
	cout << str << endl;
	return 0;
}