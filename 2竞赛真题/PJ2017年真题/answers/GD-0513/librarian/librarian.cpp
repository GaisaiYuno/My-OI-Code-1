#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,q,t,len;
int book[1200],v[1200];

int pow(int x){
	int ans=1;
	for(int i=0;i<x;++i){
		ans*=10;
	}
	return ans;
}

int findmin(int l,int x,int n){
	int minn=10000000;
	for(int i=0;i<n;++i){
		if(book[i]%pow(l)==x&&book[i]<minn){
			minn=book[i];
		}
	}
	if(minn==10000000){
		return -1;
	}
	return minn;
}

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;++i){
		cin>>book[i];
	}
	for(int i=0;i<q;++i){
		cin>>len;
		cin>>v[i];
		cout<<findmin(len,v[i],n)<<endl;
	}
	return 0; 
}
