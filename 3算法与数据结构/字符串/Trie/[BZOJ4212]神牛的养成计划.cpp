#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm> 
#define maxn 2000
#define maxl 2000000
#define maxs 26
using namespace std;
inline void qread(string &s){
	s.clear();
	char c=getchar();
	while(c<'a'||c>'z') c=getchar();
	while(c>='a'&&c<='z'){
		s.push_back(c);
		c=getchar();
	}
}
int n,m;
string in[maxn+5];

struct Trie {
	char ch[maxl+5][maxs+1];
	int maxt[maxl+5],mint[maxl+5];//�������ַ�������С������� 
	int ptr=0;
	void insert(string &s,int tim) {
		int n=s.length();
		int x=0;
		for(int i=1; i<=n; i++) {
			int c=s[i-1]-'a';
			if(!ch[x][c]) ch[x][c]=++ptr;
			x=ch[x][c];
			mint[x]=min(mint[x],tim);
			maxt[x]=max(maxt[x],tim);
		}
	}
	int query(string &s){
		int n=s.length();
		int x=0;
		for(int i=1; i<=n; i++) {
			int c=s[i-1]-'a';
			if(!ch[x][c]) break; 
			x=ch[x][c];
		}
		return x;
	}
} Tpre;

struct persist_trie{
    int root[maxn+5];
    int sz[maxl+5];
    int ch[maxl+5][maxs];
    int ptr;
    void insert(int pos,int pre,string &s){
        int now=root[pos]=++ptr,last=root[pre];
        int n=s.length();
        for(int i=n;i>=1;i--){//�������,��������ƥ���׺ 
            for(int j=0;j<maxs;j++) ch[now][j]=ch[last][j];
            int c=s[i-1]-'a';
            ch[now][c]=++ptr;
            now=ch[now][c];
            last=ch[last][c];
            sz[now]=sz[last]+1;
        }
    }
    int query(int l,int r,string &s){
        int now=root[r];
        int last=root[l-1];
        int len=s.length();
        for(int i=1;i<=len;i++){
            int c=s[i-1]-'a';
            int cnt=sz[ch[now][c]]-sz[ch[last][c]];
            if(cnt==0) break;
            now=ch[now][c];
            last=ch[last][c];
        }
        return sz[now]-sz[last];
    }
}Tnex;

int main() {
	string s1,s2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) qread(in[i]);
	sort(in+1,in+1+n);
//	printf("------");
	for(int i=1;i<=n;i++){
		cout<<in[i]<<endl;
	}
	for(int i=1;i<=n;i++){
		Tpre.insert(in[i],i);
		//���ַ������ֵ�����������,����һ��ǰ׺��ͬ���ַ����ı���������� 
	}
	for(int i=1;i<=n;i++){
		Tnex.insert(i,i-1,in[i]);//������ƥ���׺ 
	}
	scanf("%d",&m);
	int ans=0;
	for(int i=1;i<=m;i++){
		qread(s1);
		qread(s2);
		for(int i=0;i<(int)s1.length();i++) s1[i]=(s1[i]-'a'+ans)%26+'a';
		for(int i=0;i<(int)s2.length();i++) s2[i]=(s2[i]-'a'+ans)%26+'a'; 
		int x,l,r;
		x=Tpre.query(s1);
		l=Tpre.mint[x],r=Tpre.maxt[x];//��trie���ҳ�����s1ƥ����ַ����ı������ 
		printf("%d\n",Tnex.query(l,r,s2));//�ڿɳ־û�trie�ϵĶ�Ӧ�����ҳ���׺ƥ����� 
	}
}

