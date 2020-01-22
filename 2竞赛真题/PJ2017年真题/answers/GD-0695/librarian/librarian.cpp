#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
		int n,q,qa[1005];
	long long book[1005],qb[1005];
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>book[i];
	sort(book,book+n);
	for(int j=1;j<=q;j++)
	{
		cin>>qa[j]>>qb[j];
	}
	for(int j=1;j<=q;j++)
	{
    int c=-1,sb=1;
	for(int i=1;i<=qa[j];i++) sb*=10;
	int i=1;
	while(i<=n){
		if(book[i]==qb[j])
		{
			cout<<book[i]<<endl;c=0;
		}
			    if(c==0)break;
		if(book[i]-book[i]/sb*sb==qb[j])
		{
			cout<<book[i]<<endl;c=0;
		}
	    if(c==0)break;
	    i++;
	}
	if(c==-1) cout<<c<<endl;
}
	return 0;
}
