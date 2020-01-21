#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,x1,y1,x2,y2,k;
char map[105][105];
bool done[105][105][5][11];
int mx[5]={0,0,1,0,-1},my[5]={0,1,0,-1,0};                //ср  об  вС  ио 
struct yxc{
    int x,y,dire,lev;
    int fa;
}que[1000005];
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(map,'*',sizeof(map));
        memset(que,0,sizeof(que));
        memset(done,0,sizeof(done));
        cin>>m>>n;
        for(int i=1;i<=m;i++){
            for(int l=1;l<=n;l++){
                cin>>map[i][l];
            }
        }
        cin>>k>>y1>>x1>>y2>>x2;
        que[1].x=x1,que[1].y=y1,que[1].dire=1;
        que[2]=que[3]=que[4]=que[1];
        que[2].dire=2,que[3].dire=3,que[4].dire=4;
        done[1][1][1][0]=done[1][1][2][0]=done[1][1][3][0]=done[1][1][4][0]=1;
        int head=0,tail=4;
        bool flag=0;
        while(head<tail){
            head++;
            int xx=que[head].x,yy=que[head].y,dd=que[head].dire;
            printf("%d  [ %d , %d ] %d #%d  fa: %d\n",head,xx,yy,dd,que[head].lev,que[head].fa);
            if(que[head].lev>k)continue;
            if(xx==x2&&yy==y2){
                cout<<"yes\n";
                flag=1;
                break;
            } 
            for(int i=1;i<=4;i++){
                if(map[xx+mx[i]][yy+my[i]]=='*')continue;
                yxc ne;
                ne.x=xx+mx[i];
                ne.y=yy+my[i];
                ne.dire=i;
                ne.lev=que[head].lev;
                ne.fa=head;
                if(ne.dire!=que[head].dire){
                    ne.lev++;
                }
                if(done[xx+mx[i]][yy+my[i]][i][ne.lev])continue;
                done[xx+mx[i]][yy+my[i]][i][ne.lev]=1;
                tail++;
                que[tail]=ne;
            }
        }
        if(!flag){
            cout<<"no\n";
        }
    }
    return 0;
}
/* 
1
5 5
.....
.***.
.*.*.
.*.**
.....
10 1 1 3 3
*/
