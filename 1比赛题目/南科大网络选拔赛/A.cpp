#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
using namespace std;
int t,n;
char s[10];
int id[10];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",s+1);
		sort(s+1,s+1+n); 
		for(int i=1;i<=n;i++) id[i]=i;
		do{
			for(int i=1;i<=n;i++) printf("%c",s[id[i]]);
			printf("\n");
		}while(next_permutation(id+1,id+1+n));
	}
}

