#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const double Threshold = 1E-6;
const int CardNumber = 4;
const int ResutlValue = 24;

double number[CardNumber];
string result[CardNumber];

bool point_game(int n)
{
	if (n == 1)
	{
		if (fabs(number[0] - ResutlValue) < Threshold)
		{
			//根据需要，最外面的括号不要
			string tmp = result[0];
			int len = tmp.size();
			for (int i=1; i<len-1; i++)
				cout << tmp[i];
			cout << endl;
			return true;
		}
		else
			return false;
	}
	//每次从里面取出两个数，然后把运算结果再放回去，递归检测，检测完之后要放回来
	for (int i=0; i < n; i++)
	{
		for (int j=i+1; j < n; j++)
		{
			double a,b;
			string expa,expb;
			a = number[i];
			b = number[j];
			number[j] = number[n-1];//运算完之后，数组就少了一个数了，因此要保存这个数，放在拿出来的第二个位置，第一个位置留给算出来的结果
			expa = result[i];
			expb = result[j];
			result[j] = result[n-1];

			//
			result[i] = "(" + expa + "+" + expb + ")";
			number[i] = a + b;
			if (point_game(n-1))
				return true;

			result[i] = '(' + expa + '-' + expb + ')';  
			number[i] = a - b;
			if (point_game(n-1))
				return true;
			
			result[i] = "(" + expb + "-" + expa + ")";
			number[i] = b - a;
			if (point_game(n-1))
				return true;

			result[i] = "(" + expa + "*" + expb + ")";
			number[i] = a * b;
			if (point_game(n-1))
				return true; 

			if (b != 0)
			{
				result[i] = "(" + expa + "/" + expb + ")";
				number[i] = a / b;
				if (point_game(n-1))
					return true;
			}

			if (a != 0)
			{
				result[i] = "(" + expb + "/" + expa	 + ")";
				number[i] = b / a;
				if (point_game(n-1))
					return true;
			}

			//把数据放回原处
			number[i] = a;
			number[j] = b;
			result[i] = expa;
			result[j] = expb;
		}  	
	}
	return false;
}

void my_itoa(int n,char s[])  
{  
    int i,j,sign;  
  
    if((sign=n)<0)    //记录符号  
        n=-n;         //使n成为正数  
    i=0;  
    do{  
        s[i++]=n%10+'0';    //取下一个数字  
    }while((n/=10)>0);      //循环相除  
  
    if(sign<0)  
        s[i++]='-';  
    s[i]='\0';
    int start = 0;
    int end = i -1;
    //把顺序倒过来
    while(start < end)
    {
    	char tmp = s[start];
    	s[start] = s[end];
    	s[end] = tmp;
    	end--;
    	start++;
    }  
}  

int main()
{
	int x;
	for (int i=0; i < CardNumber; i++)
	{
		char buffer[10];
		//cout << "Input the" << i << " number:";
		cin >> x;
		number[i] = x;
		my_itoa(x,buffer);
		result[i] = buffer;
	}
	if (point_game(CardNumber))
	{
		return 0;
	}
	else
	{
		cout << "-1" << endl;
		return 0;
	}
}