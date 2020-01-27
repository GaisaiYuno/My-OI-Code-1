#include<iostream>
#include<cstdio>
#define maxn 105
using namespace std;
int n;
int a[maxn]; 
int main(){	
	int t;
	scanf("%d",&t); 
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==8){
				cnt=i;
				break;
			}
		}
		if(cnt==0) printf("NO\n");
		else if(n-cnt+1>=11) printf("YES\n");
		else printf("NO\n");
	}
}

