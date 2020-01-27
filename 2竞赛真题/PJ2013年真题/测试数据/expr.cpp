//expr
#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
string a;
int num[maxn];
int used[maxn];
int sign[maxn];
int ans=0;
int len,cnt_num,cnt_sign,wei;
int main() {
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>a;
	len=a.length();
	cnt_num=0;
	cnt_sign=0;
	wei=1;
	for(int i=len-1; i>=0; i--) {
		if(a[i]>='0'&&a[i]<='9') {
			num[cnt_num++]=(a[i]-'0')*wei;
			wei*=10;
		} else {
			wei=1;
			if(a[i]=='+') sign[cnt_sign++]=-1;
			else sign[cnt_sign++]=cnt_num;
		}
	}
	
	for(int i=cnt_sign-1; i>=0; i--) {
		if(sign[i]!=-1) {
			ans=(ans+num[sign[i]]*num[sign[i]-1])%10000;//只输出后四位 
			used[sign[i]]=1;
			used[sign[i]-1]=1;
		}
	}
	
	for(int i=cnt_num-1; i>=0; i--) {
		if(used[i]==0) ans=(ans+num[i])%10000;
	}
	cout<<ans;
	return 0;
}
