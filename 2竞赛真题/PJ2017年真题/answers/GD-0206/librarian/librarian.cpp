#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,q,bk[1000],num[1000],rd[1000],out[1000],b[1000];
int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>bk[i];
	}
	for(int k=0;k<q;k++){
		cin>>num[k];
		cin>>rd[k];
		out[k]=0;
		b[k]=1;
		for(int i=0;i<num[k];i++){
			b[k]=b[k]*10;
		}
	}
	for(int k=0;k<q;k++){
		for(int i=0;i<n;i++){
			int a=0;
			while(a==0){
				if(bk[i]<rd[k]){
					a=1;
				}else if(((bk[i]-rd[k])%b[k])==0){
					if((out[k]==0) || (out[k]>bk[i]) ){
						out[k]=bk[i];
						a=1;
					}
				}else{
					a=1;
				}
			}
		}
	}
	for(int k=0;k<q;k++){
		if(out[k]==0){
			cout<<-1<<endl;
		}else{
			cout<<out[k]<<endl;
		}
	}
	return 0;
}
