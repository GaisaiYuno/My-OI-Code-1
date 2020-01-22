#include<iostream>
#include<cstdio>
#define maxn 200005
using namespace std;
int n;
int a[maxn];
int b[maxn];
int is_hand[maxn];
int pos[maxn];
bool check(){
	int fir=0;
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			fir=i;
			break;
		}
	}
	if(fir==0) return 0;
	for(int i=fir+1;i<=n;i++){
		if(b[i]!=b[i-1]+1) return 0;
	}
	for(int i=b[n]+1;i<=n;i++){
		if(is_hand[i]==0) return 0;
		else is_hand[b[i-b[n]]]=1;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		is_hand[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		pos[b[i]]=i;
	}
	if(check()) printf("%d\n",n-b[n]);
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,pos[i]-i+1);
		}
		printf("%d\n",ans+n);
	}
}

