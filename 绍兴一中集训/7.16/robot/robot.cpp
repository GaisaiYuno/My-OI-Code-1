#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100
using namespace std;
int n;
int a[maxn+5],b[maxn+5];
int p[maxn+5];
int ans=0;
int cal_l(int s){
	int ans=0;
	for(int i=s;i>=1;i--){
		if(p[i]>p[s]||i==1){
			ans=s-i;
			break;
		}
	}
	return ans;
}
int cal_r(int s){
	int ans=0;
	for(int i=s;i<=n;i++){
		if(p[i]>p[s]||i==n){
			ans=i-s;
			break;
		}
	}
	return ans;
}

bool check(){
	for(int i=1;i<=n;i++){
		int l=cal_l(i);
		int r=cal_r(i);
		if(abs(r-l)>2) return 0;
	}
	return 1;
}
void dfs(int deep){
	if(deep>n){
		if(check()) ans++;
		return;
	}
	for(int i=a[deep];i<=b[deep];i++){
		p[deep]=i;
		dfs(deep+1);
	}
}
int main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	dfs(1);
	printf("%d\n",ans);
}
/*
5
3 3
2 2
3 4
2 2
3 3

7
1 7
1 7
1 7
1 7
1 7
1 7
1 7
*/
