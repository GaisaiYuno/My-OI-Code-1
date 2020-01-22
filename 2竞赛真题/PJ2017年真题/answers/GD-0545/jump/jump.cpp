#include<iostream>
using namespace std;
int n,d,k,x[500001]={0},s[500001]={0};
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int ans=0;
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>s[i];
		if(s[i]>=0) ans=s[i]+ans;
	} 
	if(ans<k) 
	{
		cout<<-1;
		return 0;
	}
	cout<<-1;
}
