#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 1005
using namespace std;
int n,q,l,code;
int a[maxn];
int mod[9]={0,10,100,1000,10000,100000,1000000,1000000,10000000};
int judge(){
	for(int i=1;i<=n;i++){
		if(a[i]%mod[l]==code) return a[i];
	}
	return -1;
}
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<=q;i++){
		cin>>l>>code;
		cout<<judge()<<endl;
	}
	return 0;
} 
