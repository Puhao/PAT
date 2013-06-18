#include <iostream>
#include <string.h>
using namespace std;

char UpStudentName[11];
char UpStudentId[11];
char DownStudentName[11];
char DownStudentId[11];
int main() {
	int num = 0;
	cin >> num;
	int HighScore = 0;
	int LowScore = 100;
	char StudentName[11];
	char StudentId[11];
	int score = 0;
	for (int i = 0; i < num; i++) {
		cin >> StudentName >> StudentId >> score;
		if (score < LowScore) {
			LowScore = score;
			strcpy(DownStudentName, StudentName);
			strcpy(DownStudentId, StudentId);
		}
		if (score > HighScore) {
			HighScore = score;
			strcpy(UpStudentName, StudentName);
			strcpy(UpStudentId, StudentId);
		}
	}
	cout << UpStudentName << " " << UpStudentId << endl;
	cout << DownStudentName << " " << DownStudentId << endl;
	return 0;
}