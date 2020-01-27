#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 15
using namespace std;
int n;
int tot;
int a[maxn];
int add[maxn];
bool flag=false;
int cmp(int x,int y){
	return x>y;
}
void print(int *ar,int t) {
	printf("%d",ar[1]);
	for(int i=2; i<=t; i++) printf("+%d",ar[i]);
	printf("\n");
}
void dfs(int sum,int now_pos,int cho_num) {
	if(sum+a[now_pos]==tot) {
		flag=true;
		add[cho_num]=a[now_pos];
		print(add,cho_num);
		return;
	}
	if(sum+a[now_pos]>tot) return;
	add[cho_num]=a[now_pos];
	for(int i=now_pos+1; i<=n; i++) {
		dfs(sum+a[now_pos],i,cho_num+1);
		while(a[i]==a[i+1]&&i+1<=n) i++;
	}

}
int main() {
	while(scanf("%d",&tot)!=EOF&&tot!=0) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		printf("Sums of %d:\n",tot); 
		flag=false;
		for(int i=1;i<=n;i++){
			dfs(0,i,1);
			while(a[i]==a[i+1]&&i+1<=n) i++;
		}
		if(!flag) printf("NONE\n");
	}
}
