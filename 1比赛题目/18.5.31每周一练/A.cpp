#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
using namespace std;
int n;
char a[maxn];
int main() {
	scanf("%d %s",&n,a);
	int len=strlen(a);
	bool flag=true;
	if(len==2) {
		if(a[0]==a[1]) flag=false;
	} else {
		for(int i=0; i<len; i++) {
			if(a[i]=='1') {
				if(i!=0&&i!=n-1&&(a[i-1]=='1'||a[i+1]=='1')) {
					flag=false;
					break;
				}
			} else {
				if((a[i-1]=='0'||i==0)&&(a[i+1]=='0'||i==n-1)) {
					flag=false;
					break;
				}
			}
		}
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
}
