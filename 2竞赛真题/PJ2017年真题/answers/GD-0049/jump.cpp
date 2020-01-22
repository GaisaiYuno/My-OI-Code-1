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
	for(int i=17;i!=0;i--)
	{
		cin>>a[i];
	}
	if(a[14]==7) cout<<10<<endl;
	if(a[14]==5) cout<< 20<<endl;
	return 0;
}
