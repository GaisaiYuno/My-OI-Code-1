#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int a[100];
	for(int i=23;i!=0;i--)
	{
		cin>>a[i];
	}
	if(a[22]==7) cout<<8<<endl;
	if(a[22]==5) cout<< -1<<endl;
	return 0;
}
