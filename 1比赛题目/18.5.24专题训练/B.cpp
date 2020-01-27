#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 15
#define maxc 100000 
using namespace std;
struct cash{
	int money;
	int num;
}a[maxn]; 
int used[maxc+5];
int tot;
int n;
int main(){
	while(scanf("%d %d",&tot,&n)!=EOF){
		for(int i=1;i<=n;i++) scanf("%d %d",&a[i].num,&a[i].money);
		memset(used,0,sizeof(used));
		used[0]=1;
		int maxv,tmp;
		maxv=0;
		for(int i=1;i<=n;i++){
			for(int j=maxv;j>=0;j--){
				if(used[j]==0) continue;
				for(int k=1;k<=a[i].num;k++){
					tmp=k*a[i].money+j;
					if(tmp>tot) continue;
					used[tmp]=1;
					maxv=max(tmp,maxv);
				}
			}
		}
		printf("%d\n",maxv);
	}

}
