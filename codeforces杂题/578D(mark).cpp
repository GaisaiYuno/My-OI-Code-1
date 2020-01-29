#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int n,m;
long long ans=0;
char s[maxn];
int main() {
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	ans=n*(m-1);//n-1个字符保持原位，另一位任意插除了原来字符的其他字符
	for(int i=1; i<n; i++) {
		if(s[i]!=s[i+1]) ans+=n*(m-1);
		//将一个字符挪到另一个位置，如果碰到aaa这种相同的情况，只算一次（插到1,2,3后面都一样）
		//所以最多和m-1个字符
	}
	//像abababab这样的串
	//把第3个a放到后面变成abbaabab，但是把第4个b放到前面也可以变成abbaabab
	//这种字符串中每个字符会与前面任意一个字符算重一次
	int k=1;
	for(int i=2; i<=n; i++) {
		if(k==1) {
			if(s[i]!=s[i-1]) k++;
			else continue;
		} else {
			if(s[i]==s[i-2]) k++;
			else {
				ans-=(k-1)*k/2;
				k=1;
				if(s[i]!=s[i-1]) k=2;
			}
		}
	}
	ans-=(k-1)*k/2;
	cout<<ans;
}
