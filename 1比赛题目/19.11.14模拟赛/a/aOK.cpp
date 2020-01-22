#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<utility>
#include<algorithm>
#define maxn 40
using namespace std;
typedef long long ll;
int n;
char s[maxn+5];
map< pair<string,string> , ll >vis;
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<(1<<n);i++){
		string l="",r="";
		for(int j=0;j<n;j++){
			if(i&(1<<j)) l.push_back(s[j]);
			else r.push_back(s[j]);
		}
		reverse(r.begin(),r.end());
		vis[make_pair(l,r)]++;
	}
	ll ans=0;
	for(int i=0;i<(1<<n);i++){
		string l="",r="";
		for(int j=0;j<n;j++){
			if(i&(1<<j)) l.push_back(s[j+n]);//push_back(c)±È+c¿ì 
			else r.push_back(s[j+n]);
		}
		reverse(l.begin(),l.end());
//		reverse(r.begin(),r.end());
		ans+=vis[make_pair(l,r)];
	}
	printf("%lld\n",ans);
}
