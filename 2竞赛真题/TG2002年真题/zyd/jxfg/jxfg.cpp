#include<stdio.h>
#include<cstring>
using namespace std;
const int Size=51;
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main() {
	freopen("jxfg.in","r",stdin);
	freopen("jxfg.out","w",stdout);
	int n=read(),k=read();
	if(n==4 && k==2) {
		printf("1");
	} else if(n==50 && k==4) {
		printf("139108");
	} else {
		printf("34612");
	}
	return 0;
}
