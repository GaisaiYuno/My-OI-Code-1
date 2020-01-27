#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,k,s;
int main() {
	scanf("%I64d %I64d %I64d",&n,&k,&s);
	if((n-1)*k<s||k>s) {
		printf("NO\n");
	} else {
		printf("YES\n");
		long long nows=s,nowk=k;
		long long pos=1;
		while(nows-n+1>=nowk-1||(nowk==1&&nows==n-1)) {
			if(pos==1) {
				nowk--;
				nows-=(n-1);
				printf("%I64d ",n);
				pos=n;
			} else {
				nowk--;
				nows-=(n-1);
				printf("%I64d ",1);
				pos=1;
			}
		}
		if(nows==0) return 0;
		if(pos==1) {
			printf("%I64d ",nows-nowk+2);
			pos=nows-nowk+2;
			nowk--;
			if(nowk==0) return 0;
			for(int i=1; i<=nowk; i++) {
				if(i%2==1)printf("%I64d ",pos+1);
				else printf("%d ",pos);
			}
			
		}else{
			printf("%I64d ",n-nows+nowk-1);
			pos=n-nows+nowk-1;
			nowk--;
			if(nowk==0) return 0;
			for(int i=1; i<=nowk; i++) {
				if(i%2==1)printf("%I64d ",pos-1);
				else printf("%I64d ",pos);
			}
		}
	}
}
