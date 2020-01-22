#include<stdio.h>
#include<cstring>
using namespace std;
const int Size=101;
int a[Size];
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
	freopen("jfzp.in","r",stdin);
	freopen("jfzp.out","w",stdout);
	int n=0,avg=0,ans=0;
	n=read();
	for(int i=1; i<=n; i++) {
		a[i]=read();
		avg+=a[i];
	}
	avg/=n;
	int sum=0;
	for(int i=1; i<=n; i++) {
		sum+=a[i]-avg;
		if(sum)	ans++;
	}
	printf("%d",ans);
	return 0;
}
