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
int get_id(char c){
	if(c>='A'&&c<='Z') return c-'A';
	else return 26;
}
int main() {
	while(cin>>s) {
		if(s=="END") return 0;
		memset(freq,0,sizeof(freq));
		while(!q.empty()) q.pop();
		int orig=s.length()*8;
		for(int i=0; i<s.length(); i++) {
			freq[get_id(s[i])]++;
		}
		int cnt=0;
		for(int i=0;i<=26;i++){
			if(freq[i]>0){
				cnt++;
				q.push(node(0,freq[i]));
			}
		}
		if(q.size()==1){
			printf("%d %d %.1f\n",orig,orig/8,8.0);
			continue;
		}
		for(int i=1;i<cnt;i++){
			node a=q.top();
			q.pop();
			node b=q.top();
			q.pop();
			q.push(node(a.wpl+b.wpl+a.sum_f+b.sum_f,a.sum_f+b.sum_f));
		}
		int now=q.top().wpl;
		printf("%d %d %.1f\n",orig,now,(double)orig/now);
	}

}
