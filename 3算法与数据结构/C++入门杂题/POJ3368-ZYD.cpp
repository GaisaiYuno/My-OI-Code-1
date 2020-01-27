#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int Size=200005;
int stmax[Size][31];
int n,m,a[Size];
void init() {
//	memset(stmax,0x80,sizeof(stmax));
//	memset(stmin,0x7f,sizeof(stmin));
	int cnt=1;
	stmax[1][0]=1;
	for(int i=2; i<=n; i++) {
		if(a[i]==a[i-1]) {
			stmax[i][0]=++cnt;
		} else {
			stmax[i][0]=cnt=1;
		}
	}
	for(int j=1; j<=20; j++) {
		for(int i=1<<j; i<=n; i++) {
			stmax[i][j]=max(stmax[i][j-1],stmax[i-(1<<(j-1))][j-1]);
		}
	}
}
int Querymax(int l,int r) {
	int cnt=0,pos=r;
	for(int i=l; i<=r; i++) {
		if(a[i]==a[l]) {
			cnt++;
		} else {
			pos=i;
			break;
		}
	}
	int x=log2(r-pos+1);
	if(pos==r) {
		return cnt;
	} else {
		return max(cnt,max(stmax[r][x],stmax[pos+(1<<x)-1][x]));
	} 
}
int main() {
//	freopen("data.txt","r",stdin);
	int l,r;
	while(scanf("%d",&n)==1 && n) {
		m=read();
		for(int i=1; i<=n; i++)
			a[i]=read();
		init();
		while(m--) {
			l=read();
			r=read();
			printf("%d\n",Querymax(l,r));
		}
	}
	return 0;
}
/*
7 8
2 5 7 12 12 13 17 
5 5
4 6
1 2
1 4
4 6
3 4
3 6
1 6
*/
