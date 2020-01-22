#include<iostream>
#include<cstring> 
#include<cstdio>
#define maxn 21
using namespace std;
char s[maxn];
int num[maxn][maxn];//num[i][j]��ʾ[i,j]�ַ���Ӧ���� 
int is_zero[maxn];//��־ 
bool flag=false;
int t;
void to_num(){
	memset(is_zero,0,sizeof(is_zero));
	memset(num,0,sizeof(num));
	int len=strlen(s);
	for(int i=len-1;i>=0;i--){
		if(s[i]=='0'){
			while(i--) is_zero[i]=0;
			break;
		}
		else is_zero[i]=1;
	}
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
			num[i][j]=num[i][j-1]*10+s[j]-'0';
			num[i][j]=min(num[i][j],t+1);
		}
	}
}
void dfs(int pos,int cnt_sign,int last_sign,int mul,int sum,int max_cnt){
	//mul�ǳ˺�ǰ�����������һλ��+,��mul=1
	//sumָĿǰ�ĺͣ���������û�۳���ĳ˻� 
	if(sum>t||cnt_sign>max_cnt||flag) return;
	if(pos==strlen(s)-1){
		if(sum+mul*num[last_sign+1][strlen(s)-1]==t) flag=true;
		else return;
	}
	if(is_zero[pos-1]==1&&sum+mul>t) return;//��֦ 
	dfs(pos+1,cnt_sign+1,pos,1,sum+mul*num[last_sign+1][pos],max_cnt);//+,��ǰ��*��ֵ����� 
	dfs(pos+1,cnt_sign+1,pos,mul*num[last_sign+1][pos],sum,max_cnt);//*
	dfs(pos+1,cnt_sign,last_sign,mul,sum,max_cnt);//���� 
}
int work(){
	int len=strlen(s);
	to_num();
	int ans=-1;
	int l=0,r=len-1;
	while(l<=r){//���ֳ���С������ 
		int mid=(l+r)/2;
		flag=false;
		dfs(0,0,-1,1,0,mid);
		if(flag){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1; 
	}
	return ans;
}
int main(){
	while(cin>>s>>t){
		if(t==-1) break;
		cout<<work()<<endl;
	}
}
/*
032089
5
333
9
00
-1

*/
