#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int n;
int a[maxn]; 
int main(){
	int maxa=0; 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxa=max(maxa,a[i]);
	} 
	int len=0,ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==maxa){
			len++;
			ans=max(ans,len);
		}else len=0;
	}
	printf("%d\n",ans);
}

