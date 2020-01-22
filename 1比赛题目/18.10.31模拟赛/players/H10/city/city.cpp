#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct node{
	int l,r;
}s[1001];
bool cmp(node a,node b){
	return a.l<b.l;
}
int a[10001],n,m,d,val=0,cnt=1;
int ans[2000002];
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d%d",&s[i].l,&s[i].r);
	sort(s+1,s+m+1,cmp);
	for(int i=2;i<=m;i++){//hebing
		if(s[i].l<=s[cnt].r){
			s[cnt].r=max(s[cnt].r,s[i].r);
		}
		else{
			++cnt;
			s[cnt].l=s[i].l;s[cnt].r=s[i].r;
		}
	}
	sort(s+1,s+cnt+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			ans[s[j].l-a[i]+1000001]++;
			ans[s[j].r-a[i]+1+1000001]--;
			//cout<<s[j].l-a[i]+1000001<<" "<<s[j].r-a[i]+1+1000001<<endl;
		}
	}
	for(int i=0;i<=2000001;i++){
		ans[i]+=ans[i-1];//cout<<ans[i]<<endl;
		if(ans[i]>val)val=ans[i],d=abs(1000001-i);
		else if(ans[i]==val)d=min(d,abs(1000001-i));
	}
	cout<<d<<" "<<val; 
}
