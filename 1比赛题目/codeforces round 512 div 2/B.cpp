#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int n,d;
int m;
struct point{
	int x;
	int y;
}a[maxn];
int is_in(int x,int y){
	if(y>=-x+d&&y<=-x+2*n-d&&y>=x-d&&y<=x+d) return 1;
	else return 0;
}
int main(){
	scanf("%d %d",&n,&d);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=m;i++){
		if(is_in(a[i].x,a[i].y)) printf("YES\n");
		else printf("NO\n");
	}
}
