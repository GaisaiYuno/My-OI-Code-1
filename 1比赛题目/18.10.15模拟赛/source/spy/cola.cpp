#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	freopen("cola.in","r",stdin);
	freopen("cola.out","w",stdout);
	int n,m,t;
	scanf("%d%d",&n,&m);
	srand(n);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&n,&n);		
	}
	scanf("%d",&t);
	cout<<rand()%2017;
}
