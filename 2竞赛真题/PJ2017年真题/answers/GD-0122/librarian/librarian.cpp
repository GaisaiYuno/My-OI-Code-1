#include<iostream>
#include<fstream>
using namespace std;
int hh(int x){
	if(x==1)
	    return 10;
	else return hh(x-1)*10;
}
int main(){
	ifstream fin("librarian.in");
	ofstream fout("librarian.out");
	int n,p,a[1000],c[1000],w[1000],g[1000],i,j,t;
	fin>>n>>p;
	for(i=0;i<p;i++)
	    g[i]=10000000;
	for(i=0;i<n;i++)
	    fin>>a[i];
	for(i=0;i<p;i++){
		t=0;
	    fin>>c[i]>>w[i];
	    for(j=0;j<n;j++){
	        if(a[j]%hh(c[i])==w[i]&&a[j]<g[i]){
	            g[i]=a[j];
	            a[j]=10000001;
	            t++;
	        }
	    }
	    if(t==0)
	        g[i]=-1;
	}
	for(i=0;i<p;i++)
	    fout<<g[i]<<endl;
	return 0;
}
