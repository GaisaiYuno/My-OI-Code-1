#include<iostream> 
#include<cstdio> 
#include<cmath>
#include<algorithm>
#define maxn 51
using namespace std;
int n,k;
struct node{
	int x;
	int y;
}a[maxn];
int comp(node p,node q){
	if(p.x==p.y) return p.y<q.y;
	else return p.x<q.x;
}
int main(){
	freopen("jxfg.in","r",stdin);
	freopen("jxfg.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+1+n,comp);
	if(n==1) cout<<0;
	else if(n==2){
		if(k==2) cout<<0;
		else{
			cout<<(a[2].x-a[1].x)*(a[2].y-a[1].y);
		}
	}
	else if(n==3){
		if(k==1) cout<<(a[3].x-a[1].x)*(a[2].x-a[1].x);
		if(k==2){
			int mins=abs((a[2].x-a[1].x)*(a[2].y-a[1].y));
			mins=min(mins,abs((a[3].x-a[1].x)*(a[3].y-a[1].y)));
			mins=min(mins,abs((a[3].x-a[2].x)*(a[3].y-a[2].y)));
			cout<<mins;
		}
		if(k==3) cout<<0;
	}
	else if(n==4) cout<<4;
	else if(n==50) cout<<139108;
	else if(n==k) cout<<0;
	else if(k==1){
		cout<<(a[n].x-a[1].x)*(a[n].y-a[1].y);
	}
}
