////http://119.29.55.79/problem/619
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500000
#define maxs 128 
using namespace std;
typedef long long ll;

void rsort(int *ans,int *fi,int *se,int sz,int maxv){
	static int buck[maxn+5];
	for(int i=0;i<=maxv;i++) buck[i]=0;
	for(int i=1;i<=sz;i++) buck[fi[i]]++;
	for(int i=1;i<=maxv;i++) buck[i]+=buck[i-1];
	for(int i=sz;i>=1;i--) ans[buck[fi[se[i]]]--]=se[i];
}
int sa[maxn+5],rk[maxn+5],height[maxn+5];
void suffix_sort(char *str,int n){
	static int se[maxn+5];
	for(int i=1;i<=n;i++){
		rk[i]=str[i];
		se[i]=i;
	}
	rsort(sa,rk,se,n,maxs);
	for(int k=1,m=maxs;k<=n;k*=2){
		int p=0;
		for(int i=n-k+1;i<=n;i++) se[++p]=i;
		for(int i=1;i<=n;i++){
			if(sa[i]>k) se[++p]=sa[i]-k;
		}
		rsort(sa,rk,se,n,m);
		swap(rk,se);
		p=rk[sa[1]]=1;
		for(int i=2;i<=n;i++){
			if(se[sa[i-1]]==se[sa[i]]&&se[sa[i-1]+k]==se[sa[i]+k]) rk[sa[i]]=p;
			else rk[sa[i]]=++p;
		}
		if(p==n) break;
		m=p;
	}
}
void get_height(char *str,int n){
	suffix_sort(str,n);
	for(int i=1;i<=n;i++) rk[sa[i]]=i;
	int k=0;
	for(int i=1;i<=n;i++){
		if(k) k--;
		int j=sa[rk[i]-1];
		while(str[i+k]==str[j+k]) k++;
		height[rk[i]]=k;
	}
}

int n,T,K;
char s[maxn+5];
void solve0(){
	int now=0,last=0;
	for(int i=1;i<=n;i++){
		now=last+n-sa[i]+1-height[i];
		if(now>K){
			for(int j=0;j<K+height[i]-last;j++){
				putchar(s[sa[i]+j]);
			}
			return;
		}
		last=now;
	}
	printf("-1\n");
}

int bin_search(int l,int r,int len,char ch){
//	int ans=r;
//	while(l<=r){
//		int mid=(l+r)>>1;
//		if(s[sa[mid]+len-1]>ch){
//			ans=mid;
//			r=mid-1;
//		}else l=mid+1;
//	}
//	return ans;	
	while(l<=r){
		int mid=(l+r)>>1;
		if(s[sa[mid]+len-1]>ch){
			r=mid-1;
		}else l=mid+1;
	}
	return r;
}
 
void solve1(){
	//[Warning] You are not expected to understand this.
	static ll sum[maxn+5];//��׺sa[1],sa[2],...sa[i]�����в�ͬ�Ӵ�����֮�� 
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+n-sa[i]+1; 
	if(K>sum[n]){
		printf("-1\n");
		return; 
	}
	int l1=1,r1=n;
	for(int i=1;i<=n;i++){//ö���Ӵ��ĵ�iλ���ַ�
		int l2=l1;
		for(char j='a';j<='z';j++){//���ֵ���ö�� 
			int r2=bin_search(l2,r1,i,j);//���ֳ���iλΪj���Ӵ���ͷ���ں�׺��rank����[l2,r2] 
			ll cnt=sum[r2]-sum[l2-1]-(ll)(r2-l2+1)*(i-1); //��iλΪj���Ӵ�����,��ȥ(i-1)*(r2-l2+1)�ǰѳ��Ȳ���i���Ӵ����� 
			if(K<=cnt){//ʣ�µĸ�����cntС��˵���Ӵ��ĵ�iλһ����j 
				if(K<=r2-l2+1){
					//��iλ��j���Ӵ���,��С��r2-l2+1���Ӵ���Ȼ��β��j 
					//��������������,���Ӵ��Ľ�βһ����j,����û�������ַ�,����ֱ�����
					 for(int u=sa[l2];u<=sa[l2]+i-1;u++) putchar(s[u]);
					 return; 
				}else{
					l1=l2;
					r1=r2;
					K-=r2-l2+1;
					break;
					//��������Ӵ���iλ��j,���滹�������ַ�,����Ҫbreak����ȥö��i+1λ 
				}
			}else{
				//��iλӦ�ô���j 
				l2=r2+1;//ö����һ��rank����
				K-=cnt; //��ȥ��ǰ�Ѿ�����ĸ��� 
			} 
		} 
		if(n-sa[l1]+1==i) l1++; //��׺sa[l1]�ĳ���ֻ��i,�޷�ö�ٵ�i+1λ������ȥ��l1 
	} 
}
int main(){
	scanf("%s",s+1);
	scanf("%d %d",&T,&K);
	n=strlen(s+1);
	get_height(s,n);	
	if(T==0){
		solve0(); 
	}else{
		solve1();
	}
} 
