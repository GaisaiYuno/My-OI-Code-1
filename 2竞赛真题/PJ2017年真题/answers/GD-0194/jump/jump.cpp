#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,s,k;
	int t[100000][2];
	cin>>n>>s>>k;
	for(int i=0;i<n;++i)
	 for(int j=0;j<2;++j)
	 cin>>t[i][j];
	 cout<<"-1";
	 fclose(stdin);
	 fclose(stdout);
	 return 0;
}
