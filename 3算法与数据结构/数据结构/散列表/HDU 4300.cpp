#include<iostream>
#include<cstring> 
#include<map>
#define maxn 100100
using namespace std;
int t;
char in[maxn];
map<char,char>table;
int main(){
	cin>>t;
	while(t--){
		char ch;
		for(int i=0;i<26;i++){
			cin>>ch;
			table[ch]='a'+i;
		}
		cin>>in;
		int len=strlen(in);
		if(len==1){
			cout<<in[0]<<table[in[0]]<<endl;
			continue;
		}
		int div=len/2-1;
		for(int i=0;i<=div;){
			if(div+i+1>len-1) break;
			if(table[in[i]]!=in[div+i+1]){
				div++;
				i=0;
			}
			else i++;
		}
		for(int i=0;i<=div;i++) cout<<in[i];
		for(int i=0;i<=div;i++) cout<<table[in[i]];
		cout<<endl;
	}
} 
