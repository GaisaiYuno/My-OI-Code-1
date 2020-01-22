#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct yxc{
	string from,to;
}ways[1005];
string start,end;
int num=0;
bool flag=1;
int aa=11;
bool ss(string a,string b){
	for(int i=0;a[i]!=0||b[i]!=0;i++){
		if(a[i]!=b[i])return false;
	}
	return true;
}
void dfs(string str,int lev){
//	for(int i=1;i<=lev;i++)cout<<'\t';
//	cout<<str<<' '<<(int)str[str.length()]<<endl;
	if(ss(str,end)){
		flag=0;
		aa=min(aa,lev);
		return;
	}
	for(int i=1;i<=num;i++){
		for(int j=0;j<=str.length()-ways[i].from.length();j++){
			string a=str;
			bool flag=0;
			for(int k=0;k<ways[i].from.length();k++){
				if(str[j+k]!=ways[i].from[k]){
					flag=1;
					break;
				}
			}
			if(flag)continue;
			if(ways[i].from.length()<ways[i].to.length()){
				for(int q=str.length()-1;q>=j+ways[i].from.length();q--){
					str[q+ways[i].to.length()-ways[i].from.length()]=str[q];
				}
			}
			else if(ways[i].from.length()>ways[i].to.length()){
				for(int q=j+ways[i].from.length();q<=str.length();q++){
					str[q+ways[i].to.length()-ways[i].from.length()]=str[q];
				}
			}
			for(int k=0;k<ways[i].to.length();k++){
				str[j+k]=ways[i].to[k];
			}
			if(lev<10)dfs(str,lev+1); 
			str=a;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>start>>end;
	string a,b;
	while(cin>>a>>b){
		num++;
		ways[num].from=a;
		ways[num].to=b;
	}
	dfs(start,0);
	if(flag)cout<<"NO ANSWER!\n";
	else cout<<aa<<endl;
	return 0;
}
/*
abcd xyz
abc xu
ud y
y yz
*/
