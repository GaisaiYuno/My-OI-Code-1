#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int read()
{
	int x=0,f=1; char c=getchar();
	while (c>'9'||c<'0') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
	return x*f;
}
int n,q,nlen[1100],Min=0,l,k;
bool flag;
char num[1100][20],need[1100][20];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	for (int i=0; i<10; i++) num[0][i]='9';
	n=read(); q=read();
	for (int i=1; i<=n; i++) scanf("%s",num[i]);
	for (int i=1; i<=q; i++) scanf("%d %s",&nlen[i],need[i]);
	for (int i=1; i<=q; i++) {
		Min=0;
		for (int j=1; j<=n; j++) {
			l=strlen(num[j]);
			k=l-nlen[i];
			flag=1;
			for (int p=0; p<nlen[i]; p++)
				if (num[j][k+p]!=need[i][p]) flag=0;
			if (flag) {
				if (strlen(num[Min])>l||strcmp(num[Min],num[j])>0) Min=j;
			}
		}
		if (Min!=0) printf("%s\n",num[Min]); else printf("-1\n");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
