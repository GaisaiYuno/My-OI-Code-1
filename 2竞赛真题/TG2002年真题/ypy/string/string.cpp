#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
struct node {
	string s;
	int step;
};
struct node2{
	string s1;
	string s2;
}change[7];
int cnt=0;
string a,b;
map<string,int>used;
node now,nex;
int bfs() {
	queue<node>q;
	while(!q.empty()) q.pop();
	now.s=a;
	now.step=0;
	q.push(now);
	while(!q.empty()) {
		now=q.front();
		q.pop();
		if(now.step>10) return -1;
		//cout<<now.s<<endl;
		if(now.s==b) return now.step;
		used[now.s]=1;
		for(int c=1;c<=cnt;c++) {
			int lens=now.s.length();
			int lenx=change[c].s1.length();
			int leny=change[c].s2.length();
			for(int i=0; i<lens; i++) {
				if(now.s.substr(i,lenx)==change[c].s1) {
					string t1=now.s.substr(0,i);
					string t2=change[c].s2;
					string t3=now.s.substr(i+lenx,lens-i-lenx);
					nex.s=t1+t2+t3;
					if(used[nex.s]==1) continue;
					nex.step=now.step+1;
					used[nex.s]=1;
					q.push(nex);
					//cout<<now.s<<"   "<<nex.s<<' '<<"step="<<nex.step<<endl;
				}
			}
		}
	}
	return -1;
}
int main() {
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	string u,v;
	cin>>a>>b;
	while(cin>>u>>v) {
		change[++cnt].s1=u;
		change[cnt].s2=v;
	}
	int tmp=bfs();
	if(tmp==-1) cout<<"NO ANSWER!";
	else cout<<tmp;
}
