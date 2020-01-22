#include<bits/stdc++.h>
using namespace std;
int n,d,k,dis,val,w[100001],sum,upp,st;
bool b[100001];
long long ans,jy[100001];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++){
		cin>>dis>>val;
		if(val>0) sum+=val;
		b[dis]=true;
		w[dis]=val;
		upp=max(upp,dis);
	}
	if(sum<k){
		cout<<"-1";
		return 0;
	}
	for(long long g=0;;g++){
		ans=0;
		for(int i=1;i<=upp;i++){
			if(b[i]){
			   if(g>=d) st=1;
			   else st=d-g;
			   for(int p=st;p<=d+g;p++){
				   if(b[p]){
				   	  jy[i]=max(jy[i],jy[p]+w[i]);
				   }
			   }
			} 
		}
		for(int i=1;i<=upp;i++){
			ans=max(jy[i],ans);
		}
		if(ans>=k){
			cout<<g;
			return 0;
		}
	}
}
