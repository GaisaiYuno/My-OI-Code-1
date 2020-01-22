#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int n,q;

struct Book{
	string id;
	int len;
	void input(){
		cin>>id;
		len=id.size();
	}
	bool operator < (const Book &b)const{
		if(len!=b.len)return len<b.len;
		else{
			for(int i=0;i<len;i++){
				if(id[i]!=b.id[i]){
					return id[i]<b.id[i];
				}
			}
		}
		return 0;
	}
}book[1001];

bool check(int len,string s,Book b){
	if(len>b.len)return 0;
	for(int i=len-1,j=b.len-1;i>=0;i--,j--){
		if(s[i]!=b.id[j])return 0;
	}
	return 1;
}

int main(){
//	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		book[i].input();
	}
	sort(book+1,book+n+1);
	for(int i=1;i<=q;i++){
		int len;
		string s;
		bool chx=0;
		cin>>len>>s;
		for(int j=1;j<=n;j++){
			if(check(len,s,book[j])){
				chx=1;
				cout<<book[j].id;
				putchar('\n');
				break;
			}
		}
		if(!chx){
			puts("-1");
		}
	}
	return 0;
}
