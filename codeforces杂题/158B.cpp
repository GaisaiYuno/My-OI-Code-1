#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int n; 
int a[maxn];
int count(int x){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==x) ans++;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int num1,num2,num3,num4;
	int ans=0;
	num1=count(1);
	num2=count(2);
	num3=count(3);
	num4=count(4);
	ans=ans+num4+num2/2+num3;
	if(num3>num1){
		num1=0; 
	}else{
		num1-=num3;
	}
	if(num2%2==1){
		ans++;
		if(num1>2)num1-=2;
		else num1=0;
	}
	ans+=num1/4;
	if(num1%4!=0) ans++;
	printf("%d\n",ans);
}
