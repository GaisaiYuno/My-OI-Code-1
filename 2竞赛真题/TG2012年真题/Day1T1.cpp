#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
using namespace std;
int n,m;
char key[maxn];
char in[maxn];
char out[maxn];
int is_up[maxn];
char to_low(char c){
	return 'a'+c-'A';
}
char to_up(char c){
	return 'A'+c-'a';
} 
char change(char k,char m){
	int x=k-'a';
	int y=m-'a';
	int z=(y-x+26)%26;
	return 'a'+z;
}
int main(){
	scanf("%s",key);
	scanf("%s",in);
	n=strlen(in);
	m=strlen(key);
	for(int i=0;i<m;i++){
		if(key[i]>='A'&&key[i]<='Z'){
			key[i]=to_low(key[i]);
		}
	}
	for(int i=0;i<n;i++){
		if(in[i]>='A'&&in[i]<='Z'){
			in[i]=to_low(in[i]);
			is_up[i]=1;
		}
	} 
	for(int i=0;i<n;i++){
		out[i]=change(key[i%m],in[i]);
	}
	for(int i=0;i<n;i++){
		if(is_up[i]) printf("%c",to_up(out[i]));
		else printf("%c",out[i]); 
	}
} 
