#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#define maxn 500000
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}


int n;
int a[maxn+5];

int main(){
	qread(n);
	for(int i=1;i<=n;i++) qread(a[i]);
	sort(a+1,a+1+n);
	int ptr=0;
	for(int i=2;i<=n;i++){
		if(a[ptr+1]*2<=a[i]) ptr++;
	}
	printf("%d\n",max(n-ptr,n/2+n%2));
}
