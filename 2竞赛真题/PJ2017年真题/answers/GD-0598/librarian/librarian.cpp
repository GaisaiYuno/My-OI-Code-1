#include <iostream>
#include <fstream>
using namespace std;
int main(){
	int n,q,b[1010],i,j,a[1010],c[1010],bm[1010],s,p,f,k;
	ifstream fin("librarian.in");
	fin>>n>>q;
	for(i=0;i<n;i++) fin>>a[i];
	for(k=0;k<1010;k++) bm[k]=-1;
	for(i=0;i<q;i++){
		fin>>b[i]>>c[i];
		for(j=0;j<n;j++){
			s=0;f=1;
			
			for(p=0;p<b[i];p++){
			    f=f*10;	
		    } 
			if(a[j]%f==c[i]%f){
			      s=a[j];bm[i]=a[j];
			      if(s<bm[i]) bm[i]=s;
			}
		}
	} 
	fin.close();
	
	ofstream fout("librarian.out");
	for(i=0;i<q;i++) fout<<bm[i]<<endl;
	fout.close();
	return 0;
}
