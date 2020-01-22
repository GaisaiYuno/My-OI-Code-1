#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int i,j,n,q,len,y,l,l1,bf,dx,pd;
int a[1031];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
	  cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=q;i++){
		cin>>len>>pd;
		y=0;
	    for(j=1;j<=n;j++){
	    	dx=1;
	    	for(l=1;l<=len;l++)
	    	  dx*=10;
	    	bf=a[j]%dx;
	    	if(bf==pd){
	    		y=1;
	    		cout<<a[j]<<endl;
	    		j=n+1;
	        }
	    }
	    if(y==0)
	      cout<<-1<<endl;
	}
	return 0;
}
