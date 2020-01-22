#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const string convert[10]={"0","0","2","3","322","5","53","7","7222","7332"};
//4!=3!*4=3!*2!*2!
//6!=5!*6=5!*3!
//8!=7!*8=7!*2!*2!*2!
//9!=9*8*7!=3*7!*2!*2!*2!;
string s;
string ans;
int n;
int cmp(char x,char y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	cin>>s;
	ans="";
	for(int i=0;i<n;i++){
		if(s[i]-'0'==0||s[i]-'0'==1) continue;
		ans=ans+convert[s[i]-'0'];
	}
//	cout<<ans<<endl;
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans<<endl;
} 
