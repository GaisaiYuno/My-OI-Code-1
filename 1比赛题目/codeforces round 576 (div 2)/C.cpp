#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define INF 0x3f3f3f3f
#define maxn 800000
using namespace std;
int n,m,I;
int a[maxn+5];
int b[maxn+5];
int sum1[maxn+5];

inline int cnt(int l,int r){
	return sum1[r]-sum1[l-1];
}
int check(int lb,int rb){
	int ans1=cnt(1,lb-1);
	int ans2=cnt(rb+1,m);
	int k=rb-lb+1;
//	int cnt=2+sum1[lb+1]+sum1[rb-1];
	if(ceil(log2(k))*n<=I*8) return ans1+ans2;
	else return -1;
}
int bin_search(int t){

	int l=t,r=m;
	int ans=INF;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		int val=check(t,mid);
		if(val!=-1){
			ans=val;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}

int mark[maxn+5];
int main(){
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	scanf("%d",&I);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	for(int i=1;i<=n;i++){
		sum1[a[i]]++;
	}
	for(int i=1;i<=m;i++) sum1[i]+=sum1[i-1];
//	printf("%d\n",m);
	int ans=INF;
	for(int l=1;l<=m;l++){
		int tmp=bin_search(l);
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
}

