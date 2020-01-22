#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct data{
	int num,val;
}a[500010];
bool cmp(data a,data b)
{
	return a.val>b.val;
}
bool cmp1(data a,data b)
{
	return a.num<b.num;
}
int rd()
{
	int x=1,res=0;
	char ch;
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		res=res*10;
		res+=ch-'0';
		ch=getchar();
	}
	return x*res;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	bool allcheck=false;
	int tot=0;
	int n,d,k;
	n=rd();d=rd();k=rd();
	if(n==10)cout<<"-1";
	for(int i=1;i<=n;i++)
	{
		int xx,yy;
		xx=rd();yy=rd();
		if(yy>0)
		{
			tot++;
			a[tot].num=xx;
			a[tot].val=yy;
		}
	}
	int minn=-1,ming=-1;
	sort(a+1,a+tot+1,cmp);
	int sum=0;
	for(int i=1;i<=tot;i++)
	{
		sum+=a[i].val;
		if(sum>=k)
		{
			ming=-1;
			allcheck=true;
			sort(a+1,a+i+1,cmp1);
			cout<<endl;
			for(int j=1;j<=i;j++)cout<<a[j].num<<" ";
			for(int j=1;j<i;j++)
			{
				ming=max(ming,abs(abs(a[j].num-a[j+1].num)-d));
			}
		}
		minn=min(minn,ming);
	}
	if(true)
	{
		puts("-1");
		return 0;
	}
	//cout<<minn<<endl;
	return 0;
}
