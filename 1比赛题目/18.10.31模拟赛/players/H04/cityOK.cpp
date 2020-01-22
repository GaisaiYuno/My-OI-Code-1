//先合并区间
//枚举每个点和每条线段，查分统计答案 
//比如说枚举了p这个点它在x,还有两段分别在x1,y1的一条线段，很明显我们最终如果移动的位置在x1-x~y1-x之间的话这个点是会为答案做贡献的，
//所以我们相当于给一个数组的x1-x~y1-x这一段加上一，最后看看哪个位置值最大，因为之前的区间已经是不重叠了，所以不必担心一个点会被多次计数。 
//差分后,统计最大的位置即可
//注意处理负数，统一加上1e6 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000
#define maxm 1000
#define maxv 1000000
using namespace std;
inline int qread(){
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

int n,m;
int a[maxn+5];
struct seg{
	int l;
	int r;
}b[maxm+5];
int cnt=0;
int div1[maxv*2+5];
int div2[maxv*2+5];
int main(){
	n=qread();
	m=qread();
	for(int i=1;i<=n;i++){
		a[i]=qread();
	}
	for(int i=1;i<=m;i++){
		b[i].l=qread();
		b[i].r=qread();
		div1[b[i].l]++;
		div1[b[i].r+1]--;
	}
	for(int i=1;i<=maxv;i++){
		div1[i]+=div1[i-1];
	}
	for(int i=0;i<=maxv;i++){
		if(div1[i]>1) div1[i]=1;
	}
	memset(b,0,sizeof(b));
	if(div1[0]>0) b[++cnt].l=0;
	if(div1[0]>0&&div1[1]==0) b[cnt].r=0;
	for(int i=1;i<=maxv;i++){
		if(div1[i-1]==0&&div1[i]>0) b[++cnt].l=i;
		if(div1[i+1]==0&&div1[i]>0) b[cnt].r=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			div2[b[j].l-a[i]+maxv]++;
			div2[b[j].r-a[i]+maxv+1]--;
		}
	}
	for(int i=1;i<=maxv*2;i++){
		div2[i]+=div2[i-1];
	}
	int d=0,s=0;
	for(int i=0;i<=maxv*2;i++){
		if(div2[i]>s){
			s=div2[i];
			d=abs(i-maxv);
		}else if(div2[i]==s){
			if(abs(i-maxv)<d) d=abs(i-maxv);
		}
	}
	printf("%d %d\n",d,s);
}
