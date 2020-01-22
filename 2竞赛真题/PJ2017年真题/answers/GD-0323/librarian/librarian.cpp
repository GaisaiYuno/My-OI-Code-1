#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
const int maxn=1010;
int book[maxn];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>book[i];
	}
	sort(book+1,book+1+n);
	for(int i=1;i<=q;++i){
		int len,t;
		cin>>len>>t;
		int mod=1;
		int j;
		for(j=1;j<=len;++j)mod*=10;
		for(j=1;j<=n;++j){
			if(book[j]%mod==t){
				cout<<book[j]<<endl;
				break;
			}
		}
		if(j==n+1){
			cout<<-1<<endl;
		}
	}
	return 0;
}
