//原文件名为count，后改为excount
#include<iostream>
#include<cstdio>
#define maxn 1005
using namespace std;
int n,x,len;
int ans=0;
int a[maxn]; 
void div(int num){
	int i=1;
	while(num!=0){
		a[i]=num%10;
		num/=10;
		i++;
	}
	len=i-1;
}
int main(){
	//freopen("excount.in","r",stdin);
	//freopen("excount.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
     	div(i);
     	for(int j=1;j<=len;j++){
            if(a[j]==x)    //比较是否相等 
            ans++;
        }
	}
	cout<<ans;
	return 0;
} 
