#include<cstdio>
#include<ctime>
#include<cstdlib>
#define N 500
#define M 500
using namespace std;
inline int Rand(int l,int r){return (rand()*32768+rand())%(r-l+1)+l;}
int main(){
	srand(time(0));
	freopen("sort6.in","w",stdout);
	printf("%d %d\n",N,M);
	for(int i=1;i<=N;i++)printf("%d ",Rand(1,1000000000));
	puts("");
	for(int i=1;i<=M;i++)printf("%d\n",Rand(1,N));
}
