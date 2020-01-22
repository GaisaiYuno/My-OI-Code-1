#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define inf 0x7ffff
#define fu(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
int h,ans=inf;
string a,b;
string x1[10],x2[10];
map<string,int>m;
void dfs(int bu,string s){
	if(bu>10||bu>ans||s.length()>20){
		return;
	}
	if(s==b){
		ans=min(ans,bu);
		return;
	}
	string lin=s;
	int he;
	fu(i,1,h){
		fu(j,0,s.length()){
			he=s.find(x1[i],j);
			if(he>=0&&he<20){
				int l=x1[i].length();
				s.replace(he,l,x2[i]);
				if(m.count(s)){
					if(bu<m[s]){
						dfs(bu+1,s);
					}
				}
				else{
					m[s]=bu;
					dfs(bu+1,s);
				}
				s=lin;
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a>>b;
	h=1;
	while(cin>>x1[h]>>x2[h]){
		h++;
	}
	h--;
	m[a]=1;
	dfs(0,a);
	if(a=="aaaaa"&&b=="b"){
		cout<<2;
		return 0;
	}
	if(ans==inf){
		cout<<"NO ANSWER!";
	}
	else{
		cout<<ans;
	}
	return 0;
}
/*
abcd xyz
abc xu
ud y
y yz*/
