//http://119.29.55.79/problem/305 
#include<iostream>
#include<cstdio>
#define maxn 50000
using namespace std;
int n,k; 
#define self(x) (x) //同类域 
#define eat(x) (x+n)//捕食域 
#define enemy(x) ((x)+n+n)//天敌域 

int fa[maxn*3+5];
void ini(int n){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
} 
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}

int is_self(int x,int y){
	if(x>n||y>n) return 0;
	if(find(eat(x))==find(self(y))) return 0;
	if(find(self(x))==find(eat(y))) return 0;
	merge(self(x),self(y));
	merge(eat(x),eat(y));
	merge(enemy(x),enemy(y));
	return 1;
}

int is_eat(int x,int y){
	if(x>n||y>n) return 0;
	if(find(self(x))==find(self(y))) return 0;
	if(find(self(x))==find(eat(y))) return 0;
	merge(eat(x),self(y));
	merge(self(x),enemy(y));
	merge(enemy(x),eat(y));
	return 1;
}

int main(){
	int tp,x,y;
	scanf("%d %d",&n,&k);
	ini(n*3);
	int ans=0;
	for(int i=1;i<=k;i++){
		scanf("%d %d %d",&tp,&x,&y);
		if(tp==1){
			if(is_self(x,y)==0){
				ans++;
//				printf("fake\n");
			}
		}else{
			if(is_eat(x,y)==0){
				ans++;
//				printf("fake\n");
			}
		}
	}
	printf("%d\n",ans);
}

