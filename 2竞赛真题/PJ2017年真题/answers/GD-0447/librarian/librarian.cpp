#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
char ch[9];
int n,q,cnt,son[8001][10],f[9],ans=0x7fffffff;
bool co[8001];
int addup(int a,int b,int uz){
	int cnt=0,re=b;
	while(a){
		f[++cnt]=a%10;
		a/=10;
	}
	for(int i=1;i<=uz;i++)f[++cnt]=0;
	for(int i=cnt;i>=1;i--)re=re*10+f[i];
	return re;
}
void insert(int bt,int cur,int len){
	if(!cur){co[bt]=true;return;}
	if(son[bt][ch[cur]-'0'])insert(son[bt][ch[cur]-'0'],cur-1,len);
	else insert(son[bt][ch[cur]-'0']=++cnt,cur-1,len);
}
void search(int bt,int num,int cur,int len,int uz){
	if(cur){
		if(!son[bt][ch[cur]-'0'])return;
		else{search(son[bt][ch[cur]-'0'],!bt?ch[cur]-'0':addup(num,ch[cur]-'0',uz),cur-1,len,ch[cur]=='0'?uz+1:0);return;}
	}else{
		if(co[bt])ans=min(ans,num);
		for(int i=0;i<=9;i++)if(son[bt][i])search(son[bt][i],addup(num,i,uz),0,len,!i?uz+1:0);
	}
}
int main(){
	freopen("librarian.in","rb",stdin);
	freopen("librarian.out","wb",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		int len=strlen(ch+1);
		insert(0,len,len);
	}
	for(int i=1;i<=q;i++){
		ans=0x7fffffff;
		int len;
		scanf("%d%s",&len,ch+1);
		search(0,0,len,len,0);
		printf("%d\n",ans==0x7fffffff?-1:ans);
	}
}
