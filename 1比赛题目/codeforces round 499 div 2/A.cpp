#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#define maxn 55
using namespace std;
int n,m;
char s[maxn];
int a[maxn];
int main() {
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	for(int i=0; i<n; i++) {
		a[s[i]-'a']=1;
	}
	int last=-2;
	int sum=0;
	int cnt=0;
	for(int i=0; i<26; i++) {
		if(a[i]==0) continue;
		else {
			if(i-last>1) {
				cnt++;
//				printf("%c",'a'+i);
				last=i;
				sum+=i+1;
			}
			if(cnt==m) break;
		}
	}
	if(cnt==m)printf("%d\n",sum);
	else printf("-1\n");
}
