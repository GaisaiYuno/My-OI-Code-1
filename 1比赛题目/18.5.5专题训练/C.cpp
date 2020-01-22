#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int len[maxn]; 
void init(){
	len[0]=0;
	len[1]=1;
	for(int i=2;i<maxn;i++){
		len[i]=len[i-1]+log10(i)+1;
		//第i个子串比第i-1个子串多一个数i，数字i的长度为log10(i)+1,也就是是说第i个子串比第i-1个子串的长度长log10(i)+1
	}
}
int t,n;
int main(){
	init();
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int i=1;
		while(n>0){
			n-=len[i++];
		}
		i--;
		if(n==0){
			printf("%d\n",i%10);
			continue;
		}
		n+=len[i];
		int tmp=n;
		for(i=1;i<=tmp;i++){
			n-=(int)(log10(i)+1);
			if(n<=0) break;
		} 
		if(n==0){
			printf("%d\n",i%10);
			continue;
		}
		n+=log10(i)+1;
		int digit[20];
		memset(digit,0,sizeof(digit));
		int ptr=0;
		while(i>0){//将i的每一位处理出来 
			digit[ptr++]=i%10;
			i/=10;
		}
		printf("%d\n",digit[ptr-n]);
	}
} 
