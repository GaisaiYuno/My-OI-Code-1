#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int book[1001],n,q,ans=0,k,book2[1001],count=1,asd[1001],u;
	bool qwe,qwe2,qwe3=false;
	cin>>n>>q;
	for(int i=0;i<n;++i)
	    cin>>book[i];
	sort(book,book+n);
	for(int i=0;i<n;++i)
	    book2[i]=book[i];
	for(int i=0;i<q;++i)
	    cin>>u>>asd[i];
	for(int i=0;i<q;++i){
		qwe=false;
		for(int j=0;j<n;++j){
			if(asd[i]==book[j]){
			    cout<<book[j]<<endl;
			    qwe=true;
			    break;
			}
		}
		if(qwe==true)continue;
		for(int j=0;j<n;++j){
			count=1;
			qwe2=false;
			while(book2[j]>=asd[i]){
				book2[j]%=100000000/(count*10);
				if(asd[i]==book2[j]){
					cout<<book[j]<<endl;
					qwe2=true;
					break;
				}
				count*=10;
			}
			if(qwe2==true){
				count=1;
			    break;
			}
			if(j==n-1&&qwe2==false)cout<<-1<<endl;
		}
	}
	return 0;
}
