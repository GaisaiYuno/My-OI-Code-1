#pragma GCC optimize(3) 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 7000000  
#define maxc 52
using namespace std;
typedef long long ll;

static int to[maxn+5];
static char ch[maxn+5];
static int nex[maxn+5];
int esz;
static int head[maxn+5];
#define max(a,b) (a)>(b)?(a):(b)
static int cnt[maxn+5];
int ptr;

ll ans=0;
void insert(){
	register int x=0;
	register char c=getchar();
	while(c=='\n') c=getchar();
	register int i; 
	for(i=1;c!='\n';){
		register bool flag=0;
		for(register int j=head[x];j;j=nex[j]){
			if(ch[j]==c){
				x=to[j];
				flag=1;
				break;
			}
		}
		if(!flag){
			ptr++;
			esz++;
			to[esz]=ptr;
			ch[esz]=c;
			nex[esz]=head[x];
			head[x]=esz;
			x=ptr;
		}
		cnt[x]++;
		ans=max(ans,1ll*cnt[x]*i);
		c=getchar();
		i++;
		
		if(c=='\n') break;
		flag=0;
		for(register int j=head[x];j;j=nex[j]){
			if(ch[j]==c){
				x=to[j];
				flag=1;
				break;
			}
		}
		if(!flag){
			ptr++;
			esz++;
			to[esz]=ptr;
			ch[esz]=c;
			nex[esz]=head[x];
			head[x]=esz;
			x=ptr;
		}
		cnt[x]++;
		ans=max(ans,1ll*cnt[x]*i);
		c=getchar(); 
		i++; 
		
		if(c=='\n') break;
		flag=0;
		for(register int j=head[x];j;j=nex[j]){
			if(ch[j]==c){
				x=to[j];
				flag=1;
				break;
			}
		}
		if(!flag){
			ptr++;
			esz++;
			to[esz]=ptr;
			ch[esz]=c;
			nex[esz]=head[x];
			head[x]=esz;
			x=ptr;
		}
		cnt[x]++;
		ans=max(ans,1ll*cnt[x]*i);
		c=getchar(); 
		i++; 
		
		if(c=='\n') break;
		flag=0;
		for(register int j=head[x];j;j=nex[j]){
			if(ch[j]==c){
				x=to[j];
				flag=1;
				break;
			}
		}
		if(!flag){
			ptr++;
			esz++;
			to[esz]=ptr;
			ch[esz]=c;
			nex[esz]=head[x];
			head[x]=esz;
			x=ptr;
		}
		cnt[x]++;
		ans=max(ans,1ll*cnt[x]*i);
		c=getchar(); 
		i++; 
	}
}


int n;
char in[maxn+5]; 

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n/3*3;i+=3){
		insert();
		insert();
		insert(); 
	}	
	if(n%3==1) insert();
	if(n%3==2){
		insert();
		insert();
	}
	printf("%lld\n",ans);
} 
