#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=1005;
int n,b,q;
int a[maxn],num[maxn],ans[maxn];

bool check(int x,int y)//x是人的编号 y是书的编号
{
	int now1=x,now2=y;
	while(1)
	{
		if(now1==0) return true;
		if(now1%10!=now2%10) return false;
		now1=now1/10;
		now2=now2/10;
	}
} 

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=q;i++) scanf("%d%d",&b,&num[i]);
	
	sort(a+1,a+1+n);
	 
	for(int i=1;i<=q;i++)//枚举人 
	{
		int v=0;
		for(int j=1;j<=n;j++)//枚举 书 
		{
			if(a[j]<num[i]) continue;
			
			if(check(num[i],a[j])==true)
			{
				ans[i]=a[j];
				v=1;
				break;
			}
		}
		if(v==0) ans[i]=-1;
	}
	
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	
	return 0;
}
