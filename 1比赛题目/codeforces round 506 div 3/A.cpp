#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k;
char a[55];
int main() {
	scanf("%d %d",&n,&k);
	scanf("%s",a);
	int len=1;
	for(len=1; len<=n-1;) {
		bool flag=false;
		for(int j=0;j+len<n;j++) {
			if(a[j]!=a[len+j]) {
				flag=true;
				break;
			}
		}
		if(flag) len++;
		else break;
	}
	printf("%s",a);
	for(int i=1;i<k;i++) {
		for(int j=n-len;j<n;j++) {
			printf("%c",a[j]);
		}
	}
}
