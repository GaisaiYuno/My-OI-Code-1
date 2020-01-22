#include<cstdio>
#include<cstring>

int n,k;
char st[2100][210],a[2100][210];
int l1[2100],l2[2100];

int sum[2100];
int ans[2100];

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",st[i]+1);
		l1[i]=strlen(st[i]+1);
		for(int j=1;j<=l1[i];j++) sum[i]=sum[i]*10+(st[i][j]-'0');
	}
	
	for(int i=1;i<=k;i++)
	{
		scanf("%d %s",&l2[i],a[i]+1);
	}
	
	for(int i=1;i<=k;i++)
	{
		int tot=0,min=999999999;
		for(int j=1;j<=n;j++)
		{
			if(l2[i]>l1[j]) continue;
			int f=0,f1=l2[i];
			for(int k=l1[j];k>=l1[j]-l2[i]+1;k--)
			{
				if(st[j][k]!=a[i][f1]) { f=1;  }
				f1--;
			}
			if(f==0)
			{
				tot++;
				if(min>sum[j]) min=sum[j];
			}
		}
		if(tot!=0) ans[i]=min;
		else ans[i]=-1;
	}
	for(int i=1;i<k;i++) printf("%d\n",ans[i]);
	printf("%d",ans[k]);
	return 0;
}
/*
5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12

23
1123
-1
-1
-1
*/
