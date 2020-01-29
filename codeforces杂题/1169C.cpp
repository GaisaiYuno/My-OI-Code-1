#include<iostream>
#include<cstdio>
#define maxn 300005
using namespace std;
int n,m;
int a[maxn];
int b[maxn];
bool check(int mid){
	for(int i=1;i<=n;i++) b[i]=a[i];
	for(int i=1;i<=n;i++){
		int l=b[i],r=(b[i]+mid)%m;
		if(l>r){
			if(b[i-1]>r&&b[i-1]<l) b[i]=l;
			else b[i]=b[i-1];
		}else{
			if(b[i-1]<l) b[i]=l;
			else{
				if(b[i-1]>r) return 0;
				else b[i]=b[i-1];
			}
		}
	}
	return 1;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);	
	} 
	int l=0,r=m;
	int ans=0;
	int mid;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}else l=mid+1;
	}
	printf("%d\n",ans);
}

