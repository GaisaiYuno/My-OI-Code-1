//http://119.29.55.79/problem/444
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000 
using namespace std;
typedef long long ll;
int n;
char str[maxn+5];
int a[maxn+5];
int cnt[20];//ÿ�����ֵĸ��� 
ll dp[maxn+5][20];//ѡi��������%11��j�ķ����� 
int tot;//��ǰδȷ�������ĸ��� 
void add(int x){
	cnt[x]++;
	tot++;
	for(int i=tot-1;i>=0;i--){
		for(int j=0;j<=10;j++){
			dp[i+1][(j+x)%11]+=dp[i][j];
		}
	}
}	
void del(int x){
	for(int i=0;i<tot;i++){
		for(int j=0;j<=10;j++){
			dp[i+1][(j+x)%11]-=dp[i][j];
		}
	}
	cnt[x]--;
	tot--;
} 

int main(){
	int sum=0;
	scanf("%s",str+1);
	n=strlen(str+1);
	dp[0][0]=1; 
	for(int i=1;i<=n;i++){
		a[i]=str[i]-'0';
		sum=(sum+a[i])%11;
		add(a[i]);
	}
	if(sum%2==1) sum+=11;//��������һλ 
	int num1=n/2/*ż��λ��Ҫ��ĸ���*/,num2=n-n/2;/*����λ��Ҫ��ĸ���*/
	int sum1=sum/2,sum2=sum/2;
	 for(int i=1;i<=n;i++){
	 	int ans=0;
	 	if(i%2==1){
	 		for(int j=9;j>=0;j--){
	 			if(cnt[j]){
	 				del(j);
	 				if(dp[num2-1][(sum2-j+11)%11]){
	 					ans=j;
	 					break;
					 }
					 add(j);
				 }
			 }
			 num2--;
			 sum2=(sum2-ans+11)%11; 
		 }else{
		 	for(int j=9;j>=0;j--){
	 			if(cnt[j]){
	 				del(j);
	 				if(dp[num1-1][(sum1-j+11)%11]){
	 					ans=j;
	 					break;
					 }
					 add(j);
				 }
			 }
			 num1--;
			 sum1=(sum1-ans+11)%11; 
		 } 
		 putchar(ans+'0');
	 } 
} 
