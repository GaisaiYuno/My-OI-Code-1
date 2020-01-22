#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
ifstream fin("jump.in");
ofstream fout("jump.out");
int l,r,q,n,d,k,x,y,f[500010],a[500010],b[500010];
int main(){
	fin>>n>>d>>k;
	for(int i=0;i<n;i++){
	fin>>a[i]>>b[i];}
	for(int j=0;j<n;j++){
		x+=b[j];
		if(b[j]>=k) y=j;
	}
	for(int o=1;o<y;o++){
		f[o]=a[o]-a[o-1];}
		sort(f+1,f+y);
		if(f[1]<d){ l=d-f[1];}
		if(f[y]<d){ r=d-f[y];}
		if(l<=r){q=r-d;}
		else q=d-l;
		cout<<q;
}
