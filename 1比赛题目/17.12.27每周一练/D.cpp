#include<iostream>
#include<cstdio>
#define maxn 10005
using namespace std;
int n,len;
int in[maxn];
int out[maxn];
int main(){
	while(cin>>n){
		len=0;
		for(int i=0;i<n;i++) cin>>in[i]; 
		for(int code='A';code<='Z';code++){
			for(int j=0;j<n;j++){
				int tmp=code^in[j];
				if(tmp>='A'&&tmp<='Z'){
					out[len++]=tmp; 
				}
				else{
					len=0;
					break;
				}
			}
			if(len==n) break;
		}
		for(int i=0;i<n;i++) printf("%c",out[i]);
		cout<<endl;
	}
} 

