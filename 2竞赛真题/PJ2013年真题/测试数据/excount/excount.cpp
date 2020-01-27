//原文件名为count，后改为excount
#include<iostream>
#include<cstdio>
using namespace std;
int n,x;
int ans=0;
void judge(int num){
	int tmp=num;
	while(num/10!=num&&num/10!=0){
		num/=10;
		if(tmp-num*10==x) ans++;
	}
	if(num==x) ans++;
}
int main(){
	freopen("excount3.in","r",stdin);
	//freopen("excount.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
     	judge(i);
	}
	cout<<ans;
	return 0;
} 
