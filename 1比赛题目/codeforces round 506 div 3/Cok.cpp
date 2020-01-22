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
	int posl,posr;
	maxl=smaxl=0;
	minr=sminr=INF;
	for(int i=1;i<=n;i++){
		if(l[i]>maxl) {
			maxl=l[i];
			posl=i;
		}
		if(r[i]<minr) {
			minr=r[i];
			posr=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=posl) smaxl=max(l[i],smaxl);
		if(i!=posr) sminr=min(r[i],sminr);
	}
	int ansl,ansr,ans=0;
	ansl=ansr=0;
	for(int i=1;i<=n;i++){
		if(l[i]==ansl) ansl=smaxl;
		else ansl=maxl;
		if(r[i]==ansr) ansr=sminr;
		else ansr=minr;
		ans=max(ans,ansr-ansl);
	}
	printf("%d\n",ans);
}
