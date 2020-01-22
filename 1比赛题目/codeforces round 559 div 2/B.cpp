#include<iostream>
#include<cstdio>
#include<algorithm> 
#define INF 0x3f3f3f3f
#define maxn 300005
using namespace std;
int n;
struct val{
	int v;
	int id;
	friend bool operator < (val p,val q){
		return p.v>q.v;
	} 
}a[maxn]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].v);
		a[i].id=i; 
	}
	sort(a+1,a+1+n); 
	int maxi=0,mini=INF;
	int ans=INF;
	for(int i=1;i<=n;i++){
		if(i>1)ans=min(ans,a[i].v/max(maxi-a[i].id,a[i].id-mini));
		maxi=max(maxi,a[i].id);
		mini=min(mini,a[i].id); 
	}
	printf("%d\n",ans);
}

