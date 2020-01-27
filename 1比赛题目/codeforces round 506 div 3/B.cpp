#include<iostream>
#include<cstdio>
#define maxn 500005
using namespace std;
int n;
long long s[maxn];
int top=0;
int main(){
	scanf("%d",&n);
	long long x;
	int top=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%I64d",&x);
		if(x>s[top]*2){
			top=1;
			s[top]=x;
		}else{
			s[++top]=x;
		}
		ans=max(ans,top);
	}
	printf("%d\n",ans);
}
