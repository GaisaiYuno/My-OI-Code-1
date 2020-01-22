#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 10005
#define maxm 1000005
#define ss 1000000
using namespace std;
void read(int &x){
	int f=1;x=0;
	char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}
int abs(int x){
	return x<0?-x:x;
}
int A[maxn];
int s1[maxm];
struct node{
	int l,r;
	node(){l=r=0;}
	node(int a,int b){l=a,r=b;}
} B[maxm];
int s2[maxm*2];
int cnt=0;
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	int n,m;
	read(n),read(m);
	for(int i=1;i<=n;i++) read(A[i]);
	for(int i=1;i<=m;i++){
		int a,b;
		read(a),read(b);
		s1[a]++,s1[b+1]--;
	}
	for(int i=1;i<=ss;i++) s1[i]+=s1[i-1];
	for(int i=0;i<=ss;i++) s1[i]=min(1,s1[i]);
	if(s1[0]) B[++cnt].l=0;
	if(s1[0]&&!s1[1]) B[cnt].r=0;
	for(int i=1;i<=ss;i++){
		if(!s1[i-1]&&s1[i]) B[++cnt].l=i;
		if(s1[i]&&!s1[i+1]) B[cnt].r=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			s2[B[j].l-A[i]+ss]++;
			s2[B[j].r-A[i]+1+ss]--;
		}
	}
	for(int i=1;i<=ss*2;i++) s2[i]+=s2[i-1];
	int d=0,s=0;
	for(int i=0;i<=ss*2;i++){
		if(s<s2[i]) s=s2[i],d=abs(i-ss);
		if(s==s2[i]) d=min(d,abs(i-ss));
	}
	printf("%d %d\n",d,s);
}
