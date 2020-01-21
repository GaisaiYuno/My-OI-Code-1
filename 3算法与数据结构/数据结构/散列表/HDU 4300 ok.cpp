#include<iostream>
#include<cstring>
#include<map>
#include<cstdio>
#define maxn 100010
using namespace std;
char in[maxn];
map<char,char>table;
struct hashtable{ 
    int base;
	unsigned long long nbase[maxn];
	unsigned long long hash_value[maxn];
	void ini(){
		nbase[0]=1;
		for(int i=1;i<maxn;i++) nbase[i]=nbase[i-1]*base;
	}
	unsigned long long get_hash(int l,int r){
		return hash_value[r]-hash_value[l-1]*nbase[r-l+1];
	}
};
hashtable H1,H2; 
int main(){
	int t;
	H1.base=H2.base=131; 
	H1.ini();
	H2.ini();
	cin>>t;
	while(t--){
		char ch;
		table.clear();
		for(int i=0;i<26;i++){
			cin>>ch;
			table[ch]='a'+i;
		}
		scanf("%s",in+1);
		int len=strlen(in+1);
		if(len==1){
			cout<<in[1]<<table[in[1]]<<endl;
			continue;
		}
		H1.hash_value[0]=0;
		H2.hash_value[0]=0;
		for(int i=1;i<=len;i++){
			H1.hash_value[i]=H1.hash_value[i-1]*H1.base+in[i]-'a';//ÃÜÎÄ 
			H2.hash_value[i]=H2.hash_value[i-1]*H2.base+table[in[i]]-'a';//Ã÷ÎÄ 
		}
		int ans=len;
		for(int i=len;i<len*2;i++){
			if(i%2==1) continue;
			int tmp=i/2;
			unsigned long long s1=H2.get_hash(1,len-tmp);
			unsigned long long s2=H1.get_hash(tmp+1,len);
			if(s1==s2){
				ans=tmp;
				break;
			}
		}
		for(int i=1;i<=ans;i++) printf("%c",in[i]);  
        for(int i=1;i<=ans;i++) printf("%c",table[in[i]]); 
        cout<<endl;
	}
} 
