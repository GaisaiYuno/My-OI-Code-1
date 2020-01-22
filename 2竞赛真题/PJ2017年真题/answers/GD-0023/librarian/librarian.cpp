#include<cstdio>
#include<cstring>
using namespace std;
struct tree
{
	int x,y,next;
}t[2010];int last[2010],len=0;
struct node
{
	int nu;bool y;
	node(){y=false;}
}ni[2010];
int need[1010],l=0,now,h;
char ch[15];
int find(int x,int k)
{
	int i;
	for(i=last[x];i>0;i=t[i].next)
	{
		if(ni[t[i].y].nu==ch[now-k]-'0') return find(t[i].y,k+1);
	}
	h=k;
	return x;
}
int fi,xi;
void print(int x,int k)
{
	int i,min;
	if(k==now) fi=1;xi=x;
	if(fi==1&&ni[x].y)fi=2;
	if(fi==1)
	{
		min=t[last[x]].y;
		for(i=last[x];i>0;i=t[i].next)
		{
			if(ni[t[i].y].nu<ni[min].nu)
			{
				min=t[i].y;
			}
		}
		print(min,k+1);
	}
	else if(fi==0)
	{
		for(i=last[x];i>0;i=t[i].next)
		{
			if(ni[t[i].y].nu==ch[now-k]-'0')
			{
				print(t[i].y,k+1);break;
			}
		}
	}
	if(fi==2&&x!=0) printf("%d",ni[x].nu);
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,bul,i,j;l=0;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		now=strlen(ch+1);
		bul=find(0,0);
		for(j=now-h;j>=1;j--)
		{
			len++;l++;
			ni[l].nu=ch[j]-'0';
			if(j==1)ni[l].y=true;
			t[len].x=bul;t[len].y=l;t[len].next=last[bul];last[bul]=len;
			bul=l;
		}
		if(now==h)ni[bul].y=true;
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d %s",&now,ch+1);
		fi=0;
		print(0,0);
		if(fi<2)printf("-1");
		printf("\n");
	}
	return 0;
}
