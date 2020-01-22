#include<bits/stdc++.h>
using namespace std;

int n,q,lx;
string x;

struct wxp{
	int px;
	string num;
	void turn(){
		for(int i=0;i<num.length();i++) px=px*10+num[i];
	}
}book[1010];

bool cmp(const wxp &a,const wxp &b){
	return a.px<b.px;
}

void find(){
	for(int i=1;i<=n;i++){
		int p=0,ll=book[i].num.length();
		for(int j=0;j<lx;j++) if(x[j]!=book[i].num[ll-lx+j]) {
			p=1;
			break;
		}
		if(!p) {
			cout<<book[i].num<<"\n";
			return;
		}
	}
	puts("-1");
	return;
}

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>book[i].num,book[i].turn();
	sort(book+1,book+n+1,cmp);
	for(int i=1;i<=q;i++) cin>>lx>>x,find();
}
