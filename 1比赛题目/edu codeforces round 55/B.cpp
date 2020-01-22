#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
char s[maxn];
int pre[maxn];
int duanp[maxn];

int last[maxn];
int duanl[maxn];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='G'){
			pre[i]=pre[i-1]+1;
		}else pre[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(pre[i]!=0&&pre[i-1]==0){
			duanp[i]=duanp[i-1]+1;
		}else duanp[i]=duanp[i-1];
	}
	for(int i=n;i>=1;i--){
		if(s[i]=='G'){
			last[i]=last[i+1]+1;
		}else last[i]=0;
	}
	for(int i=n;i>=0;i--){
		if(last[i]!=0&&last[i+1]==0){
			duanl[i]=duanl[i+1]+1;
		}else duanl[i]=duanl[i+1];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,pre[i]);
	}
	for(int i=1;i<=n;i++){
		if(pre[i]==0){
			if(duanl[i]>0){
				if(duanl[i]>1) ans=max(ans,pre[i-1]+last[i+1]+1);
				else ans=max(ans,pre[i-1]+last[i+1]);
				ans=max(ans,pre[i-1]+1);
			}
		}
	}
	memset(pre,0,sizeof(pre));
	memset(duanl,0,sizeof(duanl));
	memset(last,0,sizeof(last));
	memset(duanp,0,sizeof(duanp));
	reverse(s+1,s+1+n);
	for(int i=1;i<=n;i++){
		if(s[i]=='G'){
			pre[i]=pre[i-1]+1;
		}else pre[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(pre[i]!=0&&pre[i-1]==0){
			duanp[i]=duanp[i-1]+1;
		}else duanp[i]=duanp[i-1];
	}
	for(int i=n;i>=1;i--){
		if(s[i]=='G'){
			last[i]=last[i+1]+1;
		}else last[i]=0;
	}
	for(int i=n;i>=0;i--){
		if(last[i]!=0&&last[i+1]==0){
			duanl[i]=duanl[i+1]+1;
		}else duanl[i]=duanl[i+1];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,pre[i]);
	}
	for(int i=1;i<=n;i++){
		if(pre[i]==0){
			if(duanl[i]>0){
				if(duanl[i]>1) ans=max(ans,pre[i-1]+last[i+1]+1);
				else ans=max(ans,pre[i-1]+last[i+1]);
				ans=max(ans,pre[i-1]+1);
			}
		}
	}
	printf("%d\n",ans);
}
