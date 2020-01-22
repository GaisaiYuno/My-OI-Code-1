#include<cstdio>
using namespace std;
struct dz
{
	int len;
	int id;
};
struct sj
{
	int len;
	int id;
};
dz b[1000];
sj a[1000];

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0,temp,cs;i<m;i++)
	{
		cs=0;
		scanf("%d",&a[i].id);
		temp=a[i].id;
		while(temp!=0)
		{
			cs++;
			temp/=10;
		}
		a[i].len=cs;
	}
	for(int i=0,min,t;i<n;i++)
	{
		min=10000001;
		scanf("%d",&b[i].len);
		scanf("%d",&b[i].id);
		for(int j=0,temp1,temp2,pd;j<m;j++)
		{
			pd=0;
			if(a[j].len<b[i].len) continue;
			temp1=a[j].id;
			temp2=b[i].id;
			t=b[i].len;
			while(t-->0)
			{
				if(temp1%10==temp2%10)
				{
					temp1/=10;
					temp2/=10;
				}
				else
				{
					pd=1;
					break;
				}
			}
			if(pd==0&&a[j].id<min)
			{
				min=a[j].id;
			}
		}
		if(min==10000001)
		{
			printf("-1\n");
		}
		else printf("%d\n",min);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
