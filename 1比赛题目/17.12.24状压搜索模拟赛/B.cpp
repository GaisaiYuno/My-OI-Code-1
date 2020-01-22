#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
#define maxk 15
#define maxq maxn*maxn*maxk+10
#define max_last 5
using namespace std;
int n,m,t,mk,x1,x2,y1,y2;
struct node{
   int x;
   int y;
   int k;
   int last_turn;
};
node queue[maxq];
node now,nex;
char map[maxn][maxn];
int used[maxn][maxn][max_last][maxk];
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
bool judge(int x,int y,int k){
    if(x<1||y<1||x>m||y>n) return false;
    else if(map[x][y]=='*') return false;
    else return true;
} 
//n列，m行，x列，y行 
int bfs(){
    int head=0,tail=0;
    queue[0].x=x1;
    queue[0].y=y1;
    queue[0].k=-1;
    queue[0].last_turn=-1;
    memset(used,0,sizeof(used));
    used[x1][y1][0][0]=1;
    do{
        now=queue[head];
        if(now.x==x2&&now.y==y2){
            if(now.k<=mk) return 1;
            else return 0;
        }
        for(int i=0;i<4;i++){
            nex.x=now.x+walkx[i];
            nex.y=now.y+walky[i];
            nex.k=now.k;
            nex.last_turn=now.last_turn;
            if(judge(nex.x,nex.y,nex.k)){ 
                if(now.last_turn!=i){
                   nex.last_turn=i;
                   nex.k++;
                }
                if(nex.k>mk) continue;
                if(used[nex.x][nex.y][nex.last_turn][nex.k]==1) continue;
                used[nex.x][nex.y][nex.last_turn][nex.k]=1;
                tail++;
                queue[tail]=nex;
                //printf("(%d,%d),last=%d,k=%d\n",nex.x,nex.y,nex.last_turn,nex.k);
            } 
        }
        head++;
    }while(head<=tail);
    return 0;
}
int main(){
    cin>>t;
    while(t--){
        cin>>m>>n;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++) cin>>map[i][j];
        }
        cin>>mk>>y1>>x1>>y2>>x2;
        if(bfs()==1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
/*
8 7
.*...*.
.*.*.*.
...*.*.
****.*.
.....*.
.*****.
.*...*.
...*...
12 1 1 7 1

*/
