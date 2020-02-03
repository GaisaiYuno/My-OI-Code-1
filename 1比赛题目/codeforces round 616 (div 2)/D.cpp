#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200000
using namespace std;
char str[maxn+5];
int n,q;
int sum[26][maxn+5];
int cal_d(int l,int r){
	int ans=0;
	for(int j=0;j<26;j++){
		if(sum[j][r]-sum[j][l-1]>0) ans++;
	}
	return ans;
}
int main(){
	int l,r;
	scanf("%s",str+1);
	n=strlen(str+1);
	scanf("%d",&q);
	for(int i=1;i<=n;i++){
		int c=str[i]-'a';
		for(int j=0;j<26;j++){
			sum[j][i]=sum[j][i-1]+(j==c);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&l,&r);
		int cnt=cal_d(l,r);
		if(cnt>=3) puts("Yes");
		else if(cnt==2){
			if(str[l]==str[r]) puts("No");
			else puts("Yes");
		}else{
			if(l==r) puts("Yes");
			else puts("No"); 
		}
	}
}

