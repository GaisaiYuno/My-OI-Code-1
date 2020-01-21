#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 30
using namespace std;
string s;
struct node {
	int wpl;
	int sum_f;
	node() {

	}
	node(int pl,int f) {
		wpl=pl;
		sum_f=f;
	}
	friend bool operator <(node a,node b) {
		return a.sum_f>b.sum_f;
	}
};
priority_queue<node>q;
int freq[maxn];
int get_id(char c) {
	if(c>='a'&&c<='z') return c-'a';
	else return 26;
}
int main() {
	int save;
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&save);
		cin>>s;
		memset(freq,0,sizeof(freq));
		while(!q.empty()) q.pop();
		for(int i=0; i<s.length(); i++) {
			freq[get_id(s[i])]++;
		}
		int cnt=0;
		for(int i=0; i<=25; i++) {
			if(freq[i]>0) {
				cnt++;
				q.push(node(0,freq[i]));
			}
		}
		int now;
		if(q.size()==1) {
			now=s.length();
		} else {
			for(int i=1; i<cnt; i++) {
				node a=q.top();
				q.pop();
				node b=q.top();
				q.pop();
				q.push(node(a.wpl+b.wpl+a.sum_f+b.sum_f,a.sum_f+b.sum_f));
			}
			now=q.top().wpl;	
		}
		if(save>=now) printf("yes\n");
	    else printf("no\n");
	}

}
