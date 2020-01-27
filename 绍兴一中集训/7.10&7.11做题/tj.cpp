#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int t,n,m;
inline int frandom() {
    static int seed=131;
    return seed=int(seed*48271LL%2147483647);
}

int random(int n){
	return frandom()%n;
}
int random(int l,int r){
	return l+frandom()%(r-l+1);
}
int main(){
	srand(time(NULL));
	freopen("1.in","w",stdout);
	t=5;
	n=100000;
	m=100000;
	printf("%d\n",t);
	while(t--){
		cerr<<"ok "<<500-t<<endl;
		printf("%d %d\n",n,m);
		for(int i=1;i<=n;i++) printf("%d ",random(n));
		for(int i=2;i<=n;i++){
			printf("%d ",random(i-1));
		}
		for(int i=1;i<=m;i++){
			printf("%d %d\n",random(n),random(n/3));
		}
	}
	
}
