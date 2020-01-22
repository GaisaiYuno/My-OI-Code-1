#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,p;
	int c,b,s;
	int a[1005],d[1005];
	cin>>n>>p;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=p;i++){
		s=1;
		cin>>c>>b;
		while (c!=0) {
		  s=s*10;
		  c--;
		}
		for (int j=1;j<=n;j++){
			if (a[j]%s==b) {
				d[i]=a[j];
				break;
			}
			if (j==n) d[i]=-1;
		}
	}
	for (int i=1;i<=p;i++) cout<<d[i]<<endl;
	return 0;
}
