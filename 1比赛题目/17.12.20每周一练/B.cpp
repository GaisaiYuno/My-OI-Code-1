#include<iostream>
#include<cstring>
#define maxn 105
using namespace std;
int t,n;
char a[maxn][maxn];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,' ',sizeof(a));
		for(int i=1;i<=n;i++){
			a[i][i]=a[i][n-i+1]='X';
	    }
		for(int i=1;i<=n;i++){
			for(int j=1;j<=max(n-i+1,i);j++) cout<<a[i][j];
			cout<<endl;
		}
		cout<<endl;
	}
}
