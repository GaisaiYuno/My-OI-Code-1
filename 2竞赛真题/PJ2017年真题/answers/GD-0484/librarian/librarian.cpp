#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
string S[10000];
bool Check(string T,string P){
	int Lenp=P.size(),Lent=T.size();
	if(Lent>Lenp)return false;
	for(int i=Lenp-1;i>=Lenp-Lent;i--){
		if(P[i]!=T[i-(Lenp-Lent)])return false;
	}
	return true;
}
bool cmp(const string &Lhs,const string &Rhs){
	if(Lhs.size()!=Rhs.size())return Lhs.size()<Rhs.size();
	int Len=Lhs.size();
	for(int i=0;i<Len;i++){
		if(Lhs[i]!=Rhs[i])return Lhs[i]<Rhs[i];
	}
	return false;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int N,Q;
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++)cin>>S[i];
	for(int i=0;i<Q;i++){
		int Len,Ok=0;
		scanf("%d",&Len);
		string Tmp,TTmp="302394235923";
		cin>>Tmp;
		for(int j=0;j<N;j++){
			if(Check(Tmp,S[j])){
				if(cmp(S[j],TTmp))TTmp=S[j];
				Ok=1;
			}
		}
		if(Ok)cout<<TTmp<<'\n';
		if(!Ok)printf("-1\n");
	}
	return 0;
}
