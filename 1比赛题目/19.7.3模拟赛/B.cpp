#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50005
#define INF 0x3f3f3f3f
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x*=sign;
}
inline void qprint(long long x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}
int n,tn,m;
int a[maxn+5];
int b[maxn+5];
void discrete(){
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int tn=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+1+tn,a[i])-b;
	} 
}

int cnt1[maxn+5],cnt2[maxn+5];
long long solve(int l1,int r1,int l2,int r2){
	int maxv=0,minv=INF;
	for(int i=l1;i<=r1;i++){
		cnt1[a[i]]++;
		maxv=max(maxv,a[i]); 
		minv=min(minv,a[i]);
	}
	for(int i=l2;i<=r2;i++){
		cnt2[a[i]]++;
		maxv=max(maxv,a[i]);
		minv=min(minv,a[i]);
	}
	long long ans=0;
	for(int i=minv;i<=maxv;i++){
		ans+=(long long)cnt1[i]*cnt2[i];
	}
	for(int i=minv;i<=maxv;i++){
		cnt1[i]=cnt2[i]=0;
	}
	return ans;
}
int main(){
	int l1,r1,l2,r2;
	qread(n);
	for(int i=1;i<=n;i++) qread(a[i]);
//	discrete();
	qread(m);
	for(int i=1;i<=m;i++){
		qread(l1);
		qread(r1);
		qread(l2);
		qread(r2);
		qprint(solve(l1,r1,l2,r2));
		putchar('\n');
	}
}
