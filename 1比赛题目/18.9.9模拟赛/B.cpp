#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int cnt=0;
int cha=0;
vector<int>ans;
int main(){
	scanf("%d",&n);
//	printf("%d\n",'c');
	if(n%4==0){
		cha=0;
		cnt=n/2;
		for(int i=1;i<=n/2;i+=2){
			ans.push_back(i);
			ans.push_back(n-i+1);
		}
	}else if(n%4==1){
		cha=1;
		cnt=n/2;
		for(int i=2;i<=n/2+1;i+=2){
			ans.push_back(i);
			ans.push_back(n-i+2);
		}
	}else if(n%4==2){
		cha=1;
		cnt=n/2;
		ans.push_back(1);
		for(int i=3;i<=n/2+1;i+=2){
			ans.push_back(i);
			ans.push_back(n-i+3);
		}
	}else{
		cha=0;
		cnt=n/2;
		ans.push_back(3);
		for(int i=4;i<=n/2+1;i+=2){
			ans.push_back(i);
			ans.push_back(n-i+4);
		}
	}
	printf("%d\n",cha);
	printf("%d ",cnt);
	for(int i=0;i<cnt;i++){
		printf("%d ",ans[i]);
	}
} 
