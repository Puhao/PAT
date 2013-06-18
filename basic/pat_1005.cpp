#include <iostream>
using namespace std;
#define N 150
int bit_index[N];
int src[N];

void bit_map(int n) {
	if (n == 1)
		return;
	if (n%2) {
		int num = (3*n + 1)/2;
		if (num < N)
			bit_index[num] = 0;
		bit_map(num);
	}
	else {
		int num_ = n/2;
		if (num_ < N)
			bit_index[num_] = 0;
		bit_map(num_);
	}
	return;
}

int main() {
	int num_num;
	int tmp;
	cin >> num_num;
	for (int i = 0; i < num_num; i++) {
		cin >> tmp;
		src[i] = tmp;
		bit_index[tmp] = 1;
	}
	for (int i = 0; i < num_num; i++) {
		bit_map(src[i]);
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (bit_index[i] == 1)
			cnt++;
	}
	for (int i = N; i >= 0; i--) {
		if (bit_index[i] == 1) {
			cnt--;
			if (cnt == 0)
				cout << i << endl;
			else
				cout << i << " ";
		}
	}
	return 0;
}