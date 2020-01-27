#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
using namespace std;
int n;
int neq[maxn];
char a[maxn],b[maxn];
int main(){
	scanf("%d",&n);
	scanf("%s %s",a+1,b+1);
	int sz=0;
	int ans=0; 
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			neq[++sz]=i;
		}
	}
	for(int i=1;i<=sz;i++){
		if(i==sz){
			ans++;
			break;
		}
		if(a[neq[i+1]]!=a[neq[i]]&&neq[i+1]-neq[i]==1){
			i++;
			ans++;
		}else{
			ans++;
		}
	}
	printf("%d\n",ans);
}
