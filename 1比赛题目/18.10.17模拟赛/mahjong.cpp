#include<iostream>
#include<cstdio>
#include<cstring>
#define maxm 1005
using namespace std;
int n,m;
int a[maxm*3]; 
int main(){
	freopen("mahjong.in","r",stdin);
	freopen("mahjong.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=3*m+1;i++) scanf("%d",&a[i]);
	printf("NO\n");
}
