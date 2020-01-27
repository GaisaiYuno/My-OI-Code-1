#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100000
using namespace std;
typedef long long ll;
int n;
int a[maxn*2+5];
int main(){
	scanf("%d",&n);
	if(n%2==0){
		printf("NO\n");
		return 0;
	}else{
		printf("YES\n");
		for(int i=1;i<=n;i++){
			if(i%2==0){
				a[i]=2*n-i+2;
				a[i+n]=a[i]-1;
			}else{
				a[i]=i;
				a[i+n]=a[i]+1;
			}
		}
		for(int i=1;i<=n*2;i++) printf("%d ",a[i]);
	}
	
}

