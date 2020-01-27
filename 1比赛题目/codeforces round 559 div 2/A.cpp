#include<iostream>
#include<cstdio>
#define maxn 100005 
using namespace std;
int n;
char a[maxn]; 
int main(){
	int cnt=0,ans=0;
	scanf("%d",&n);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		if(a[i]=='-') cnt++;
		else cnt--;
		ans=max(cnt,ans);
	}
	if(ans<0) ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='+') ans++;
		else ans--;
	} 
	printf("%d\n",ans); 
}

