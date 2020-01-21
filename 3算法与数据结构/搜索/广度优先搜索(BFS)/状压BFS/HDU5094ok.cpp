#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 56
#define maxqu 50*50*(1<<11)+10
using namespace std;
int n,m,p,k,s;
struct node{
    int x;
    int y;
    int step;
    int key;//存储钥匙 
};
node now,nex;
node queue[maxqu];
int door[maxn][maxn][maxn][maxn];
int keys[maxn][maxn];
int used[maxn][maxn][2055];
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
int fread(){
    int x=0;
    char c=getchar();
    int sign=1;
    while(c<'0'||c>'9') {
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*sign;
}
bool judge(int x1,int y1,int x2,int y2){
	if(door[now.x][now.y][nex.x][nex.y]==0) return false;//有墙 
    if(x2>=1&&x2<=n&&y2>=1&&y2<=m) return true;
    else return false;
}
int bfs(){  
    int head=0,tail=0;
    int tmp;
    queue[0].x=1;
    queue[0].y=1;
    queue[0].step=0;
    queue[0].key|=keys[1][1];//起点有钥匙的特判 
    memset(used,0,sizeof(used));    
    used[1][1][queue[0].key]=1;
    do{
        now=queue[head];
        if(now.x==n&&now.y==m) return now.step;
        for(int i=0;i<4;i++){
            nex.x=now.x+walkx[i];
            nex.y=now.y+walky[i];
            nex.key=now.key;
            nex.step=now.step;
            if(judge(now.x,now.y,nex.x,nex.y)){
            	if(door[now.x][now.y][nex.x][nex.y]>0){//开门 
                    tmp=door[now.x][now.y][nex.x][nex.y]-1;
                    if((nex.key&(1<<tmp))==0) continue;
                }
                if(keys[nex.x][nex.y]>0){//拿钥匙 
                    nex.key|=keys[nex.x][nex.y];
                }
                if(used[nex.x][nex.y][nex.key]==1) continue;
                used[nex.x][nex.y][nex.key]=1;
                tail++;
                queue[tail].x=nex.x;
                queue[tail].y=nex.y;
                queue[tail].key=nex.key;
                queue[tail].step=nex.step+1;
                //printf("(%d,%d) key=%d step=%d door=%d keys[x][y]=%d\n",nex.x,nex.y,nex.key,nex.step+1,door[now.x][now.y][nex.x][nex.y],keys[nex.x][nex.y]); 
            }
        } 
        head++;
    }while(head<=tail);
    return -1;
}
int main(){
   // freopen("data.txt","r",stdin);
    int x1,y1,x2,y2,v;
    while(cin>>n>>m>>p){
        memset(door,-1,sizeof(door));
        memset(keys,0,sizeof(keys));
        k=fread();
        for(int i=1;i<=k;i++){
            x1=fread();
            y1=fread();
            x2=fread();
            y2=fread();
            v=fread();
            door[x1][y1][x2][y2]=v;//>0门，=0墙，-1无 
            door[x2][y2][x1][y1]=v;
        }
        cin>>s;
        for(int i=1;i<=s;i++){
            x1=fread();
            y1=fread();
            v=fread();
            keys[x1][y1]|=(1<<(v-1));//预处理钥匙，注意一个位置有多个钥匙的情况 
        }
        cout<<bfs()<<endl;
    }
}
/* 易错数据 
33 5 4
35
27 4 27 5 1
20 1 20 0 0
1 1 2 1 1
7 3 6 3 1
27 4 27 5 3
13 3 13 2 1
20 3 20 4 3
16 3 17 3 1
32 2 32 3 3
28 5 28 4 1
28 5 27 5 3
15 3 15 4 1
27 3 27 2 3
33 1 33 0 1
23 2 22 2 1
1 4 0 4 1
4 3 4 4 2
2 2 3 2 1
16 3 17 3 1
28 3 27 3 1
20 5 21 5 0
33 1 33 0 2
29 2 28 2 1
16 1 15 1 0
14 4 13 4 2
11 3 11 4 3
12 4 11 4 2
16 5 16 4 2
4 1 5 1 2
22 3 23 3 2
33 3 34 3 1
20 3 20 2 0
29 5 30 5 0
7 2 8 2 3
28 3 28 2 3
3
27 5 8
1 1 1
10 1 5
正解36 
*/ 
