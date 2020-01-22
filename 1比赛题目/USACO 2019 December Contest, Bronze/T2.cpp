#include<iostream>
#include<cstdio>
#include<cstring> 
#include<set>
using namespace std;
string s;
set<string>vis;
int n;
int main(){
#ifndef LOCAL
	freopen("whereami.in","r",stdin);
	freopen("whereami.out","w",stdout);
#endif 
	scanf("%d",&n);
	cin>>s;
	for(int len=1;len<=n;len++){
		vis.clear();
		for(int i=0;i+len-1<n;i++){
			vis.insert(s.substr(i,len));
		}
		if((int)vis.size()==n-len+1){
			printf("%d\n",len);
			break;
		}
	}
}

