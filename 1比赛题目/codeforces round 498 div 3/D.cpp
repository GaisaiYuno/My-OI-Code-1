#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n;
char a[maxn],b[maxn];
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	int ans=0;
	if(n%2==1&&a[n/2]!=b[n/2]){
		ans++;
	}
	for(int i=1;i<=n-i+1;i++){
		if(b[i]!=b[n-i+1]){
			if(a[i]!=b[n-i+1]&&a[i]!=b[i]) ans++;
			if((a[i]==b[i]||a[n-i+1]!=b[i])&&(a[i]==b[i]||a[n-i+1]!=b[n-i+1]) )ans++;
		}else{
			if(a[i]!=a[n-i+1]) ans++;
			
		}
	}
	printf("%d\n",ans);
}
