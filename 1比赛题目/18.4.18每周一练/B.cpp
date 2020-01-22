#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int a[maxn],b[maxn];
int n,m;
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==1&&m==0){
			printf("0 0\n");
			return 0;
		}
		if(m==0||m>n*9){
			printf("-1 -1\n");
			return 0; 
		}else{
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			int now=m;
			for(int i=1;i<=n;i++){
				if(now<9) a[i]=now;
				else a[i]=9;
				now-=a[i];
			}
			now=m-1;
			b[1]=1;//确保第一位不为0 
			for(int i=n;i>1;i--){
				if(now<9) b[i]=now;
				else b[i]=9;
				now-=b[i];
			}
		    b[1]+=now;
			for(int i=1;i<=n;i++) printf("%d",b[i]);
			printf(" ");
			for(int i=1;i<=n;i++) printf("%d",a[i]); 
			printf("\n");
		}
	}
}
