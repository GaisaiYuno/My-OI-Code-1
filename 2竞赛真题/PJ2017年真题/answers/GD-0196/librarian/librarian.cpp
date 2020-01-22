#include <bits/stdc++.h>
using namespace std;
struct node{
	long len;
	string s;
};
node book[1010],m;
long n,q;
bool cmp(node a,node b){
	if(a.len==b.len){
		if(a.s<b.s)return true;
		else return false;
	}
	else {
	if(a.len<b.len)return true;
	else return false;
	}
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>book[i].s;
		book[i].len=book[i].s.length();
	}
	sort(book+1,book+n+1,cmp);
	for(int i=1;i<=q;i++){
		cin>>m.len>>m.s;
		int mans=0,mm=0;
		for(int k=1;k<=n;k++){
			mans=0;mm=0;
		    for(int j=1;j<=m.len;j++){
			    if(book[k].s[book[k].len-j]==m.s[m.len-j])mans++;
		    }
		    if(mans==m.len){
		    	mm=1;
		    	cout<<book[k].s<<endl;
		    	break;
		    }
	    }
	    if(mm==0)cout<<"-1"<<endl;
	}
	return 0;
}
