#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string book[n],reader[q];
	int size[q],flag;
	for (int i=0;i<n;++i) cin>>book[i];
	for (int i=0;i<q;++i) cin>>size[i]>>reader[i];// ‰»Î 
	
	string need;
	
	for (int i=0;i<q;++i){
		need="-1";
		for (int j=0;j<n;++j){
			flag=1;
			for (int k=1;k<=size[i];++k){
				if (book[j][ book[j].size()-k ]  !=
					reader[i][ reader[i].size()-k] ){
					flag=0;
					break;		
				}
			}
			if (flag==1){
				if (need=="-1"){
					need=book[j];
				}
				else {
					if (need.size()>book[j].size()){
						need=book[j];
					}
					if (need.size()==book[j].size()){
						if (need>book[j])
							need=book[j];
					}
				}
			}
		}
		cout<<need<<endl;
	}
	
	return 0;
}
