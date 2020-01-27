#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 10
#define maxm 100000
#define maxq 100000
#define maxv 1000000000
using namespace std;
typedef long long ll;
inline int random(int n){
	return (ll)rand()*rand()%n+1;
}
inline int random(int l,int r){
	return (ll)rand()*rand()%(r-l+1)+l;
}
int main(){
	freopen("input.txt","w",stdout);
	srand(time(NULL));
	int n=random(maxn);
	int m=random(maxm);
	int q=random(maxq);
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		printf("%d %d\n",random(-maxv,maxv),random(-maxv,maxv));
	} 
	printf("%d\n",m);
	for(int i=1;i<=m;i++){
		printf("%d %d\n",random(-maxv,maxv),random(-maxv,maxv));
	} 
	printf("%d\n",q);
	for(int i=1;i<=q;i++){
		printf("%d %d\n",random(-maxv,maxv),random(-maxv,maxv));
	} 
} 
