#include <iostream>
using namespace std;

int num[101];

int main() {
	int len, step;
	cin >> len >> step;
	for (int i=0; i<len; i++)
		cin >> num[i];
	for (int j=0; j<(len-1); j++) {
		int tmp = (j+len-step) % len;
		if (tmp < 0)
			tmp += len;
		cout << num[tmp] << " ";
	}
	int tmp = (len - step -1) % len;
	if (tmp < 0)
		tmp += len;
	cout << num[tmp] << endl;
	return 0;

}