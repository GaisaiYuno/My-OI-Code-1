#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define maxn 100005
using namespace std;
char a[maxn];
stack<char>s;
int main(){
	scanf("%s",a+1);
	int n=strlen(a+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!s.empty()&&s.top()==a[i]){
			s.pop();
			cnt++;
		}
		else s.push(a[i]);
	}
	if(cnt%2==1) printf("Yes\n");
	else printf("No\n");
}

