#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200000 
using namespace std;
int n,m;
char s[maxn+5];
int a[maxn+5]; 
int sum1,sum2;
int cnt1,cnt2;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(i<=n/2){
			if(s[i]=='?') cnt1++;
			else sum1+=s[i]-'0';
		}else{
			if(s[i]=='?') cnt2++;
			else sum2+=s[i]-'0';
		}	
	}
	if(cnt1>cnt2){
		cnt1-=cnt2;//对于左右两半各cnt2个数,后手每次和先手选一样的数 
		cnt2=0; 
	}else{
		cnt2-=cnt1;
		cnt1=0;
	}
	if(cnt1==0){
		swap(cnt1,cnt2);
		swap(sum1,sum2);
	}
	if(sum2-sum1==(cnt1/2)*9) printf("Bicarp\n");//和对手凑9的倍数
	else printf("Monocarp\n"); 
}

