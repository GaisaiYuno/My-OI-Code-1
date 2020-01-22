#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{
	int num,len;
}a[1010];

inline bool cmp(node xxx,node yyy)
{
	return xxx.num<yyy.num;
}

int n,q;
int query_len,query_num;

void query(int qlen,int qnum)
{
	for(int i=1;i<=n;++i)
	{
		if(a[i].len<qlen)
		{
			continue;
		}
		
		int temp=1;
		for(int k=1;k<=qlen;++k) temp*=10;
		
		int tmp=a[i].num%temp;//BUG fix by FYX@20171111
		
		if(tmp==qnum)
		{
			printf("%d\n",a[i].num);
			return ;
		}
	}
	
	printf("-1\n");
	return ;
}

int main(void)
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i].num);
		if(a[i].num<=9){a[i].len=1;continue;}
		if(a[i].num<=99){a[i].len=2;continue;}
		if(a[i].num<=999){a[i].len=3;continue;}
		if(a[i].num<=9999){a[i].len=4;continue;}
		if(a[i].num<=99999){a[i].len=5;continue;}
		if(a[i].num<=999999){a[i].len=6;continue;}
		if(a[i].num<=9999999){a[i].len=7;continue;}
		if(a[i].num<=99999999){a[i].len=8;continue;}
	}
	
	sort(a+1,a+1+n,cmp);
	
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d",&query_len,&query_num);
		
		query(query_len,query_num);
	}
	
	return 0;
}
