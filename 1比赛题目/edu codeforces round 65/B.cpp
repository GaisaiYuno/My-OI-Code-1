#include<iostream>
#include<cstdio>
using namespace std;
const int a[7]={0,4,8,15,16,23,42};
int ans[7];
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int ask(int i,int j){
	printf("? %d %d\n",i,j);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
void solve(int ax,int ay,int az){
	int p=ask(ax,ay);
	int q=ask(ax,az);
	for(int i=1;i<=6;i++){
		for(int j=1;j<=6;j++){
			for(int k=1;k<=6;k++){
				if(a[i]*a[j]==p&&a[i]*a[k]==q&&i!=j&&i!=k&&j!=k){
					ans[ax]=a[i];
					ans[ay]=a[j];
					ans[az]=a[k];
				}
			}
		}
	}
}
int main(){
	solve(1,2,3);
	solve(4,5,6);
	printf("! ");
	for(int i=1;i<=6;i++) printf("%d ",ans[i]);
}

