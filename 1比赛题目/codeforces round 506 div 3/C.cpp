#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300005
#define INF 0x7fffffff
using namespace std;
int n;
int l[maxn],r[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&l[i],&r[i]);
	} 
	int maxl,smaxl,minr,sminr; 
	maxl=smaxl=0;
	minr=sminr=INF;
	int posl,posr;
	for(int i=1;i<=n;i++){
		maxl=max(l[i],maxl);
		minr=min(r[i],minr);
		if(maxl==l[i]) posl=i;
		if(minr==r[i]) posr=i;
	}
	for(int i=1;i<=n;i++){
		if(i!=posl) smaxl=max(l[i],smaxl);
		if(i!=posr) sminr=min(r[i],sminr);
	}
	int ansl,ansr;
	ansl=ansr=0;
	for(int i=1;i<=n;i++){
		if(l[i]==ansl) ansl=smaxl;
		else ansl=maxl;
	}
	for(int i=1;i<=n;i++){
		if(r[i]==ansr) ansr=sminr;
		else ansr=minr;
	}
	printf("%d\n",ansr-ansl+1);
}
