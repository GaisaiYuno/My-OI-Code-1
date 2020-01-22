#include<bits/stdc++.h>
using namespace std;
struct v1{
	int x,s;
}a[500001];
struct v2{
	int i,l;
}s2[500001];
int n,k,d,i,j,cnt,sum,s[500001],g,re,s1[500001];
bool cmp(v2 a,v2 b)
{
	return a.l>b.l;
}
int main()
{
	cin>>n>>d>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].s;
		if(a[i].s>0){
			sum+=a[i];
			cnt++;
			s[cnt]=i;
			g=max(g,abs(s[cnt]-s[cnt-1]));
		    s2[cnt].i=cnt;
		    s2[cnt].l=abs(s[cnt]-s[cnt-1]);
		}
	}
	if(sum<k)cout<<"-1";
	else 
	if(sum==k)cout<<g;
	else{	
	re=sum-k;
	while(re-a[s[s2[cnt].i]].x>=0&&s2[cnt].l==g)cnt--,rest-=a[s[s2[cnt].i]].x;
	sort(s2+1,s2+cnt+1,cmp);
	for(i=1;i<=cnt;i++)
	{
		int tmp=100000000;
		for(j=s[s2[cnt].i-1]+1;j<s[s2[cnt].i];j++)
		{
			if(re-a[j]>=0)
			{
				tmp=min(tmp,min(a[j]-a[s[s2[cnt].i-1]],a[s[s2[cnt].i]]-a[j]));
			}
		}
		if(s2[i+1]<g)g=tmp;
	}  	
	}
	cout<<g;
}
