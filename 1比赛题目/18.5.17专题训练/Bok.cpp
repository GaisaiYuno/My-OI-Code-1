#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int T,MaxP,W;
struct dddl{
	int qq[10000005];
	int head,tail;
	dddl(){
		head=1,tail=0;
//		memset(qq,-0x7f,sizeof(qq));
	}
	void empty(){
		head=1,tail=0;
	}
	void push(int a){
		while(head<=tail&&a>qq[tail]) tail--;
		qq[++tail]=a;
	}
	void pop(int a){
		if(qq[head]==a) head++;
	}
	int length(){
		return tail-head+1;
	}
	int front(){
		if(length()==0) return -0x7ffffff;
		return qq[head];
	}
	void print(){
		for(int i=head;i<=tail;i++){
			printf("%d ",qq[i]);
		}
		putchar('\n');
	}
} q1,q2;
struct yxc{
	int ap,bp,as,bs;
	yxc(){
		ap=bp=as=bs=0;
	}
}day[2005];
int dp[2005][2005];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>T>>MaxP>>W;
		for(int i=1;i<=T;i++){
			cin>>day[i].ap>>day[i].bp>>day[i].as>>day[i].bs;
		}
		for(int i=1;i<=MaxP;i++) dp[0][i]=-0x7ffffff;
		for(int i=1;i<=T;i++){
			int j=max(0,i-W-1);
			q1.empty();
			q2.empty();
			for(int n=1;n<=min(MaxP,day[i].bs);n++){
				q2.push(dp[j][n]+day[i].bp*n);
			}
			for(int k=0;k<=MaxP;k++){			//dp[i][k]
				dp[i][k]=dp[i-1][k];
//				int aa=-0x7ffffff,bb=-0x7ffffff;
//				for(int n=max(0,k-day[i].as);n<k;n++){
//					aa=max(aa,dp[j][n]+day[i].ap*n);
//				}
//				for(int n=k+1;n<=min(MaxP,k+day[i].bs);n++){
//					bb=max(bb,dp[j][n]+day[i].bp*n);
////					cout<<"AHA "<<'['<<dp[j][n]<<' '<<bb<<']';
//				}
				dp[i][k]=max(dp[i][k],q1.front()-day[i].ap*k);
				dp[i][k]=max(dp[i][k],q2.front()-day[i].bp*k);
//				dp[i][k]=max(dp[i][k],max(q1.front(),q2.front()));
//				printf("i= %d k= %d [ %d , %d ] [ %d , %d ]\n",i,k,q1.front(),aa,q2.front(),bb);
				if(k-day[i].as+1>0) q1.pop(dp[j][k-day[i].as]+day[i].ap*(k-day[i].as));
				q1.push(dp[j][k]+day[i].ap*k);
				q2.pop(dp[j][k+1]+day[i].bp*(k+1));
				if(k+day[i].bs<MaxP) q2.push(dp[j][k+day[i].bs+1]+day[i].bp*(k+day[i].bs+1));
//				printf("%d\n",dp[j][k+day[i].bs+1]);
	//			printf("dp[ %d ][ %d ]= %d\n",i,k,dp[i][k]);
				
			}
			for(int i=1; i<=T; i++) {
					for(int j=0; j<=MaxP; j++) {
						printf("%d ",dp[i][j]);
					}
					printf("\n");
				}
				printf("\n");
		}
		for(int i=1;i<=T;i++){
			for(int j=0;j<=MaxP;j++){
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		} 
		int ans=0;
		for(int i=0;i<=MaxP;i++){
			ans=max(ans,dp[T][i]);
		}
		cout<<ans<<endl;
	}
}

