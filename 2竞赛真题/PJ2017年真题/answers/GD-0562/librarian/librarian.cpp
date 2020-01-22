#include<bits/stdc++.h>
using namespace std;
struct reader{
	int len;
	string code;
}u;
int n,q;
bool flag;
reader temp,t;
vector<reader>a;
vector<reader>::iterator ti;
bool cmp(const reader a,const reader b){return a.code.size()<b.code.size();}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian1.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){ 
	 getline(cin,t.code);
	 a.push_back(t);
	}
	sort(a.begin(),a.end(),cmp);
/*	for(ti=a.begin();ti!=a.end();ti++){
		temp=*ti;
		cout<<temp.code<<'\n';
	}*/
	for(int i=1;i<=q;i++){
		cin>>u.len>>u.code;
		flag=false;
		for(ti=a.begin();ti!=a.end();ti++){
			temp=*ti;
			if(temp.code.find(u.code)!=string::npos&&temp.code.size()>=u.code.size()){
				cout<<temp.code<<'\n';
				flag=true;
				break;
			}
		}
		if(!flag) cout<<-1<<'\n';
	}
}
