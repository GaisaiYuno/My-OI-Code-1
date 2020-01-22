#include<bits/stdc++.h>
#define zhh 100005
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int 2a=b;a>=c;a--) 
#define ll long long
using namespace std;
string s;
int l,q2,dd=1;
int a1[zhh],b1[zhh];
bool fl[zhh];
int main(){
	cin>>s;
	l=s.length();
	fu(i,0,l-1){
		if(s[i]=='1'){
			q2++;
		}
		if(s[i]=='0'&&fl[dd]==0){
			a1[dd]++;
		}
		if(s[i]=='0'&&fl[dd]==1){
			dd++;
			a1[dd]++;
		}
		if(s[i]=='2'){
			fl[dd]=1;
			b1[dd]++;
		}
	}
	fu(i,1,a1[1]) cout<<0;
	fu(i,1,q2) cout<<1;
	fu(i,1,b1[1]) cout<<2;
	fu(i,2,dd){
//		if(a1[i]==0) break;
		fu(j,1,a1[i]) cout<<0;
		fu(j,1,b1[i]) cout<<2;
	}
	return 0;
}
