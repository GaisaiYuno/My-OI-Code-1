#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int t,n; 
set<int>s; 
int main(){
	int x;
	scanf("%d",&t);
	while(t--){
		s.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(!s.count(x)){
				printf("%d ",x);
				s.insert(x);
			}
		} 
		printf("\n");
	}
}

