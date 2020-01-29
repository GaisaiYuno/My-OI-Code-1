#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 100005
#define INF 0x7f7f7f7f
using namespace std;
int t,n;
char s[4][maxn];
map<char,int>cnt;
int solve(char *a,int n) {
	cnt.clear();
	for(int i=0; i<n; i++) {
		cnt[a[i]]++;
	}
	map<char,int>::iterator it;
	int ans=0;
	for(it=cnt.begin(); it!=cnt.end(); it++) {
		if(it->second>ans) {
			ans=it->second;
		}
	}
	if(t==1&&ans==n) return min(ans+t,n-1);
	else return min(ans+t,n);
}
int ans[maxn];
int main() {
	scanf("%d",&t);
	for(int i=1; i<=3; i++) {
		scanf("%s",s[i]);
	}
	n=strlen(s[1]);
	int maxv=0,maxp=0,cnt=0;
	for(int i=1; i<=3; i++) {
		ans[i]=solve(s[i],n);
		if(ans[i]>maxv) {
			cnt=1;
			maxv=ans[i];
			maxp=i;
		} else if(ans[i]==maxv){
			cnt++;
		}
	}
	if(cnt>=2){
		printf("Draw\n");
	}
	else {
		if(maxp==1) printf("Kuro\n");
		else if(maxp==2) printf("Shiro\n");
		else printf("Katie\n");
	}
}
