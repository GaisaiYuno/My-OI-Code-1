#include<bits/stdc++.h>
using namespace std;
long int n,q,i,j,lg,k,num[1001];
bool flag;
int cf(int o){
	int p=1;
	while (o>0){p*=10;o--;}
	return p;
}
int main(){
	freopen ("librarian.in","r",stdin);
	freopen ("librarian.out","w",stdout);
	cin>>n>>q;
	for (i=1;i<=n;i++)	cin>>num[i];
	sort(num+1,num+n+1);
	for (i=1;i<=q;i++){
		cin>>lg>>k;
		for (j=1;j<=n;j++)
			if (num[j]-(num[j]/cf(lg)*cf(lg))==k){
				cout<<num[j]<<endl;
				flag=true;
				break;
			}
		if (!flag) cout<<-1<<endl;
		flag=false;
	}
	return 0;
}
