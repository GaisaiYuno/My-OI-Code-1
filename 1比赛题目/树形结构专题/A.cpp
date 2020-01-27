#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define maxn 50050
using namespace std;
int n,m;
int year[maxn],num[maxn];
int st[maxn][21];
void init(){
    for(int i=1;i<=n;i++) st[i][0]=num[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++)
            if(i+(1<<j)-1<=n)   st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int mylog(int x){
	if(x!=0) return log2(x);
	else return -1;
} 
int query(int l,int r){
    int k=mylog(r-l+1); 
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d %d",&year[i],&num[i]);
	}
    init();
    scanf("%d",&m);
    while(m--){
        int l,r;
        scanf("%d %d",&l,&r);
        int ql=lower_bound(year+1,year+1+n,l)-year;
        int qr=lower_bound(year+1,year+1+n,r)-year;
        if(ql>qr) puts("false");
        else if(qr>n||year[qr]!=r) {         
            if(ql>n||year[ql]!=l)      
                puts("maybe");
            else{                      
                int maxx=query(ql+1,qr-1);
                if(maxx>=num[ql]) puts("false");
                else puts("maybe");
            }
        }
        else{                           
            if(ql>n||year[ql]!=l){      
                int maxx=query(ql,qr-1);
                if(maxx>=num[qr]) puts("false");
                else puts("maybe");
            }
            else{                       
                if(num[ql]<num[qr]) puts("false");
                else{
                    int maxx=query(ql+1,qr-1);
                    if(maxx>=num[qr]) puts("false");
                    else if(qr-ql+1!=r-l+1) puts("maybe");      
                    else puts("true");
                }
            }
        }
    }
}

