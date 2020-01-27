#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 300005
#define M 8000000
int i,j,k,u,v,t,n,m,c,fx,fy,cnt,Year,num,s1,s2;
int root[N],tree[M],sonl[M/2],sonr[M/2],size[M];
bool angry;
char s;

void build(int l,int r,int node){
	if(l==r){tree[node]=l;size[node]=1;return;}
	int mid=(l+r)>>1;
	sonl[node]=++cnt;
	build(l,mid,cnt);
	sonr[node]=++cnt;
	build(mid+1,r,cnt);
}

void change(int l,int r,int x,int k,int w,int node){
	int now=++cnt;
	if(l==r){tree[now]=k;size[now]=w;return;}
	int mid=(l+r)>>1;
	if(x<=mid){
		sonl[now]=cnt+1;
		sonr[now]=sonr[node];
		change(l,mid,x,k,w,sonl[node]);
	}else{
		sonl[now]=sonl[node];
		sonr[now]=cnt+1;
		change(mid+1,r,x,k,w,sonr[node]);
	}
}

void change1(int l,int r,int x,int k,int node){
	if(l==r){size[node]=k;return;}
	int mid=(l+r)>>1;
	if(x<=mid)change1(l,mid,x,k,sonl[node]);
		else change1(mid+1,r,x,k,sonr[node]);
}

int find(int l,int r,int x,int node){
	if(l==r){return tree[node];}
	int mid=(l+r)>>1;
	if(x<=mid) return find(l,mid,x,sonl[node]);
	return find(mid+1,r,x,sonr[node]);
}

int getsize(int l,int r,int x,int node){
	if(l==r){return size[node];}
	int mid=(l+r)>>1;
	if(x<=mid) return getsize(l,mid,x,sonl[node]);
	return getsize(mid+1,r,x,sonr[node]);
}

int get(int x){
	int now=find(1,n,x,root[num]);
	if(now==x)return x;
	return get(now);
}

int fast(){
	int t=0;
	char s=getchar();
	while(s<48||s>57)s=getchar();
	while(s>47&&s<58)t=t*10+s-48,s=getchar();
	return t;
}

int main()
{
	freopen("history.in","r",stdin);
	freopen("history.out","w",stdout);
	n=fast(),m=fast();
	root[0]=++cnt;
	build(1,n,1);
	for(i=1;i<=m;i++){
		s=getchar();
		if(s=='K')c=fast();
		if(s=='R'){
			u=fast(),v=fast();
			if(angry)u=(u+c)%n,v=(v+c)%n;
			u++,v++;num=Year;
			fx=get(u),fy=get(v);
			if(fx==fy){root[++Year]=root[Year-1];continue;}
			root[Year+1]=cnt+1;
			s1=getsize(1,n,fx,root[Year]),s2=getsize(1,n,fy,root[Year]);
			if(s1<s2) change(1,n,fx,fy,s1,root[Year]);
			if(s1>s2) change(1,n,fy,fx,s2,root[Year]);
			if(s1==s2) change(1,n,fx,fy,s1,root[Year]),change1(1,n,fy,s2+1,root[Year]);
			Year++;
		}
		if(s=='T'){
			u=fast(),v=fast(),t=fast();
			u++,v++;num=Year;
			fx=get(u),fy=get(v);
			if(fx!=fy){angry=1;putchar('N'),putchar(10);continue;}
			num=max(Year-t,0);
			if(num>=0){
				fx=get(u),fy=get(v);
				if(fx==fy){angry=1;putchar('N'),putchar(10);continue;}
			}
			angry=0;putchar('Y'),putchar(10);
		}
	}
	return 0;
}
