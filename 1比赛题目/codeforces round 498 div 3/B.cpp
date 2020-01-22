#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2005 
using namespace std;
int n,k;
int a[maxn],b[maxn],duan[maxn],used[maxn];
int bin_search(int x){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]==x) return mid;
		else if(a[mid]>x) r=mid-1;
		else l=mid+1;
	}
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int ans=0;
	for(int i=n;i>=n-k+1;i--){
		int pos=1;
		for(pos=1;pos<=n;pos++){
			if(a[pos]==b[i]&&used[pos]==0){
				used[pos]=1;
				break;
			}
		}
		duan[pos]=1;
		ans+=b[i];
//		printf("%d\n",pos);
	}
	printf("%d\n",ans);
	int last=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(duan[i]==1){
			cnt++;
			if(cnt==k) printf("%d ",n-last+1);
			else{
				printf("%d ",i-last+1);
				last=i+1;
			} 	
		}
	}
} 
