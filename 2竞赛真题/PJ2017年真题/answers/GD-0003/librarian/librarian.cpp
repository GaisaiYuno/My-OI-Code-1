#include<cstdio>
#include<cstdlib>
using namespace std;
const int MAXN=2e9;
int N,Q,Book[1005],Need[1005],x=1;
struct stu
{
	int len,num;
}node[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++)
		scanf("%d",&Book[i]);
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d",&node[i].len,&node[i].num);
		Need[i]=MAXN;
	}
	for(int i=0;i<Q;i++)//人的数目 
	{
		for(int j=0;j<N;j++)//书的数目 
		{
			x=1;
			for(int k=0;k<node[i].len;k++) x*=10;
			if(Book[j]%x==node[i].num && Book[j]<Need[i]) Need[i]=Book[j]; 
		}
	}
	for(int i=0;i<Q;i++)
	{
		if(Need[i]==MAXN) printf("-1\n");
		else printf("%d\n",Need[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
