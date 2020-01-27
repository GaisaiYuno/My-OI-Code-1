#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define maxn 200005
using namespace std;
int n;
int a[maxn],b[maxn];
int ins[maxn];
stack<int>s;
int work(int x){
	if(!ins[x]) return 0;
	else{
		int y,cnt=0;
		while(!s.empty()){
			y=s.top();
			s.pop();
			cnt++;
			ins[y]=0;
			if(y==x) break;
		}
		return cnt;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	} 
	for(int i=n;i>=1;i--){
		s.push(a[i]);
		ins[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",work(b[i]));
	} 
	
}
