#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int h,w,n;
int a,b,c;
int s[maxn],t[maxn];
int main(){
	freopen("football.in","r",stdin);
	freopen("football.out","w",stdout);
	scanf("%d %d",&h,&w);
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&s[i],&t[i]);
	}
	if(n==2){
		int x=abs(s[n]-s[1]);
		int y=abs(s[n]-s[1]);
		printf("%d\n",min(min(c*x+a*y+b,c*y+a*x+b),c*(x+y)));
	}
}
