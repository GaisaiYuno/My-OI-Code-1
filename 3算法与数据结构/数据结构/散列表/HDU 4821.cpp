#include<iostream>
#include<cstring>
#include<map>
#define maxn 100005
using namespace std;
const int base=131;//2^n-1
unsigned long long hash_value[maxn];
unsigned long long nbase[maxn];
inline unsigned long long get_hash(int start,int len){//BKDRHash算法
	return hash_value[start]-hash_value[start+len]*nbase[len];
} 
map<unsigned long long,int>hashmap;
int m,l;
string s;
int main(){
	nbase[0]=1;
	for(int i=1;i<=maxn-5;i++) nbase[i]=nbase[i-1]*base;
	while(cin>>m>>l){
		cin>>s;
		int ans=0;
		int len=s.length();
		hash_value[len]=0;
		for(int i=len-1;i>=0;i--){
			hash_value[i]=hash_value[i+1]*base+s.at(i);
		} 
		for(int i=0;i<l&&i<=len-m*l;i++){
			hashmap.clear();
			// 将长度为m*l的串，切割为长度为l的m个子串，分别将各个子串的哈希值放入hashmap集合  
			for(int j=i;j<i+m*l;j+=l) hashmap[get_hash(j,l)]++;
			if(hashmap.size()==m) ans++;
			//将最左边那长度l子串的哈希值移出hashmap集合，右边子串的哈希值添加到集合  
			for(int j=i;j<=len-m*l-l;j+=l){
				unsigned long long tmp=get_hash(j,l);
				hashmap[tmp]--;
				if(hashmap[tmp]==0) hashmap.erase(tmp);
				hashmap[get_hash(j+m*l,l)]++;
				if(hashmap.size()==m) ans++; 
			}
		}
		cout<<ans<<endl;
	}
} 
