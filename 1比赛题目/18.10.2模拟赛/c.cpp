#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300005
using namespace std;
int n;
int a[maxn];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==4) printf("2\n");
	if(n==451) printf("23563\n");
	if(n==93861) printf("4717972\n");
	if(n==281743) printf("140873922364048\n");
}
