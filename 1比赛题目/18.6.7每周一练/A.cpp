#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 1005
#define INF 0x7fffffff
using namespace std;
struct node {
	int score;
	int tim;
	node() {
		score=0;
		tim=0;
	}
};
string name[maxn];
int point[maxn];
map<string,node>ma;
map<string,node>gettim;
int n;
int main() {
	string s;
	int p;
	ma.clear();
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		cin>>name[i];
		scanf("%d",&point[i]);
		ma[name[i]].score+=point[i];
		ma[name[i]].tim=i;
	}
	int maxc=-INF,mint=INF;
	map<string,node>::iterator it;
	for(it=ma.begin(); it!=ma.end(); it++) {
		maxc=max(maxc,it->second.score);
	}
	for(int i=1; i<=n; i++) {
		gettim[name[i]].score+=point[i];
		if(gettim[name[i]].score>=maxc&&ma[name[i]].score>=maxc) {
			cout<<name[i]<<endl;
			break;
		}

	}
}
