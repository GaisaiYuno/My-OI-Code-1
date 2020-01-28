#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+10;
int t,n,m;
pair<int,int> a[maxn];
ll ans;

int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		ans=0;
		for(int i=1;i<=n;++i)
			scanf("%d%d",&a[i].first,&a[i].second);
		if(m==n){
			for(int i=1;i<=n;++i)
				if(ans<(ll)a[i].first*a[i].second)
					ans=(ll)a[i].first*a[i].second;
			printf("%lld\n",ans);
			continue;
		}
		priority_queue<int,vector<int>,greater<int> > q;
		sort(a+1,a+n+1);
		for(int i=m+1;i<=n;++i)
			q.push(a[i].second);
		ans=(ll)a[m+1].first*q.top();
		for(int i=m;i;--i){
			q.push(a[i].second);
			q.pop();
			if(ans<(ll)a[i].first*q.top())
				ans=(ll)a[i].first*q.top();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
