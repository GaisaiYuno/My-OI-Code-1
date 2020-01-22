#include<iostream>
#include<fstream>
using namespace std;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	long long n,d,k,s[100005]{0},ans,x;
	int l=0;
	cin>>n>>d>>k;
	for(long long i=1;i<=n;i++)
	{
		long long a,b;
		cin>>a>>b;
		s[a]=b;
		if(i==n)x=a;
	}
	if(d==1)
	for(long long i=x-1;i>=0;i--)
	{
		
		long long j=0,count=0;
		while(j<x)
		{
			j+=i+d;
			count+=s[j];
		}
		if(count>=k) {
		ans=i;l=1;
	    }
	}
	if(d!=1){
		cout<<-1<<endl;
		return 0;
	}
	if(l==1)cout<<ans<<endl;
	if(l!=1)cout<<0-1<<endl;
	return 0;

}
