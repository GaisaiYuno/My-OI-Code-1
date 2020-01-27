#include <cstdio>
//#include <windows.h>
// ‰»Î
int W, H;
int map[20][20];
int sx, sy,ex, ey;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int result;

bool check(int x, int y){
    return 0 <= x && x < H && 0 <= y && y < W;
}/*
void debug(int ans){
	printf("\n");
	
	for(int i=1;i<=H;i++){
			printf("\n");
			for(int j=1;j<=W;j++)
			{
				printf("%d ",map[i][j]);
			}
		}
		printf("\n");
		printf("now ans= %d tmp = %d\n",ans,result);
//		system("pause");
		printf("\n");
}*/

void dfs(int x, int y, int ans){
    if(x == ex && y == ey){
        if(result > ans){
            result = ans;
        }
        return;
    }
    if(ans==10||ans>=result) return;
    for(int i = 0; i < 4; i ++){
        int xx = x + dir[i][0], yy = y + dir[i][1];
        while(check(xx, yy) && map[xx][yy] != 1){
            if(xx == ex && yy == ey){                
                ans ++;
                if(result > ans){
                    result = ans;
                }
                return;
            }
            xx += dir[i][0];
            yy += dir[i][1];
        }
        if((xx == x + dir[i][0] && yy == y + dir[i][1]) || !check(xx, yy)){
            continue;
        }
        map[xx][yy] = 0;
        ans ++;
        dfs(xx-dir[i][0],yy-dir[i][1],ans);
   //     map[xx][yy]=4;
   //     debug(ans);
    //    map[xx][yy]=0;
        ans --;
        map[xx][yy] = 1;
    }
}

int main(){
    freopen("data_a.txt","r",stdin);
    while(scanf("%d %d", &W, &H)){
    	
    	result=11;
        if(W == 0 && H == 0) break;
        for(int i = 0; i < H; i ++){
            for(int j = 0; j < W; j ++){
                scanf("%d", &map[i][j]);
                if(map[i][j]==2){
                	sx=i;sy=j;
                	map[i][j]=0;
				}if(map[i][j]==3){
					ex=i;ey=j;
				}
            }
        }
	dfs(sx, sy, 0);
    if(result == 11)
        printf("-1\n");
    else
        printf("%d\n", result);
    }
    return 0;
}
