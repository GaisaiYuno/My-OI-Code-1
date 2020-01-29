#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 5005
using namespace std;
int n,m; 
int a[maxn];
int s[maxn];
int top; 
int main(){
	double x;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		scanf("%lf",&x);//然而坐标并没有什么卵用 
	}
	for(int i=1;i<=n;i++){
		if(a[i]>=s[top]) s[++top]=a[i];
		else{
			int tmp=upper_bound(s+1,s+1+top,a[i])-s;
			s[tmp]=a[i]; 
		} 
	}
	printf("%d\n",n-top);
} 
