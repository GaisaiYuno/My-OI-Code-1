#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int qipan[200][200],s[2000];
bool qipan1[200][200];
int n,m,i,j,a,b,c,d,sum,sum1;
int pan(int d,int is,int iss){
	while(is!=m&&iss!=m){
		if(is==1&&iss==1&&sum1==0){return 0;
		}
	if(d==qipan[is+1][iss]&&d==0){sum1=0;return 0;}
    if(d==qipan[is-1][iss]&&d==0){sum1=0;return 0;}
    if(d==qipan[is][iss+1]&&d==0){sum1=0;return 0;}
    if(d==qipan[is][iss-1]&&d==0){sum1=0;return 0;}
	if(d==qipan[is+1][iss]&&d!=0&&qipan1[is+1][iss]!=true){is++;d=qipan[is][iss];qipan1[is][iss]=true;pan(d,is,iss);is--;d=qipan[is][iss];qipan1[is][iss]=false;}
    if(d==qipan[is-1][iss]&&d!=0&&qipan1[is-1][iss]!=true){is--;d=qipan[is][iss];qipan1[is][iss]=true;pan(d,is,iss);is++;d=qipan[is][iss];qipan1[is][iss]=false;}
    if(d==qipan[is][iss+1]&&d!=0&&qipan1[is][iss+1]!=true){iss++;d=qipan[is][iss];qipan1[is][iss]=true;pan(d,is,iss);iss--;d=qipan[is][iss];qipan1[is][iss]=false;}
    if(d==qipan[is][iss-1]&&d!=0&&qipan1[is][iss-1]!=true){iss--;d=qipan[is][iss];qipan1[is][iss]=true;pan(d,is,iss);iss++;d=qipan[is][iss];qipan1[is][iss]=false;}
    if(d!=qipan[is+1][iss]&&qipan[is+1][iss]!=0&&qipan1[is+1][iss]!=true){is++;d=qipan[is][iss];sum++;qipan1[is][iss]=true;pan(d,is,iss);is--;d=qipan[is][iss];sum--;qipan1[is][iss]=false;}
    if(d!=qipan[is-1][iss]&&qipan[is-1][iss]!=0&&qipan1[is-1][iss]!=true){is--;d=qipan[is][iss];sum++;qipan1[is][iss]=true;pan(d,is,iss);is--;d=qipan[is][iss];sum--;qipan1[is][iss]=false;}
    if(d!=qipan[is][iss+1]&&qipan[is][iss+1]!=0&&qipan1[is][iss+1]!=true){iss++;d=qipan[is][iss];sum++;qipan1[is][iss]=true;pan(d,is,iss);is--;d=qipan[is][iss];sum--;qipan1[is][iss]=false;}
    if(d!=qipan[is][iss-1]&&qipan[is][iss-1]!=0&&qipan1[is][iss-1]!=true){iss--;d=qipan[is][iss];sum++;qipan1[is][iss]=true;pan(d,is,iss);is--;d=qipan[is][iss];sum--;qipan1[is][iss]=false;}
    if(d!=qipan[is+1][iss]&&qipan[is+1][iss]==0&&qipan1[is+1][iss]!=true){is++;d=qipan[is][iss];sum+=2;qipan1[is][iss]=true;pan(d,is,iss);is--;d=qipan[is][iss];sum-=2;qipan1[is][iss]=false;}
    if(d!=qipan[is-1][iss]&&qipan[is-1][iss]==0&&qipan1[is-1][iss]!=true){is--;d=qipan[is][iss];sum+=2;qipan1[is][iss]=true;pan(d,is,iss);is--;d=qipan[is][iss];sum-=2;qipan1[is][iss]=false;}
    if(d!=qipan[is][iss+1]&&qipan[is][iss+1]==0&&qipan1[is][iss+1]!=true){iss++;d=qipan[is][iss];sum+=2;qipan1[is][iss]=true;pan(d,is,iss);is--;d=qipan[is][iss];sum-=2;qipan1[is][iss]=false;}
    if(d!=qipan[is][iss-1]&&qipan[is][iss-1]==0&&qipan1[is][iss-1]!=true){iss--;d=qipan[is][iss];sum+=2;qipan1[is][iss]=true;pan(d,is,iss);is--;d=qipan[is][iss];sum-=2;qipan1[is][iss]=false;}
	}
	
	
	
}















int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=n;i++){
		cin>>a>>b>>c;
		qipan[a][b]=c+1;
	}
	d=qipan[1][1];
	qipan1[1][1]=true;
	sum1=1;
	pan(d,1,1);
	if(sum1>0){cout<<sum;
	}
	else cout<<-1;
	return 0;
}
