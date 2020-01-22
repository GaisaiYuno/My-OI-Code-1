#include<cstdio>
#include<deque>
#include<cstring>
#include<iostream>
#define inf 0x7f7f7f7f
#define N 110000
using namespace std;
inline char gc() {
	static char now[1<<16],*S,*T;
	if(S==T) {
		T=(S=now)+fread(now,1,1<<16,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
inline int read() {
	int x=0,f=1;
	char ch=gc();
	while (ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=gc();
	}
	while (ch<='9'&&ch>='0') {
		x=x*10+ch-'0';
		ch=gc();
	}
	return x*f;
}
struct node {
	int id,value;
};
deque<node> q,q1,q2;
int a[N],L[N],l,s,n,f[N];
int main() {
//  freopen("cf.in","r",stdin);
	cin>>n>>s>>l;
	for (int i=1; i<=n; ++i) cin>>a[i];
	int p=0;
	for (int i=1; i<=n; ++i) {
		while (!q1.empty()&&a[i]+s<q1.front().value) p=q1.front().id+1,q1.pop_front();
		while (!q2.empty()&&a[i]-s>q2.front().value) p=q2.front().id+1,q2.pop_front();
		L[i]=p;
		node tmp;
		tmp.id=i;
		tmp.value=a[i];
		while (!q1.empty()&&a[i]>q1.back().value) q1.pop_back();
		q1.push_back(tmp);
		while (!q2.empty()&&a[i]<q2.back().value) q2.pop_back();
		q2.push_back(tmp);
	}
	memset(f,0x7f,sizeof(f));
	f[0]=0;
	for (int i=l; i<=n; ++i) {
		while (!q.empty()&&q.back().value>f[i-l]) q.pop_back();
		node tmp;
		tmp.value=f[i-l];
		tmp.id=i-l;
		q.push_back(tmp);
		printf("%d %d %d\n",i,q.empty()?1:0,f[i]); 
		while (!q.empty()&&q.front().id<L[i]-1) q.pop_front();
		if (!q.empty()&&q.front().value!=inf) f[i]=q.front().value+1;
	}
	if (f[n]==inf) printf("-1");
	else printf("%d\n",f[n]);
	return 0;
}


