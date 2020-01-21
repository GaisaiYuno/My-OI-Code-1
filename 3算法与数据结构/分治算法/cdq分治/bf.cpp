#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define maxk 200000
using namespace std;
int n,k;
int sz;
struct node{
	int a;
	int b;
	int c;
	int cnt;
}p[maxn+5];
int ans[maxn+5];
int main(){
//	freopen("3.in","r",stdin);
//	freopen("3.ans","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].c);
	}
	
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=1;j<=n;j++){
			if(i!=j&&p[j].a<=p[i].a&&p[j].b<=p[i].b&&p[j].c<=p[i].c) num++;
		}
		ans[num]++;
	}
	for(int i=0;i<n;i++) printf("%d\n",ans[i]);
}
