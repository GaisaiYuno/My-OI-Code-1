# include<cstdio>
# include<cstring>
# include<algorithm>
using namespace std;
const int N = 1e3 + 10;
struct node
{
	int val,len;
}a[N];
int n,q,i,pre,len,ans;
bool cmp(node a,node b)
{
	return a.val < b.val;
}
int getans(int a,int b,int len)
{
	int val = 0,sum = 1;
	while (len--)
	{
		val += (a % 10) * sum;
		a /= 10;
		sum *= 10;
	}
	if (val == b) return 1;
	else return 0;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (i = 1;i <= n; i++)
	{
		scanf("%d",&a[i].val);
		int tmp = a[i].val; len = 0;
		while (tmp)
		{
			len++;
			tmp /= 10;
		}
		a[i].len = len;
	}
	sort(a + 1,a + n + 1,cmp);
	for (i = 1;i <= q; i++)
	{
		scanf("%d%d",&len,&pre);
		ans = -1;
		for (int j = 1;j <= n; j++)
		{
			if (a[j].len < len) continue;
			if (getans(a[j].val,pre,len)) { ans = a[j].val; break; }
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
