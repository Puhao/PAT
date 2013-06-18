#include <iostream>
using namespace std;
char CharSrc[100];

int main() {
	int num;
	cin >> num;
	for (int i=0; i < num; i++) {
		cin >> CharSrc;
		int p_index = -1;	//'P' position
		int t_index = -1;	//'T' position
		int dis = 0;		//distance between 'P' and 'T'
		int index = 0;
		bool result = true;
		while(CharSrc[index] != '\0') {
			if (CharSrc[index] == 'P') {
				if (p_index < 0)
					p_index = index;
				else {
					result = false;
					break;
				}
			}
			else if (CharSrc[index] == 'T') {
				if (t_index < 0)
					t_index = index;
				else {
					result = false;
					break;
				}
			}
			else if (CharSrc[index] != 'A') {
				result = false;
				break;
			}
			index++;
		}
		if ((p_index < 0) || (t_index < 0) || (p_index >= (t_index-1))) {
			result = false;
		}
		else {
			dis = t_index - p_index;
			int length = (dis - 1) * (p_index) + t_index;
			if (length != index - 1)
				result = false;
			else
				result = true;
		}
		if (result)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}