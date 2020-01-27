#include<iostream>
#include<cstdio> 
#include<cstring>
#include<map>
#define maxn 5000000
#define base 4
#define mod 1000000007
#define maxv 1048575
using namespace std;
int n,k;
char s[maxn+5];
int vis[maxv+5];
int id[35];
int main(){
#ifndef LOCAL
	freopen("ueana.in","r",stdin);
	freopen("ueana.out","w",stdout);
#endif
	scanf("%s",s+1);
	scanf("%d",&k);
	n=strlen(s+1);
	id['A'-'A']=0;
	id['C'-'A']=1;
	id['G'-'A']=2;
	id['T'-'A']=3;
	for(register int i=1;i+k-1<=n;i++){
		register int l=i,r=i+k-1;
		register int hs=0;
		for(register int j=l;j<=r;j++){
			hs=hs*base+id[s[j]-'A'];
		}
		vis[hs]++;
//		printf("%d\n",hs);
	}
	int ans=0;
	for(register int i=0;i<=maxv;i++){
		if(vis[i]>ans){
			ans=vis[i];
		}
	} 
	printf("%d\n",ans);
}
