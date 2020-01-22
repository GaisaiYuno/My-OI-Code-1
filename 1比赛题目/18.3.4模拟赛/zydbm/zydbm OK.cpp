#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1005
#define INF 2147483647
#define ForMyLove return 0;
using namespace std;
struct maze{
	int d;
	int w;
	friend bool operator <(maze x,maze y){
		return x.d<y.d;
	}
}a[maxn];
int n,v;
int f[maxn][maxn][2];
int sumw[maxn]; 
inline int fastread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int abs(int x){
	if(x>0) return x;
	else return -x;
}
int countw(int l,int r){
	return sumw[r]-sumw[l-1];
}
int countd(int l,int r){
	return abs(a[l].d-a[r].d);
}
int main(){
	//freopen("zydbm.in","r",stdin);
	//freopen("zydbm.out","w",stdout);
	n=fastread();
	v=fastread();
	for(int i=1;i<=n;i++){
		a[i].d=fastread();
		a[i].w=fastread();
		sumw[i]=sumw[i-1]+a[i].w;
	}
	//sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) f[i][i][0]=f[i][i][1]=abs(a[i].d-a[v].d)*sumw[n];
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n;i++){
			int t=INF;
			int j=i+len-1;
			if(j>n) break;
			t=min(t,f[i+1][j][0]+countd(i,i+1)*(countw(1,i)+countw(j+1,n)));
			t=min(t,f[i][j-1][1]+countd(j-1,j)*(countw(1,i-1)+countw(j,n))+(countd(i,j))*(countw(1,i-1)+countw(j+1,n)));
			f[i][j][0]=t;
			t=INF;
			t=min(t,f[i][j-1][1]+countd(j-1,j)*(countw(j,n)+countw(1,i-1)));
			t=min(t,f[i+1][j][0]+countd(i+1,i)*(countw(1,i)+countw(j+1,n))+(countd(i,j))*(countw(1,i-1)+countw(j+1,n)));
			f[i][j][1]=t;
		}
	}
	int ans=INF;
	ans=min(f[1][n][0],f[1][n][1]);
	cout<<ans<<endl;
	ForMyLove
} 
/*
4
3
2 2
5 8
6 1
8 7
*/
