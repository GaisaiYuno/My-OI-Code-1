# include<iostream>
# include<cstdio>
# include<cstdlib>
# include<algorithm>
# include<cmath>
# include<string>
# include<cstring>
using namespace std;
int xx[500000+5],ss[500000+5];
int main()
{
	int n,d,k,t,tt,w,m,y;
	long long s=0,g=-1;
	
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	cin>>n>>d>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>xx[i]>>ss[i];
		if (ss[i]>0) {s+=ss[i];}
	}
	if (s<k) {cout<<-1; return 0;}
	s=0;
	while (s<k)
	{
		g++; w=0; s=0;
		if (g<d) {t=d-g; tt=d+g;} else {t=1; tt=d+g;}
		if (g==0) {t=d; tt=d;}
       	for (int i=1;i<=n;i++)
		{
			m=-100100;
      		if (ss[i]<0) {
				for (int j=i;j<=n;j++)
				{
 					if (xx[j]>w+tt) {break;}
 					if ((xx[j]>w+t)&&(ss[j]>0)) {i=j; break;}
					if ((xx[j]>w+t)&&(ss[j]>m)) {m=ss[j]; y=j;}
					i=y;
				}
						 }
			if ((xx[i]-w<t)||(xx[i]-w>tt)) {break; s=0;}
			s+=ss[i]; w=xx[i];
 			if (s>=k) {break;}
		}
	}
	cout<<g;
	return 0;
}
