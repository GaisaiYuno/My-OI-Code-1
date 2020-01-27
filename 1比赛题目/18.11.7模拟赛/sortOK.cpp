//LOJ 2181
//先对最小一层操作，逐次向上，直到完成。
//考虑如何操作，对于每一层（长度为2^x），暴力找出每段是否排好序，如果不是，num++,
//对于每一层，如果num>2显然无解，因为上一层已经排好，将其分成两段，暴力调换，如果可以，继续枚举
//最后发现操作顺序无关（显然）,每次加上操作数的阶乘
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 5005
using namespace std;
int n;
long long ans=0;
int a[maxn];
int pow2[20];
long long fact[20];
void init(){
	pow2[0]=1;
	for(int i=1;i<=n;i++){
		pow2[i]=pow2[i-1]<<1;
	}
	fact[0]=1;
	for(int i=1;i<=n;i++){
		fact[i]=fact[i-1]*i;
	}
}
int check(int x,int k){//判断是否递增 
	for(int i=1;i<pow2[k];i++){
		if(a[x+i]!=a[x+i-1]+1) return 0;
	}
	return 1;
}

void change(int x,int y,int t){
	for(int i=0;i<pow2[t];i++){
		swap(a[x+i],a[y+i]); 
	} 
}

void dfs(int x,int k){//x层数（第x层长度2^x），k操作次数 
	if(x==n+1){
		ans+=fact[k];
		return;
	}
	int seq1=0,seq2=0;
	for(int i=1;i<=pow2[n];i+=pow2[x]){
		if(check(i,x)==0){
			if(seq1==0) seq1=i;
			else if(seq2==0) seq2=i;
			else return; //如果该层非递增的段超过2个，显然无解 
		} 
	}
	if(seq1==0&&seq2==0) dfs(x+1,k);
	else if(seq2==0){//将该段的左半边和右半边交换 
		change(seq1,seq1+pow2[x-1],x-1);
		dfs(x+1,k+1);
		change(seq1,seq1+pow2[x-1],x-1);
	}else{
		//2个不合法的段，每段有两边，可互相交换，共2*2种方法 
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				change(seq1+i*pow2[x-1],seq2+j*pow2[x-1],x-1);
				if(check(seq1,x)&&check(seq2,x)){
					dfs(x+1,k+1);
					change(seq1+i*pow2[x-1],seq2+j*pow2[x-1],x-1);
					break;      
				}
				change(seq1+i*pow2[x-1],seq2+j*pow2[x-1],x-1);
			}
		} 
	} 
}
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=(1<<n);i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0);
	printf("%lld\n",ans);
}
