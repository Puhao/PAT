#include <iostream>
#include <math.h>
using namespace std;
bool prime_check(int n) {
	if (n < 2)
		return false;
	if (n == 2)
		return true;
	for (int j = 2; j <= sqrt(n); j++) {
		if ( (n%j)==0 )
			return false;
	}
	return true;
}
int main() {
	int num;
	cin >> num;
	int prime_1 = 2;
	int prime_2 = 3;
	int cnt = 0;
	for (int k=4; k <= num; k++) {
		if (prime_check(k)) {
			prime_1 = prime_2;
			prime_2 = k;
			if (( prime_2 - prime_1) == 2 )
				cnt++;
		}
	}
	cout << cnt << endl;
}