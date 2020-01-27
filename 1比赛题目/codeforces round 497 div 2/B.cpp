#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
struct node{
	int x;
	int y;
}a[maxn];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	int lasth=a[1].x;
	bool flag1=true;
	for(int i=2;i<=n;i++){
		if(a[i].x>lasth&&a[i].y>lasth){
			flag1=false;
			break;
		}else{
			if(a[i].x<=lasth&&a[i].y<=lasth) lasth=max(a[i].x,a[i].y);
			else if(a[i].x>lasth) lasth=a[i].y;
			else lasth=a[i].x;
		}
	}
	lasth=a[1].y;
	bool flag2=true;
	for(int i=2;i<=n;i++){
		if(a[i].x>lasth&&a[i].y>lasth){
			flag2=false;
			break;
		}else{
			if(a[i].x<=lasth&&a[i].y<=lasth) lasth=max(a[i].x,a[i].y);
			else if(a[i].x>lasth) lasth=a[i].y;
			else lasth=a[i].x;
		}
	}
	if(flag1||flag2) printf("YES\n");
	else printf("NO\n");
}
