#include<cstdio>
#include<algorithm>
using namespace std;
struct node{int x[12],num;}c[1001];
int a[1001],b,q,n,y,i,j,k,o;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		c[i].num=0;
		while(a[i]!=0)
		{
			c[i].x[c[i].num]=a[i]%10;
			a[i]/=10; c[i].num++;
		}
	}
	for(i=1;i<=q;i++)
	{
		bool tf=true; scanf("%d%d",&y,&b);
		for(k=1;k<=n;k++)
		{
			o=b;
			if(y>c[k].num) continue;
			for(j=0;j<y;j++){if(c[k].x[j]!=o%10) break; o/=10;}
			if(o==0) 
			{
				for(j=c[k].num-1;j>=0;j--) printf("%d",c[k].x[j]);
				printf("\n"); tf=false; break;
			}	
		}
		if(tf) printf("-1\n"); 
	}
	fclose(stdin); fclose(stdout);
	return 0;
}

