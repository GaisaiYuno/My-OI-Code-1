#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define len 1000
#define maxn 1005
#define maxm len*len
using namespace std;
inline int fread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
inline unsigned sfr(unsigned h, unsigned x) {
    return h >> x;
}
inline unsigned Ran() {
    return rand()<< 15|rand();
}
int f(unsigned long long i, unsigned long long j) {
    unsigned long long w = i * 100000011 + j;
    int h = 0;
    for(int k = 0; k < 5; ++k) {
        h += (int) ((w >> (8 * k)) & 255);
        h += (h << 10);
        h ^= sfr(h, 6);
    }
    h += h << 3;
    h ^= sfr(h, 11);
    h += h << 15;
    return sfr(h, 27) & 1;
}
const int mod=100007;
struct hashmap{
	struct node{
		unsigned long long x;
		unsigned long long pos;
		node *next;
	}a[mod];
	void ini(){
		memset(a,0,sizeof(a)); 
	}
	void insert(unsigned long long x,unsigned long long pos){
		if(a[x%mod].x==0){
			a[x%mod].x=x;
			a[x%mod].pos=pos;
		}else{
			node *tmp=new node();
			tmp->x=x;
			tmp->pos=pos;
			tmp->next=a[x%mod].next;
			a[x%mod].next=tmp;
		}
	} 
	unsigned long long find(unsigned long long x){
		if(a[x%mod].x==0) return 0;
		if(a[x%mod].x==x) return a[x%mod].pos;
		else{
			node *tmp=a[x%mod].next;
			while(tmp!=NULL){
				if(tmp->x==x) return tmp->pos;
				tmp=tmp->next;
			}
			return 0;
		} 
	}
};
hashmap H;
int t;
char s[len];
unsigned long long hsh[maxn];
int main(){
	cin>>t;
	for(int cas=1;cas<=t;cas++){
		H.ini();
		for(int i=1;i<=len;i++){
			scanf("%s",s);
			for(int j=0;j<len;j++){
				int tmp;
				if(s[j]=='1') tmp=1;
				else tmp=0; 
				hsh[j]=hsh[j-1]<<1+tmp;
			}
			for(int j=0;j<=len-64;j++){
				H.insert(hsh[j+64-1],(unsigned long long)(maxm*i+j));
			}
		}
		unsigned long long ans=0;
		int ans_x,ans_y;
		for(int i=0;ans==0&&i<=maxm;i+=1000){
			for(int j=0;ans==0&&j<=maxm;j+=900){
				if(j+64-1>=maxm) continue;
				unsigned long long x=0;
				for(int k=0;k<64;i++) x=x<<1+f(i,j+k);
				ans=H.find(x);
				if(ans!=0){
					ans_x=i;
					ans_y=j;
				}
			}
		}
		int x=ans/maxm,y=ans%maxm;
		printf("Case #%d :%d %d\n",ans_x-x+1,ans_y-y+1);
	}
} 
