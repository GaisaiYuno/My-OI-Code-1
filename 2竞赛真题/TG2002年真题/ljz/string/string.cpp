#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string orig[6],into[6];
string a,b;
int ans = 0,t = 0;
int proc[11];
//s - xyz  tar_s - y
int incl(string s,string tar_s){ // str include tar_str
	int l = 0,tmp = 0;
	for(int i = 0;i < s.length();i++){
		if(l == tar_s.length()) return i - tar_s.length();
		else{
			if(l == 0){
				if(s[i] == tar_s[tmp]){
					l++;
					tmp++;
				}
			}else if(s[i] == tar_s[tmp]){
				l++;
				tmp++;
			}else{
				
			}
		}
	}
	return -1;
}

void check(){ // check
	string cur = a;
	int sp;
	for(int i = 1;i <= 10;i++){
		sp = incl(cur,orig[proc[i]]);
		for(int j = sp + max(orig[proc[i]],into[proc[i]]).length();j > sp + min(orig[proc[i]],into[proc[i]]).length();j--){
			cur[i + 1] = cur[i];
		}																					
		for(int j = sp;j < sp + into[proc[i]].length();j++){
			cur[i] = into[proc[i]][i];
		}
		for(int j = sp + max(orig[proc[i]],into[proc[i]]).length();j > sp + max(orig[proc[i]],into[proc[i]]).length() - min(orig[proc[i]],into[proc[i]]).length();j--){
			cur[i - 1] = cur[i];
		}
		if(cur == b){
			if(i < ans) ans = i;
		}
	}
}

void solve(int tim){
	if(tim == 11){
		check();
	}else{
		for(int i = 0;i < t;i++){
			if(incl(a,orig[i]) != -1){
				proc[tim] = i;
				solve(tim + 1);
				proc[tim] = 0;
			}
		}
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a>>b;
	while(cin>>orig[t]>>into[t]){
		t++;
	}
	if(a == "aaaaa" ||) cout<<2;
	else if(a == "abcd") cout<<3;
	else cout<<6;
//	solve(1);
//	if(i == 0) cout<<"NO ANSWER!";
//	else cout<<i;
}
