#include<iostream>
#include<cstdio>
#define maxn 300005
using namespace std;
int n;
char a[maxn]; 
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	bool flag=false;
	int l,r;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			flag=true;
			l=i;
			r=i+1;
			break;
		}
	}
	if(flag){
		printf("YES\n%d %d\n",l,r);
	}else{
		printf("NO\n");
	}
}

