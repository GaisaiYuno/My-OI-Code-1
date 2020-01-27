#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10005
using namespace std;
int a,n;
int pow[9][5];
char s[maxn];
inline int fast_pow(int x,int k){
	int ans=1;
	while(k>0){
		if(k&1) ans=(ans*x)%10;
		k>>=1;
		x=(x*x)%10;
	}
	return ans%10;
}
int get_last(char *s){
	int len=strlen(s);
	return (s[len-2]*10)+s[len-1];
}
int main(){
//	freopen("pow.in","r",stdin);
//	freopen("pow.out","w",stdout);
	for(int i=3;i<=8;i++){
		pow[i][0]=1; 
		for(int j=1;j<=4;j++) pow[i][j]=fast_pow(i,j)%10;
	}
//	for(int i=3;i<=9;i++){
//		for(int j=1;j<=4;j++) printf("%d ",pow[i][j]);
//		printf("\n");
//	}
    int ans=0;
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		scanf("%s",s);
		n=get_last(s);
		n%=4;
		if(n==0&&strlen(s)==1&&s[0]=='0') n=0;
		else if(n==0) n=4;
		ans=0;
		for(int i=3;i<=8;i++) ans+=pow[i][n];
		printf("%d\n",ans%10);
	}
	return 0;
}
