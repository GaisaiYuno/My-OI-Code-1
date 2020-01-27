/*
* this code is made by LinMeiChen
* Problem:
* Type of Problem:
* Thinking:
* Feeling:
*/
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//#include<math.h>
//#include<string>
//#include<vector>
//#include<queue>
//#include<list>
using namespace std;
typedef long long lld;
typedef unsigned int ud;
#define oo 0x3f3f3f3f
#define maxn 51
int map[maxn][maxn];
int road[maxn][maxn][4];
int st[maxn][maxn][2050];
int n, m, p, k;
int d[4][2] = {
    { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }
};
struct Node
{
    int x, y;
    int st, step;
};
Node q[maxn*maxn*2050];
int front, rear;

bool Pass(Node& node, int dir)
{
    if (road[node.x][node.y][dir] == -1)
        return false;
    if (road[node.x][node.y][dir] == 0)
        return true;
    if (!(road[node.x][node.y][dir] & node.st))
        return false;
    return true;
}

int BFS()
{
    Node now, next;
    now.x = 1;
    now.y = 1;
    now.step = 0;
    now.st = map[1][1];
    st[now.x][now.y][now.st] = 1;

    front = rear = 0;
    q[rear++] = now;    
    
    while (front < rear)
    {
        now = q[front++];
        if (now.x == n&&now.y == m)
            return now.step;      
        for (int i = 0; i < 4; i++)
        {
            next.x = now.x + d[i][0];
            next.y = now.y + d[i][1];
            if (next.x >= 1 && next.x <= n&&next.y >= 1 && next.y <= m)
            {
                if (Pass(now, i))
                {
                    next.st =now.st | map[next.x][next.y]; 
                    if (!st[next.x][next.y][next.st])
                    {
                        next.step = now.step + 1;
                        st[next.x][next.y][next.st] = 1;
                        q[rear++] = next;
                    }
                }
            }
        }
    }
    return -1;
}

int Get(int x)
{
    if (x == 0)
        return -1;
    else
        return 1 << x;
}

void SetRoad(int x1, int y1, int x2, int y2, int key)
{
    int temp = Get(key);
    if (x1 == x2)
    {
        if (y1 < y2)
        {
            road[x1][y1][1] = temp;
            road[x2][y2][3] = temp;
        }
        else
        {
            road[x1][y1][3] = temp;
            road[x2][y2][1] = temp;
        }
    }
    else if (x1 < x2)
    {
        road[x1][y1][2] = temp;
        road[x2][y2][0] = temp;
    }
    else
    {
        road[x1][y1][0] = temp;
        road[x2][y2][2] = temp;
    }
}

void Init()
{
    memset(map, 0, sizeof map);
    memset(road, 0, sizeof road);
    memset(st, 0, sizeof st);
}

bool Read()
{
    int x1, x2, y1, y2, key;
    if (scanf("%d%d%d", &n, &m, &p) == EOF)
        return false;
    //³õÊ¼»¯
    Init();
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &key);
        SetRoad(x1, y1, x2, y2, key);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d%d", &x1, &y1, &key);
        map[x1][y1] |= (1 << key);
    }
    return true;
}

int main()
{
    while (Read())
    {
        printf("%d\n",BFS());
    }
    return 0;
}
