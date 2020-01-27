#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
struct node {
    int x;
    int y;
    int value; //最小值
    int color; //颜色
    int magic; //魔法能否使用 1,0
} queue[maxn];
int a[maxn][maxn],v[maxn][maxn];
int xx[4]= {1,-1,0,0},yy[4]= {0,0,1,-1};
int m,n;
void bfs() {
    int head=0,tail=1;
    queue[head].x=1;
    queue[head].y=1;
    queue[head].value=0;
    queue[head].color=a[1][1];
    queue[head].magic=1;
    while(head<tail) {
        int tx,ty,tv;
        for(int i=0; i<4; i++) {
            tx=queue[head].x+xx[i];
            ty=queue[head].y+yy[i];
            tv=queue[head].value;
            if(tx<1||tx>m||ty<1||ty>m) continue;
            if(a[tx][ty]!=-1) { //可以走
                if(a[tx][ty]!=queue[head].color)  tv+=1;
                if(tv<v[tx][ty]) {
                    v[tx][ty]=tv;
                    queue[tail].x=tx;
                    queue[tail].y=ty;
                    queue[tail].value=tv;
                    queue[tail].color=a[tx][ty];
                    queue[tail].magic=1;
                    tail++;
                }
            } else if(queue[head].magic==0) {
                continue;
            } else { //用魔法
                tv+=2;
                if(tv<v[tx][ty]) {
                    v[tx][ty]=tv;
                    queue[tail].x=tx;
                    queue[tail].y=ty;
                    queue[tail].value=tv;
                    queue[tail].color=queue[head].color;
                    queue[tail].magic=0;
                    tail++;
                }
            }
        }
        head++;
    }
}
int main() {
    int x,y,c;
    memset(a,-1,sizeof(a));
    memset(v,127,sizeof(v));
    cin>>m>>n;
    for(int i=1; i<=n; i++) {
        cin>>x>>y>>c;
        a[x][y]=c;
    }
    v[1][1]=0;
    bfs();
    if(v[m][m]>100000) cout<<-1;
    else cout<<v[m][m];
    return 0;
}
