#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
	int n,q,i,j,k,b[1001],l[1001],du[1001],ans[1001];
	ifstream fin("librarian.in");
	fin>>n>>q;
	for(i=0;i<n;i++) fin>>b[i];
	for(i=0;i<q;i++){
		fin>>l[i]>>du[i];
	}
	for(i=0;i<q;i++){
		k=1;ans[i]=10000001;
		for(j=1;j<=l[i];j++) k=k*10;
		for(j=0;j<n;j++){
			if(du[i]==b[j]%k&&b[j]<ans[i]) ans[i]=b[j];
		}
		if(ans[i]==10000001) ans[i]=-1;
	}
	ofstream fout("librarian.out");
	for(i=0;i<q;i++) fout<<ans[i]<<"\n";
}
