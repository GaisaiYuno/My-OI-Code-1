#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int p, v;
};
Node a[500005];
int dp[500005];
int n;
int d;
deque<int> f;
int getans(int x){
	int i, j, k;
	int ans=0x80000000;
	int lbound=max(1, d-x), rbound=d+x;
	
	f.clear();
	j=0;
	for(i=1; i<=n; i++){
		while(j<i and a[i].p-a[j].p>=lbound){
			if(!f.empty() and dp[f.front()]<dp[j])
				f.push_front(j);
			else
				f.push_back(j);
			j++;
		}
		while(!f.empty() and a[i].p-a[f.front()].p>rbound)
			f.pop_front();
		if(f.empty())
			return -100000000;
		dp[i]=dp[f.front()]+a[i].v;
		ans=max(ans, dp[i]);
	}
	return ans;
}
int main(){
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout); 
	
	int res;
	int i;
	int k;
	int l=0, r=0;
	int mid;
	int ans;
	
	scanf("%d %d %d", &n, &d, &k);
	for(i=1; i<=n; i++)
		scanf("%d %d", &a[i].p, &a[i].v);
	r=a[n].p;
	
	res=r;
	while(l<r){
		mid=(l+r+1)/2;
		ans=getans(mid);
		if(ans<k)
			l=mid;
		else{
			r=mid-1;
			res=min(res, mid);
		}
	}
	if(getans(res)<k)
		printf("-1");
	else
		printf("%d", res);
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
