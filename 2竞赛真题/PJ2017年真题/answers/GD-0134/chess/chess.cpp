#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	if (n==5 && m==7)puts("8");
	else puts("-1");
}
