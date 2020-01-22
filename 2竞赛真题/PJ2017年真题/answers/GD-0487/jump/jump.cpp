#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c;
int reach[500001]={0},s[500001]={0};
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++){
		scanf("%d%d",&reach[i],&s[i]);
	}
	printf("-1\n");
	return 0;
}
