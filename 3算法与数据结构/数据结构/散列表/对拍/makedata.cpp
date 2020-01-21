#include<iostream>
#include<cstdlib>
#include<ctime> 
#include<map>
#define maxn 100100
using namespace std;
char table[26],in[maxn];
map<char,char>m;
int main(){
	freopen("data.txt","w",stdout); 
	srand(time(NULL)); 
	int t=rand()%100+1;
	cout<<t<<endl;
	while(t--){
		m.clear();
		for(int i=0;i<26;i++)table[i]='a'+i; 
		for(int i=0;i<26;i++)swap(table[rand()%26],table[rand()%26]);
		for(int i=0;i<26;i++){
			 cout<<table[i];
			m[table[i]]='a'+i;
		} 
		cout<<endl;
		int n=rand()%1000;
		int div=rand()%n+1;
		for(int i=0;i<div;i++){
			 in[i]='a'+rand()%26;
		     printf("%c",in[i]);
		} 
		for(int i=div;i<n;i++) printf("%c",m[in[rand()%div]]) ;
		cout<<endl;
	}
}
