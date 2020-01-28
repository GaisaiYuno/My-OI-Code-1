#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
struct seg{
	int l;
	int r;	
}a[maxn<<1];
int sz=0;
int n,m;
int mid;
void input(int l,int r){
	a[++sz].l=l;
	a[sz].r=r;
	if(l==r||l+1==r) return;
	scanf("%d",&mid);
	input(l,mid);
	input(mid+1,r);
}
int main(){
	scanf("%d %d",&n,&m);

	for(int i=1;i<=sz;i++){
		printf("%d %d\n",a[i].l,a[i].r);	
	}
}
