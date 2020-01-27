#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200000
using namespace std;
int n,m;
char s[maxn+5];
char t[maxn+5];
int sum[maxn+5][27];

int tmp[maxn+5][27];
bool check(char *s,int len,int mid){
	for(int i=1;i<=26;i++){
		if(sum[mid][i]<tmp[len][i]) return 0;
	}
	return 1;
}
int solve(char *s){
	int len=strlen(s+1);
	for(int i=1;i<=len;i++){
		for(int j=1;j<=26;j++){
			tmp[i][j]=tmp[i-1][j]+(s[i]=='a'+j-1);
		}
	}
	
	int l=1,r=n;
	int ans=n;
	int mid;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(s,len,mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	
//	for(int i=1;i<=len;i++){
//		for(int j=1;j<=26;j++){
//			tmp[i][j]=0;
//		}
//	}
	return ans;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++){
			sum[i][j]=sum[i-1][j]+(s[i]=='a'+j-1);
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",t+1);
		printf("%d\n",solve(t));
	}
}

