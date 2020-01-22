#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n, q, i, j, code[1010], len, x;
bool b;
int cf(int x)
{
	int r=1;
	while (x>0)
	{
		x--;
		r*=10;
	}
	return r;
}
int main()
{
	freopen("librarian.in", "r", stdin);
	freopen("librarian.out", "w", stdout);
	memset(code, 0, sizeof(code));
	scanf ("%d%d", &n, &q);
	for (i=1;i<=n;i++) scanf ("%d", &code[i]);
	sort(code+1,code+n+1);
	for (i=1;i<=q;i++)
	{
		b=true;
		scanf ("%d %d", &len, &x);
		for (j=1;j<=n;j++)
		{
			if (code[j]%cf(len)==x)
			{
				printf ("%d\n", code[j]);
				b=false;
				break;
			}
		}
		if (b==true) printf ("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
