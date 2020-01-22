#include<iostream>
#include<cstdio>
using namespace std;

struct tree{
	int l,r,val;
}t[300001];
int tag[1];
void build(int l,int r,int index){
	t[index].l=l;t[index].r=r;
	if(l==r){
		t[index].val=0;return;
	}
	else{
		int mid=(l+r)>>1;
		build(l,mid,index<<1);
		build(mid+1,r,index<<1|1);
	}
}
void pushdown(int index){
	tag[index<<1]=tag[index];
	tag[index<<1|1]=tag[index];
	t[index].val+=tag[index];
	tag[index]=0;
}
void update(int s,int y,int val,int index){
	if(s<=t[index].l&&t[index].r<=y){
		if(tag[index])pushdown(index);
	}
	if(y<t[index].l||t[index].r<s)return;
	update(s,y,val,index<<1);
	update(s,y,val,index<<1|1);
	t[index].val=max(t[index<<1].val,t[index<<1|1].val);
}

int n,k,a[300001],delay[300001];
int main(){
	freopen("bed.in","r",stdin);
	freopen("bed.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[j]+k<a[i]||a[j]-k>a[i]||delay[i-1]==j+1){
				delay[i]=j+1;break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=delay[i];j<=i;j++){
			t[j].val++;
		}
	}
	int ans=0;
	for(int i=1;i<+n;i++){
		ans=max(ans,t[i].val);
	}
	cout<<ans;
}
