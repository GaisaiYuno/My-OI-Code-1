//Ве№И SEARCH
#include<iostream>
#include<cstring>
#define maxr 51
#define maxn 1001 
using namespace std;
int r,c,n;
char a[maxr][maxr];
const int walkx[4] = {1,0,-1,0};
const int walky[4] = {0,1,0,-1};
int used[maxr][maxr][maxn];
char d[maxn][10];
void dfs(int x,int y,int now){
        if(used[x][y][now]) return;
    used[x][y][now]=1;
    if(now==n+1){
        a[x][y]='*';
        return;
    }
    int t;
     if(d[now][0]=='N') t=2;//2;
        if(d[now][0]=='S') t=0;//3;
        if(d[now][0]=='W') t=3;//1;
        if(d[now][0]=='E') t=1;//0;
        
        x += walkx[t];
        y += walky[t];
    while(x>=0&&y>=0&&x<r&&y<c&&a[x][y]!= 'X'){
    //    int t;
      //  if(d[now][0]=='N') t=2;
      //  if(d[now][0]=='S') t=3;
      //  if(d[now][0]=='W') t=1;
    //    if(d[now][0]=='E') t=0;
        dfs(x,y,now+1);
        x += walkx[t];
        y += walky[t];
    }
    
}
int main(){
    int sx,sy;
    cin>>r>>c;
    for(int i=0;i<r;i++){
         for(int j=0;j<c;j++) {
             cin>>a[i][j];
             if(a[i][j]=='*'){
                 sx=i;
                 sy=j;
             }
        } 
    }
    cin>>n;
    for(int k=1;k<=n;k++) scanf("%s",d[k]);
    memset(used,0,sizeof(used));
    a[sx][sy]='.';
    dfs(sx,sy,1);
    for(int u=0;u<r;u++){
        for(int v=0;v<c;v++) cout<<a[u][v];
        cout<<endl; 
    }
    return 0;           
} 
