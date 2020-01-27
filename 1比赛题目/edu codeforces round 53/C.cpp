#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200005 
#define INF 0x7fffffff
using namespace std;
int n,ex,ey;
char s[maxn];
int sumx[maxn];//x,y��ǰ׺�� 
int sumy[maxn];
int query(int *a,int l,int r){
	return a[r]-a[l-1];
}
int check(int len){
	for(int i=1;i+len-1<=n;i++){
		int px=sumx[n]-query(sumx,i,i+len-1);//px,pyΪȥ���޸�������x,y�仯��֮�� 
		int py=sumy[n]-query(sumy,i,i+len-1);
		int cx=ex-px;//cx,cyΪ�����޸ĺ�������������x,y�仯�� 
		int cy=ey-py;
		if(abs(cx)+abs(cy)<=len&&(len-abs(cx)-abs(cy))%2==0){
			//���㹻�Ĳ��������ƶ�����ʣ�µı�����ż�����ܻ������ 
			return 1;
		}
	}
	return 0;
}
int bin_search(){//���ֳ��� 
	int l=0,r=n;
	int mid;
	int ans=INF;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	if(ans>=INF) return -1;
	else return ans;
}
int main() {
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%d %d",&ex,&ey);
	for(int i=1; i<=n; i++) {
		sumx[i]=sumx[i-1];
		sumy[i]=sumy[i-1];
		if(s[i]=='U') {
			sumy[i]++;
		} else if(s[i]=='D') {
			sumy[i]--;
		} else if(s[i]=='L') {
			sumx[i]--;
		} else {
			sumx[i]++;
		}
	}
	printf("%d\n",bin_search());
}
