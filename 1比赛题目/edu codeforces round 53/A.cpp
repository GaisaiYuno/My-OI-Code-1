#include<iostream>
#include<cstdio>
#define maxn 1005
using namespace std;
int n;
char a[maxn];
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	bool flag=false;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			flag=true;
			printf("YES\n%c%c",a[i],a[i+1]);
			break;
		}
	}
	if(!flag) printf("NO\n");
} 
