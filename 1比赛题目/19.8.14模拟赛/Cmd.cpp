#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxt 3
#define maxn 5
#define maxv 10
using namespace std;
inline int random(int n){
	return 1ll*rand()*rand()%n+1;
}
inline int random(int l,int r){
	return l+rand()%(r-l+1);
}
int main(){
//	freopen("1.in","w",stdout);
	srand(time(NULL));
	int t=random(2,maxt),n=random(maxn);
	printf("%d\n",t);
	while(t--){
		n=random(maxn);
		printf("%d ",n);
		int k=random(maxn);
		int l=random(n);
		int r=random(n);
		if(l>r) swap(l,r);
		printf("%d %d %d\n",k,l,r);
		for(int i=1;i<=n;i++) printf("%d ",random(maxv));
		printf("\n\n");
	} 

}
