#include <iostream>
#include <cstdio>
using namespace std;

int x[501000],s[501000],n;

int solve(int times,int d,int k,int cur_pos,int ans){
	for(int i = 0;i < n;i++){
		if(cur_pos + d == x[n]){
			solve(times,d,k,cur_pos + d,ans += x[n]);
			if(ans >= k) return times;
		}
	}
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int d,k,ans = 0,not_okay = 1,cur_pos = 0,times = 0;
	cin>>n>>d>>k;
	for(int i = 0;i < n;i++) cin>>x[i]>>s[i];
	//At least one point.
	for(int i = 0;i < n;i++){
		if(s[i] > 0) ans += s[i];
	}
	if(ans < k) cout<<-1;
	else{
		while(not_okay){
			solve(times,d,k,cur_pos,ans);
			times++;
			d++;
			cur_pos = 0;
			ans = 0;
		}
	}
	
	return 0;
}
