#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long n,d,k,dis[500010],sc[500010],dp[500010],tot,mid,lef,rig,ans=0x7fffffff,noww,maxx,fen,zui;
int check(int tor)
{
	noww=0;maxx=-0x7fffffff;
	for(int i=1;i<=n;i++) dp[i]=-0x7fffffff;
	dis[0]=0;dp[0]=0;sc[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(dis[i]-dis[j]<d-tor) continue;
			if(dis[i]-dis[j]>d+tor) break;
			dp[i]=max(dp[i],dp[j]+sc[i]);
		}
		maxx=max(maxx,dp[i]);
	}
	//cout<<maxx<<endl;
	if(maxx>=k) return 1;
	else return 0;
}
int ju(int tor)
{
	noww=0;maxx=-0x7fffffff;fen=0;zui=-0x7fffffff;
	while(noww<n)
	{
		long long flag=0,mp=0,mf=0,nowwy=noww;
		for(int tmp=noww+1;tmp<=n;tmp++)
		{
			if(dis[tmp]-dis[noww]>d+tor) break;
			if(sc[tmp]>0)
			{
				noww=tmp;
				fen+=sc[tmp];
				maxx=max(fen,maxx);
				flag=1;
				break;
			}
			else
			{
				if(mp==0&&mf==0)
				{
					mp=tmp;
					mf=fen+sc[tmp];
				}
				else if(fen+sc[tmp]>mf)
				{
					mp=tmp;
					mf=fen+sc[tmp];
				}
			}
		}
		if(flag==0)
		{
			noww=mp;
			fen=mf;
		}
		if(noww==nowwy||noww==0) return 0;
		//cout<<"2"<<" "<<noww<<endl;
	}
	//cout<<"1"<<endl;
	if(maxx>=k) return 1;
	else return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%lld%lld%lld",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&dis[i],&sc[i]);
		if(sc[i]>0) tot+=sc[i];
	}
	if(tot<k)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	if(d==1)
	{
		lef=0;rig=dis[n]-d;
		while(lef<=rig)
		{
			mid=(lef+rig)/2;
			int tor1=ju(mid);
			//cout<<mid<<" "<<tor1<<endl;
			if(tor1==1)
			{
				ans=min(ans,mid);
				rig=mid-1;
			}
			else lef=mid+1;
		}
	}
	else
	{
		lef=0;rig=max(dis[n]-d,d-1);
		while(lef<=rig)
		{
			mid=(lef+rig)/2;
			int tor1=check(mid);
			//cout<<mid<<" "<<tor1<<endl;
			if(tor1==1)
			{
				ans=min(ans,mid);
				rig=mid-1;
			}
			else lef=mid+1;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
7 1 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2
*/
