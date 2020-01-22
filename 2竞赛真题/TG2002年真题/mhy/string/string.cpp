#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int mino;
struct node {
	char word[40];
	int len;
	int step;
};
node s,e;
int ans=0;
int bfs() {
	queue<node>que;
	que.push(s);
	while (!que.empty()) {
		node fa=que.front();
		que.pop();
		for (int i=0; i<fa.len; i++) {
			node ch=fa;
			bool flag=true;
			for (int j=0;j<ch.len;j++){
				if (ch.word[j]!=e.word[j]){
					flag=false;
				}
			}
			if (flag) {
				mino=min(mino,ch.step);
			}
			if (ch.word[i]=='a'&&ch.word[i+1]=='b'&&ch.word[i+2]=='c') {
				ch.len--;
				//cout<<"c"<<endl;
				ch.word[i]='x';
				ch.word[i+1]='u';
				//cout<<"len"<<ch.len<<"i"<<i<<endl;
				for (int j=i+2; j<ch.len; j++) {
					ch.word[j]=ch.word[j+1];
				}
				//ch.word=ch.word.substr(0,ch.len-1);
				//Ç°ÒÆ
				//abcd xucd xud
				
			} else if (ch.word[i]=='u'&&ch.word[i+1]=='d') {
				ch.len--;
				//cout<<"c"<<endl;
				ch.word[i]='y';
				for (int j=i+1; j<ch.len; j++) {
					ch.word[j]=ch.word[j+1];
				}//Ç°ÒÆ
				//ch.word=ch.word.substr(0,ch.len-1);
			} else if (ch.word[i]=='y') {
				ch.len++;
				for (int j=ch.len; j>=i+1; j--) {
					ch.word[j+1]=ch.word[j];
				}//ºóÒÆ
				ch.word[i+1]='z';
			} else {
				continue;
			}
			ch.step++;
			if (ch.step>10) {
				continue;
			}
			//cout<<"pushed "<<ch.word<<endl;
			que.push(ch);
		}
	}
}
int main() {
	freopen("b.in","r",stdin);
	while (true) {
		memset(s.word,0,sizeof(s.word));
		memset(e.word,0,sizeof(e.word));
		if (scanf("%s %s",s.word,e.word)==EOF){
			break;
		}
		mino=100000;
		s.len=strlen(s.word);
		e.len=strlen(e.word);
		s.step=0;
		e.step=0;
		bfs();
		ans+=mino;
	}
	ans++;
	if (ans>10) {
		cout<<"NO ANSWER!"<<endl;
	} else {
		cout<<ans<<endl;
	}
}
