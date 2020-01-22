#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int book[1002],length,number,n,q;
int mi_10[]={0,10,100,1000,10000,100000,1000000,10000000,100000000};
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>book[i];
	sort(book,book+n);
	for(int i=0;i<q;i++){
		int ok=1;
		cin>>length>>number;
		for(int j=0;j<n;j++)
			if(book[j]%mi_10[length]==number){
				cout<<book[j]<<endl;ok=0;
				break;
			}
		if(ok)cout<<-1<<endl;
	}
	return 0;
}
