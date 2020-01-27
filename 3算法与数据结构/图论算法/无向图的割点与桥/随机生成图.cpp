#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<map>
#include<utility>
#define maxn 5
#define maxm 10
using namespace std;
pair<int,int>e[maxm+5];
map<pair<int,int>,bool>h;
inline int random(int x){
	return (long long)rand()*rand()%x;
}
int main(){
	srand(time(NULL));
	int n=random(maxn)+3;
	int m=random(n*(n-1)/2-n+1)+n-1;
	printf("%d %d\n",n,m);
	for(int i=1;i<n;i++){
		int fa=random(i)+1;
		e[i]=make_pair(fa,i+1);
		h[e[i]]=h[make_pair(i+1,fa)]=1;
	}
	for(int i=n;i<=m;i++){
		int x,y;
		do{
			x=random(n)+1;
			y=random(n)+1;
		}while(x==y||h[make_pair(x,y)]);
		e[i]=make_pair(x,y);
		h[e[i]]=h[make_pair(x,y)]=1;
	}
	random_shuffle(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		printf("%d %d\n",e[i].first,e[i].second);
	}
	int q=rand()%maxn+1;
	printf("%d\n",q);
	for(int i=1;i<=q;i++){
		printf("%d %d\n",rand()%n+1,rand()%n+1);
	}
}

