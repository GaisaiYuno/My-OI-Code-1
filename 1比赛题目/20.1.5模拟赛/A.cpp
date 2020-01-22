#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cctype>
#include<queue>
#define maxn 26
#define maxl 100000
#define mod 10000

using namespace std;
int n,t;
char tp[maxn+5],lentp;
inline bool isAlpha(char c){
	return c>='A'&&c<='Z';
}
void get_nex(char *s,int n,int *nex) {
	nex[1]=0;
	for(int i=2,j=0; i<=n; i++) {
		while(j&&s[j+1]!=s[i]) j=nex[j];
		if(s[j+1]==s[i]) j++;
		nex[i]=j;
	}
}
int kmp(char *s,int n,char *t,int m) {
	static int nex[maxl+5];
	static int f[maxl+5];
	get_nex(t,m,nex);
	for(int i=1,j=0; i<=n; i++) {
		while(j&&t[j+1]!=s[i]) j=nex[j];
		if(t[j+1]==s[i]) j++;
		f[i]=j;
	}
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(f[i]==m) cnt++;
	}
	return cnt;
}


vector<int>E[maxn+5];
int ind[maxn+5];
void add_edge(int u,int v) {
	E[u].push_back(v);
	ind[v]++;
}
vector<int>seq;
void topo_sort() {
	queue<int>q;
	for(int i=1;i<=26;i++){
		if(!ind[i]) q.push(i);
	}
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		seq.push_back(x);
		for(int i=0; i<(int)E[x].size(); i++) {
			int y=E[x][i];
			ind[y]--;
			if(ind[y]==0) q.push(y);
		}
	}
}

char in[maxl+5];
char a[maxn+5][maxl+5];
int len[maxn+5];

int f[maxn+5];
struct str_tp {
	int l;
	int r;
	int type;
	str_tp() {

	}
	str_tp(int _l,int _r,int _type) {
		l=_l;
		r=_r;
		type=_type;
	}
};
string get_pre(int id,int left,int k) {
	string ans="";
	for(int i=1; i<=len[id]; i++) {
		if(left==0) return ans;
		if(isAlpha(a[id][i])) {
			string tmp=get_pre(a[id][i]-'A'+1,left,k);
			ans+=tmp;
			left-=tmp.length();
			if(left==0) return ans;
		} else {
			ans+=a[id][i];
			left--;
			if(left==0) return ans;
		}
	}
	return ans;
}
string get_suf(int id,int left,int k) {
	string ans="";
	for(int i=len[id]; i>=1; i--) {
		if(left==0) return ans;
		if(isAlpha(a[id][i])) {
			string tmp=get_pre(a[id][i]-'A'+1,left,k);
			ans+=tmp;
			left-=tmp.length();
			if(left==0) return ans;
		} else {
			ans+=a[id][i];
			left--;
			if(left==0) return ans;
		}
	}
	return ans;
}
string get_seg(int l,int r,char *s) {
	string ans="";
	for(int i=l; i<=r; i++) ans+=s[i];
	return ans;
}

void solve(int x) {
	char *s=a[x];
	int le=len[x];
	vector<str_tp>seg;
	static char now[maxl+5];
	int l=1,r=1;
	for(int i=1; i<=le; i++) {
		if(isAlpha(s[i])) seg.push_back(str_tp(i,i,s[i]-'A'+1));
		else {
			if(i==1||isAlpha(s[i-1])) l=i;
			if(i==le||isAlpha(s[i+1])) {
				r=i;
				seg.push_back(str_tp(l,r,0));
			}
		}
	}
	for(int i=0; i<(int)seg.size();i++) {
		if(seg[i].type==0){
			for(int j=seg[i].l;j<=seg[i].r;j++) now[j-seg[i].l+1]=s[j];
			f[x]+=kmp(now,seg[i].r-seg[i].l+1,tp,lentp);
			f[x]%=mod;
		}else{
			 f[x]+=f[s[seg[i].l]-'A'+1];
			 f[x]%=mod;
		}
	}

	for(int i=0; i<(int)seg.size()-1; i++) {
		string p="",q="";
		if(seg[i].type==0) {
			p=get_seg(seg[i].l,seg[i].r,s);
			int cutlen=min(lentp-1,(int)p.length());
			int cutpos=p.length()-cutlen;
			p=p.substr(cutpos,cutlen);
		} else {
			int id=seg[i].type;
			p=get_suf(id,lentp-1,lentp-1);
		}
		if(seg[i+1].type==0) {
			q=get_seg(seg[i+1].l,seg[i+1].r,s);
			int cutlen=min(lentp-1,(int)q.length());
			int cutpos=0;
			q=q.substr(cutpos,cutlen);
		} else {
			int id=seg[i+1].type;
			q=get_pre(id,lentp-1,lentp-1);
		}
		p=p+q;
		for(int i=0; i<(int)p.length(); i++) now[i+1]=p[i];
		int delta=kmp(now,p.length(),tp,lentp);
		f[x]+=delta;
		f[x]%=mod;
	}

}
int main() {
	scanf("%d",&n);
	scanf("%s",in+1);
	t=in[1]-'A'+1;
	for(int i=1; i<=n; i++) {
		scanf("%s",in+1);
		int l=strlen(in+1);
		for(int j=3; j<=l; j++) a[in[1]-'A'+1][j-2]=in[j];
		len[i]=l-2;
		for(int j=3; j<=l; j++) {
			if(isAlpha(in[j])) add_edge(in[j]-'A'+1,in[1]-'A'+1);
		}
	}
	scanf("%s",tp+1);
	lentp=strlen(tp+1); 
	topo_sort();
	for(int i=0; i<(int)seq.size(); i++){
		solve(seq[i]);
	}
	printf("%d\n",f[t]);
}

