//http://www.cnblogs.com/MashiroSky/p/5921072.html 
#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
#define maxn 1000005
using namespace std;
struct matrix{
    long long a[3][3];
    
    void set(int x){
        if(x==1){
            a[1][1]=1;
            a[1][2]=0;
            a[2][1]=0;
            a[2][2]=1;
        }else{
            a[1][1]=0;
            a[1][2]=0;
            a[2][1]=0;
            a[2][2]=0;
        }
    }
    
    void set(long long A11,long long A12,long long A21,long long  A22){
        a[1][1]=A11;
        a[1][2]=A12;
        a[2][1]=A21;
        a[2][2]=A22;
    }
    
    friend matrix operator * (matrix p,matrix q){
        matrix ans;
        ans.set(0);
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++){
                for(int k=1;k<=2;k++){
                    ans.a[i][j]+=p.a[i][k]*q.a[k][j]%mod;
                }
                ans.a[i][j]%=mod;
            }
        }
        return ans;
    }
    void print(){
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
};

inline matrix fast_pow(matrix x,long long k){
    matrix ans;
    ans.set(1);
    while(k){
        if(k&1) ans=ans*x;
        x=x*x;
        k>>=1;
    }
    return ans;
}

char N[maxn],M[maxn];
long long n,m;
long long a,b,c,d;
long long str_to_num(char *s,long long modulo){
    int len=strlen(s+1);
    long long ans=0;
    for(int i=1;i<=len;i++){
        ans=(ans*10+s[i]-'0')%modulo;
    }
    return ans;
}

matrix A,B,T;
int main(){
    scanf("%s %s",N+1,M+1);
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    if(a==1&&c==1){
        n=str_to_num(N,mod);
        m=str_to_num(M,mod);
    }else{
        n=str_to_num(N,mod-1);
        m=str_to_num(M,mod-1);
    }
 	A.set(a,0,b,1);
    B.set(c,0,d,1);
    T.set(1,1,0,0);
    A=fast_pow(A,m-1);
    A.print();
	matrix tmp=A*B;
	tmp.print();
	tmp=fast_pow(A*B,n-1);
	tmp.print();
    T=T*fast_pow(A*B,n-1)*A;
    printf("%lld\n",T.a[1][1]);
} 
