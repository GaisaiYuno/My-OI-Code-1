#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int x[500001],s[500001];
int n,d,k,g,sum=0;
int i,j;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(i=0;i<n;i++) cin>>x[i]>>s[i];
	for(i=0;i<n;i++) 
	{
		if(s[i]>=0) sum=sum+s[i];
	}
	if(sum<k)
	{
		int abc=-1;
		cout<<abc<<endl;
		return 0;
	}
	else cout<<'3';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
