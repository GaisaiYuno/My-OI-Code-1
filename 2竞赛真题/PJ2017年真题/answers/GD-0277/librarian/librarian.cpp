#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;

#define FILE
#ifdef FILE
#define cin is
#define cout os
ifstream is("librarian.in");
ofstream os("librarian.out");
#endif

int n, q;
int book[1005];

int main(){
	int x, y, z;
	int m;
	bool flag=false;
	cin>>n>>q;
	for (int i=0; i<n; i++){
		cin>>book[i];
	}
	sort(book, book+n);
	for (int i=0; i<q; i++){
		cin>>x>>y;
		flag=false;
		for (int j=0; j<n; j++){
			z = (int)(pow(10,x)+0.5);
			m=book[j]%z;
			if (m==y){
				cout<<book[j]<<endl;
				flag=true;
				break;
			}
		}
		if (!flag)cout<<-1<<endl;
	}
	is.close();
	os.close();
	return 0;
}
