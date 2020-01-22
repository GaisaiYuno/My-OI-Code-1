#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
using namespace std;
int read(){
	int num=0;
	char ch=getchar();
	int w=1;
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		num=num*10+ch-48;
		ch=getchar();
	}
	return num*w;
}
int m,n;
string input[1000];
int len;
char fin[10];
bool comp(string a,string b){
	if(a.length()<b.length()){
		return true;
	}
	if(a.length()>b.length()){
		return false;
	}
	for(int i=0;i<a.length();i++){
		if(a[i]<b[i])return true;
		if(a[i]>b[i])return false;
	}
	return false;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	m=read();
	n=read();
	for(int i=0;i<m;i++){
		cin>>input[i];
	}
	sort(input,input+m,comp);
	bool flag;
	for(int i=0;i<n;i++){
		len=read();
		for(int u=0;u<len;u++){
			fin[u]=getchar();
		}
		for(int u=0;u<m;u++){
			flag=1;
			for(int j=0;j<len;j++){
				if(fin[j]!=input[u][input[u].length()-len+j]){
					flag=false;
					break;
				}
			}
			if(flag){
				cout<<input[u]<<endl;
				break;
			}
		}
		if(!flag)cout<<-1<<endl;
	}
}
