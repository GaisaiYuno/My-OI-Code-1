#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,i,j,h,h2,jb,jl,x[500005],s[500005],a[500005];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (i=1;i<=n;i++)
	{
		cin>>x[i]>>s[i];
		if (s[i]>0) h+=s[i];h2+=s[i];
		if (i==1) a[i]=d-x[i]; else a[i]=x[i]-x[i-1];
	}
	if (h<k) {cout<<-1<<endl; return 0;}
	j=0;
	while (jl<k)
	{
		for (i=1;i<=n;i++) 
		if (a[i]>=d-jb&&a[i]<=d+jb&&s[i]>=0) jl+=s[i]; else
		if (a[i]>=d-jb&&a[i]<=d+jb&&s[i]<0&&h2>=k) jl+=s[i]; else
		if (a[i]>=d-jb&&a[i]<=d+jb&&s[i]<0&&h2<k) continue;
		if (jl>=k) break; else {jb++;jl=0;}
	}
	cout<<jb<<endl;
	return 0;
}
