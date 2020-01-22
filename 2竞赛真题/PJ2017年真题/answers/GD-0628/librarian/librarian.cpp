#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,q,a[1005];
int f(int n){
	int w=1;
	for(int i=1;i<=n;i++)w*=10;
	return w;
}
struct h{
	int s,x;
}b[1005];
int d(int t){
	int e[1005],g=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=b[t].x){
			if(a[i]%b[t].s==b[t].x){
				e[g]=a[i];
				g++;
			}
		}
	}
	if(g==0)return -1;
	sort(e,e+g);
	return e[0];

}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		cin>>b[i].s>>b[i].x;
		b[i].s=f(b[i].s);
	}
	for(int i=1;i<=q;i++)cout<<d(i)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
