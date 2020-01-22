#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
using namespace std;
int n;
char s[maxn];
int ans[maxn];
int get_val(int r,int f) {
	char minv='z'+1;
	char maxv=0;
	int ans=0;
	if(!f) {
		for(int i=1; i<=r; i++) {
			if(s[i]>=maxv){
				maxv=s[i];
				ans=i;
			}
		}
		return ans;
	}else{
		for(int i=1; i<=r; i++) {
			if(s[i]<=minv){
				minv=s[i];
				ans=i;
			}
		}
		return ans;
	}

}
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	int lst=n+1;
	int cnt=0;
	do {
		cnt++;
		lst=get_val(lst-1,cnt%2);
		ans[lst]=1;
	} while(lst>0);
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
}
