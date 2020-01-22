#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	printf("%d\n",n/10*2+m/10*3+k/10*5);
	return 0;
}
