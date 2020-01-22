#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxm 505
#define ForMyLove return 0;
using namespace std;
int n,m;
struct node{
	char name[20];
	int s;
	int e;
	int value;
}work[maxm];
inline int fastread(){
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
int cmp(node x,node y){
	return x.s<x.e;
}
int main(){
	freopen("exercise.in","r",stdin);
	freopen("exercise.out","w",stdout);
    n=fastread();
    m=fastread();
    for(int i=1;i<=m;i++){
    	scanf("%s",work[i].name);
    	work[i].s=fastread();
    	work[i].e=fastread();
    	work[i].value=fastread();
	}
    int cnt=1;
    int ans=-1; 
    for(int t=1;t<=1440;t++){
    	n++;
    	if(cnt==m+1){
    		n+=1440-t;
    		break;
		} 
    	if(t>=work[cnt].s&&t<=work[cnt].e){
    		n-=work[cnt].value;
    		if(n<=0){
    			ans=t;
    			break;
			}
			if(t==work[cnt].e) cnt++;
		}
	}
    if(n>0) cout<<"Accepted"<<endl<<n;
    else cout<<"Runtime Error"<<endl<<ans;
    ForMyLove
} 
