#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
#define INF 0x7fffffff
using namespace std;
int n;
long long v[maxn];
int type[maxn];
string s;
int main(){
	scanf("%d",&n);
	long long mina,minb,minc;
	mina=minb=minc=INF;
	for(int i=1;i<=n;i++){
		scanf("%I64d",&v[i]);
		cin>>s;
		for(int j=0;j<s.length();j++){
			if(s[j]=='A') type[i]|=1;
			else if(s[j]=='B') type[i]|=2;
			else if(s[j]=='C') type[i]|=4;
		}
		if(type[i]==1) mina=min(v[i],mina);
		else if(type[i]==2) minb=min(v[i],minb);
		else if(type[i]==4) minc=min(v[i],minc);
	}
	long long ans=INF;
	for(int i=1;i<=n;i++){
		if(type[i]==7) ans=min(ans,v[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if((type[i]|type[j])==7){
				ans=min(ans,v[i]+v[j]);
			}
		} 
	}
	ans=min(ans,mina+minb+minc);
	if(ans>=INF){
		printf("-1\n");
	}else{
		printf("%I64d\n",ans);
	}
} 
