#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<deque>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	int a,b,c;  
	
	cin>>a>>b>>c;
	
	cout<<a*0.2+b*0.3+c*0.5;
	
	return 0;
}

