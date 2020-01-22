#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
using namespace std;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	string ts[1001],dz;
	long long tr,y=0,zx,i,n,q,size,j,p,o[1001]={0},js,u,k;
	stringstream zh;
	cin>>n>>q;
	for(i=1;i<=n;i++) cin>>ts[i];
	for(i=1;i<=q;i++){
	    cin>>size>>dz;
	    zx=10000001;
	    y=0;
	    for(j=1;j<=n;j++){
	    	if(ts[j].size()<size) continue;
	        js=dz.size()-1;
	        u=0;
	        for(k=ts[j].size()-1;k>=ts[j].size()-size;k--){
	        	if(ts[j][k]!=dz[js]){
	        		u=1;
	        		break;
	        	}
	        	js--;
	        }
	    	if(u==1) continue;
	    	zh<<ts[j];
	    	zh>>tr;
	    	zh.clear();
	    	if(zx>tr){
	    		zx=tr;
	    		y=1;
	    	}
	    }
	    if(y==0)  o[i]=-1;
	    else o[i]=zx;
    }
    for(i=1;i<=q;i++) cout<<o[i]<<endl;
    fclose(stdin);
    fclose(stdout);
}

