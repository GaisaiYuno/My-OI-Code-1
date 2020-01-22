#include<cstring>
#include<string>
#include<fstream>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cwchar>
#include<cwctype>
#include<limits>
using namespace std;
int main()
{
	int p=0,q=0,sr[100005],len[100005],n=0,d=0,k=0,y=0,o=0,u=0;
	//freopen("jump.in","r",stdin);
    //freopen("jump.out","w",stdout);
     scanf("%d%d%d",&n,&d,&k);
    for (int i=1;i<=n;i++)
    {
    	scanf("%d%d",&len[i],&sr[i]);
    	if(sr>0)
    	q=q+sr[i];
    }
    for (int i=1;i<=n;i++)
    {
	    if (p>k) break;
    	if(sr[i]<0)
    	p=p+len[i]-len[i-1];
    }
	for (int i=1;i<=n;i++)
    {
    	y=y+len[i]-len[i-1];
    }
    u=q;
    if(q>k)
    o=y;
    for (int i=n;i>n;i--)
    {
    	u-=sr[i];
    	if (u<k)
    	u+=sr[i];
    }
    if (q<k)
	cout<<-1;
	if(o<p) o=p;
	if(o<u) o=u;
	cout<<o;
	return 0;
}
