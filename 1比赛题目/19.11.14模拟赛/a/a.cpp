#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 18
#define maxb 262144
using namespace std;
typedef long long ll;
int n;
char s[maxn+5];
int count(int x){
	int ans=0;
	while(x){
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}
bool check(int x,int y){
	static char sx[maxn+5],sy[maxn+5];
	int sz1=0,sz2=0;
	for(int i=0;i<n*2;i++) if(x&(1<<i)) sx[++sz1]=s[i];
	for(int i=0;i<n*2;i++) if(y&(1<<i)) sy[++sz2]=s[i];
	for(int i=1;i<=sz1;i++) if(sx[i]!=sy[sz1-i+1]) return 0;
	return 1;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s);
	int all=(1<<(n*2))-1;
	int ans=0;
	for(int s=0;s<=all;s++){
		if(count(s)==n){
			if(check(s,all^s)) ans++;
		}
	}
	printf("%d\n",ans);
}
