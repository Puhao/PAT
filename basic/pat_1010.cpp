/*#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int num, power;
	int flag = 1;
	while (scanf("%d,%d",&num,&power) != EOF)	 {
		if (flag == 0) {
			flag = 1;
			cout << " ";
		}
		if (power != 0) {
			cout << num * power << " " << power -1;
			flag = 0;
		}
	}	
	return 0;

}
*/
#include <stdio.h>
#include <string.h>
 
 int main()
 {
 int n,e,flag=0;
 while(scanf("%d%d",&n,&e)!=EOF)
 {
 if(n*e)
 {
 if(flag)
 printf(" ");
 else
 flag=1;
 printf("%d %d",n*e,e-1);
 }
 }
 if(!flag) printf("0 0"); 
 return 0;
 }