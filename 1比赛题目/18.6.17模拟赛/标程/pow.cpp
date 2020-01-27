#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	string s;
	int a,len;
	int x;
	cin>>a;
	while(a--)
	{
		cin>>s;
		if(s=="0")
		{
			puts("6");
			continue;
		}
		len=s.length(); 
		if(len==1) x=s[0]-48;
		else x=(s[len-2]-48)*10+(s[len-1])-48;
		x%=4;
		switch(x)
		{
			case 1:puts("3");break;
			case 2:puts("9");break;
			case 3:puts("7");break;
			case 0:puts("5");break;
		}
	}
	return 0;
}
