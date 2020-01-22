#include<bits/stdc++.h>
using namespace std;

int book[2001],read[2001][2];

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>book[i];
	for(int i=1;i<=m;i++) {
		cin>>read[i][0]>>read[i][1];
	}
	sort(book+1,book+n+1);
	for(int i=1;i<=m;i++){
		int pu=1;
		bool flag=false;
		while(read[i][0]){
			pu*=10;
			read[i][0]--;
		}
		for(int j=1;j<=n;j++)if(book[j]%pu==read[i][1]){
			flag=true;
			printf("%d\n",book[j]);
			break;
		}
		if(!flag) printf("-1\n");
	}
	return 0;
}
