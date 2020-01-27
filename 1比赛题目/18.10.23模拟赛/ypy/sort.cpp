//For my love Selina
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 100005
#define maxlog 32
#define INF 0x7f7f7f7f
using namespace std;
inline int qread(){
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
int n;
int a[maxn];
int premax[maxn];
int sufmin[maxn];
int bsort(int l,int r){
	int val=0;
	for(int i=l;i<r;i++){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
			val++;
		}
	}
	premax[l]=a[l];
	for(int i=l+1;i<=r;i++){
		premax[i]=max(premax[i-1],a[i]);
	}
	sufmin[r]=a[r];
	for(int i=r-1;i>=l;i--){
		sufmin[i]=min(sufmin[i+1],a[i]);
	}
	return val;
}

int check(int l,int r){
	for(register int i=l;i<=r;i++){
		if(premax[i]<=sufmin[i+1]){
			return 1;
		}
	}
	return 0;
}

long long ans;
void ssort(int l,int r){//slowsort
	if(r-l+1==1)  return;
	int t;
	do{
		ans=ans+(r-l+1);
		t=bsort(l,r);
		if(t==0) return;
	}while(!check(l,r));
	int last=l;
	for(register int i=l;i<=r;i++){
		if(premax[i]<=sufmin[i+1]){
			ssort(last,i);
			last=i+1;
		}
	}
	if(last<=r)ssort(last,r);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	n=qread();
	for(int i=1;i<=n;i++){
		a[i]=qread();
	}
	ans=0;
	ssort(1,n);
	cout<<ans;
}
