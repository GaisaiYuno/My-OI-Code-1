#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int p10[8]={1,10,100,1000,10000,100000,1000000,10000000};
string a[1001];

void qsort(int x, int y){
	int i=x, j=y;
	string mid=a[(x+y)/2];
	while (i<=j){
		while (a[i].length()<mid.length() || a[i].length()==mid.length() && a[i]<mid) i++;
		while (mid.length()<a[j].length() || mid.length()==a[j].length() && mid<a[j]) j--;
		if (i<=j) swap(a[i++],a[j--]);
	}
	if (x<j) qsort(x, j);
	if (i<y) qsort(i, y);
}

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	int n, q;
	scanf("%d%d",&n,&q);
	for (int i=0; i<n; i++) cin>>a[i];
	qsort(0, n-1);
	for (int i=0; i<q; i++){
		int tl;
		string t, f="-1";
		cin>>tl>>t;
		for (int j=0; j<n; j++)
			if (a[j].length()>=tl && a[j].substr(a[j].length()-tl, tl)==t) {
				f=a[j]; break;
			}
		cout<<f<<endl;
	}
	
	fclose(stdout);
	return 0;
}
