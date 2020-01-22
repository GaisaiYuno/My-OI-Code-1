#include<bits/stdc++.h>
using namespace std;
int n,q,l,ask,s[1100],k,x;
bool o;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)	cin>>s[i];
	sort(s+1,s+n+1);
	for (int i=1;i<=n;i++){
		scanf("%d",&l);
		scanf("%d",&ask);
		k=1;	x=1;	o=false;
		for (int j=1;j<=l;j++)	x*=10;
		for (int j=1;j<=n;j++){
			if (s[j]%x==ask){
				printf("%d\n",s[j]);
				o=true;
				break;
			}
		}
		if (!o)	printf("-1\n");
	}
	return 0;
}
