#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
using namespace std;
int n;
int a[maxn];
int b[maxn];
int main(){
//	freopen("paint.in","r",stdin);
//	freopen("paint.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
		b[n-i+1]=a[i];
	}
	
	int ans1=0;
	for(int i=1;i<=n-1;i+=2){
		if(a[i]!=1) ans1++;
		if(a[i+1]!=0) ans1++;
	}
	if(n%2==1&&a[n]==0)	ans1++;
	
	int ans2=0;
	for(int i=1;i<=n-1;i+=2){
		if(a[i]!=0) ans2++; 
		if(a[i+1]!=1) ans2++; 
	}
	if(n%2==1&&a[n]==1) ans2++;
	
	int ans3=0;
	for(int i=1;i<=n-1;i+=2){
		if(b[i]!=1) ans3++;
		if(b[i+1]!=0) ans3++;
	}
	if(n%2==1&&b[n]==0)	ans3++;
	
	int ans4=0;
	for(int i=1;i<=n-1;i+=2){
		if(b[i]!=0) ans4++; 
		if(b[i+1]!=1) ans4++; 
	}
	if(n%2==1&&b[n]==1) ans4++;
	printf("%d\n",min(min(ans1,ans2),min(ans3,ans4)));
}
