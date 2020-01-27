#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 5
#define maxv 10
using namespace std;
int n;
inline int random(int n){
	return 1ll*rand()*rand()%n+1;
}
int main(){
//	freopen("1.in","w",stdout);
	srand(time(NULL));
	n=maxn;
	printf("%d\n",n);
	for(int i=2;i<=n;i++){
		printf("%d %d %d\n",random(i-1),i,random(maxv));
	}
	for(int i=2;i<=n;i++){
		printf("%d %d\n",random(maxv),random(maxv));
	}
}
