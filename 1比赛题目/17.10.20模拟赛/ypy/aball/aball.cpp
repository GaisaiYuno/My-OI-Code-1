#include<iostream>
#include<cstdio>
#define maxn 101
using namespace std;
char a[101];
int n,tail;
int main(){
	freopen("aball.in","r",stdin);
	freopen("aball.out","w",stdout);
	cin>>n;
	for(int i=n;i>=1;i--) cin>>a[i];
	tail=n;
	for(int count=0;;count++){
		while(a[tail]=='R') tail--;
		a[tail]='R';
		while(tail<=n){
			tail++;
			a[tail]='B';
		}
		tail-=1;
		bool flag=true;
		for(int j=1;j<=tail;j++) {
			if(a[j]=='R') flag=false;
		}
		if(flag){
			cout<<count;
			return 0;
		}
	}
	return 0;
}
