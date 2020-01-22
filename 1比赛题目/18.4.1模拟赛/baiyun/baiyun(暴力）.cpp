#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500005
using namespace std;
int a[maxn];
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int n,k;
int main(){
	//printf("%.2f MB\n",(double)(sizeof(tree)+sizeof(a))/1024/1024);
	int cmd,q,z,y,i;
	int cnt;
	bool flag;
	n=qread();
	for(int i=1;i<=n;i++) a[i]=qread();
	k=qread();
	while(k--){
		cmd=qread();
		if(cmd==1){
			cnt=0;
			flag=true;
			q=qread();
			z=qread();
			y=qread();
			for(int i=q;i<=z;i++){
				if(a[i]%y!=0) cnt++;
				if(cnt>=2){
					break;
				}
			}
			if(cnt<2) printf("YES\n");
			else printf("NO\n");
		}else{
			i=qread();
			y=qread();
			a[i]=y;
		}
	}
}
