#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int n,d,k,x[500500],s[500500],sum[500500],try1,l;
int he(int xx)
{
    memset(sum,0,sizeof(sum));
	int k1=0,k2=d+xx,maxx=0;
	if (d>xx) k1=d-xx;else k1=1;
    if (x[1]<k1) return 0;
    for (int i=1;i<=n;i++)	
    	{ 
		  maxx=0;
    	  for (int j=i-1;j>0;j--)
    	    if (x[i]-x[j]>k2) break;else
    	      if (x[i]-x[j]>k1)
    	      {
    	        if (sum[j]>maxx) maxx=sum[j];
    	      }
    	  sum[i]=maxx+s[i];
    	  if (sum[i]>k) return 1;
        }
    return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	int try0=1,ll=0,suml=0,maxl=0,sum=0,summ=0;
	for (int i=1;i<=n;i++)
	{
	  cin>>x[i]>>s[i];
	  ll=x[i]-x[i-1];
	  if (ll==d) {summ+=s[i];}else try0=0;
	  suml+=ll;
	  if (s[i]>0)sum+=s[i];
	  if (ll>maxl) maxl=ll;
    }
    if (sum<k) cout<<-1<<endl;else
    if (try0==1&&summ>=k) cout<<0<<endl;else
    {
    	int L=maxl-d,R=suml+1;
    	if (L<0) L=0;
    	while (L+1<R)
    	{
    		int mid=(L+R)/2;
    		if (he(mid)==0) L=mid;else R=mid;
    	}
    	if (R==suml+1) cout<<-1;else cout<<R;
    }
	return 0;
}

