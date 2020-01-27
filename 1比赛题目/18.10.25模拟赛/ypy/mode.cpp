#include<iostream>
#include<cstdio>
#include<map>
#define maxn 500005
using namespace std;
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
int n;
int a[maxn];
map<int,int>used;
int main(){
	freopen("mode.in","r",stdin);
	freopen("mode.out","w",stdout);
	n=qread();
	for(int i=1;i<=n;i++){
		a[i]=qread();
		used[a[i]]++; 
	}
	for(int i=1;i<=n;i++){
		if(used[a[i]]>n/2){
			printf("%d\n",a[i]);
			break;
		}
	}
	return 0;
}
//For my love Selina
