#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 5005
#define mod 131
using namespace std;
int n,m,k;
int a[maxn];
map<string,int>ma;
string get_hash(int x){
	string s="";
	for(int i=n;i>=0;i--){
		if((1<<i)&x){
			char c='0'+a[n-i];
			s=s+c;
		}
	}
	return s;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d %d\n",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<(1<<n);i++){
		ma[get_hash(i)]=1;
	}
	printf("%d\n",ma.size());
}
