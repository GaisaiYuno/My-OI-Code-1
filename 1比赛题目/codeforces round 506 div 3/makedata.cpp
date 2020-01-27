#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<set>
#define maxn 10
#define maxv 100
using namespace std;
int a[maxn+5];
int random(int l,int r){
	int k=rand()%(r-l+1);
//	printf("%d %d\n",k,r-l+1);
	return l+k;
}
set<int>S;
int main(){
	srand(time(NULL));
	int n=rand()%maxn+1;
	printf("%d\n",n);
	while(S.size()!=n){
		S.insert(rand()%maxv+1);
	}
	set<int>::iterator it;
	for(it=S.begin();it!=S.end();it++){
		printf("%d ",*it);
	}
}
