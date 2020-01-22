#include<iostream>
#include<fstream>
using namespace std;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    string a[1005],s;
    long long ans[1005],d=0,w=1;
    fill(ans,ans+2000,-1);
	int n,q,len;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<q;i++){
		cin>>len>>s;
		for(int j=0;j<n;j++){
			int D=0;
			for(int k=len-1;k>=0;k--){
				if(s[s.size()-k]!=a[j][a[j].size()-k]||s.size()>a[j].size()){
					D=1;					
					break;
				}
			}
			if(D==0){
				for(int k=a[j].size()-1;k>=0;k--){
					d+=(a[j][k]-'0')*w;
					w*=10;
				}
				if(ans[i]>d||ans[i]==-1)ans[i]=d;
				d=0,w=1;
			}
		}
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
