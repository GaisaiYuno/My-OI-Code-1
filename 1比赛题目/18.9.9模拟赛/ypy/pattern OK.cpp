#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 20005
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n,k;
const ull seed=1000000007;
ull a[maxn];
ull pows[maxn];
ull hashmap[maxn];
map<ull,int>cnt; 
void BKDR_hash(){
	pows[0]=1;
	for(int i=1;i<=n;i++){
		pows[i]=pows[i-1]*seed; 
	}
	hashmap[0]=0;
	for(int i=1;i<=n;i++){
		hashmap[i]=hashmap[i-1]*seed+a[i];
	}
}
ull get_hash(int l,int r){
	return hashmap[r]-hashmap[l-1]*pows[r-l+1];
} 

int check(int x){
	cnt.clear();
	for(int i=1;i+x-1<=n;i++){
		ull tmp=get_hash(i,i+x-1);
//		cout<<i<<' '<<tmp<<endl;
		cnt[tmp]++;
		if(cnt[tmp]>=k) return 1;
	}
	return 0;
}

int bin_search(){
	int l=0,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	BKDR_hash();
	printf("%d\n",bin_search());
} 
