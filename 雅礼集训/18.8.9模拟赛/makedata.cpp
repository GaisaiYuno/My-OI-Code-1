#include<bits/stdc++.h>
#define maxn 5
#define maxm 5
#define maxq 5 
using namespace std;
int main(){
	srand(time(NULL));
	int n=rand()%maxn+1; 
	int m=rand()%maxm+1;
	int q=rand()%maxq+1;
	printf("%d %d %d\n",n,m,q); 
	for(int i=2;i<=n;i++){
		printf("%d %d\n",rand()%(i-1)+1,i);
	} 
	for(int i=1;i<=q;i++){
		printf("%d %d\n",rand()%n+1,rand()%q+1);
	}
	return 0;
}

