#include<bits/stdc++.h>
using namespace std;
int a,b,c,ans;
int main()
{
	freopen("score.in.txt","r",stdin);
	freopen("score.out.txt","w",stdout);
	cin>>a>>b>>c;
	ans=a/5+(b/10)*3+c/2;
	cout<<ans;
	return 0;
}
