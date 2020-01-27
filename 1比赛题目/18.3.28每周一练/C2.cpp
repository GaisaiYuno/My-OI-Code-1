#include<iostream>  
#include<fstream>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
#define Lchild rt<<1,L,m  
#define Rchild rt<<1|1,m+1,R  
#define maxn 100100  
int tree[maxn * 3];  
int N;  
int ans[maxn];  
void update(int x, int delta, int rt = 1, int L = 1, int R = N)  
{  
    if (L == R)  
    {  
        tree[rt]++;  
        return;  
    }  
    int m = (L + R) >> 1;  
    if (x <= m)  
        update(x, delta, Lchild);  
    else  
        update(x, delta, Rchild);  
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];  
}  
  
int query(int l, int r, int rt = 1, int L = 1, int R = N)  
{  
    if (l <= L&&R <= r)  
    {  
        return tree[rt];  
    }  
    int m = (L + R) >> 1;  
    int ret = 0;  
    if (l <= m)  
        ret += query(l, r, Lchild);  
    if (r > m)  
        ret += query(l, r, Rchild);  
    return ret;  
}  
struct node  
{  
    int x, y;  
    int pos;  
};  
node point[maxn];  
bool cmp(node a, node b)  
{  
    if (a.y != b.y)  
        return a.y > b.y;  
    return a.x < b.x;  
}  
#define scanf_s scanf
int main()  
{  
    while (scanf_s("%d", &N), N)  
    {  
        memset(ans, 0, sizeof(ans));  
        for (int i = 1; i <= N * 3; i++)  
            tree[i] = 0;  
        for (int i = 0; i < N; i++)  
        {  
            scanf_s("%d%d",&(point[i].x), &(point[i].y));  
            point[i].x++;  
            point[i].y++;  
            point[i].pos = i;  
        }  
        sort(point, point + N, cmp);  
        for (int i = 0; i < N; i++)  
        {  
            if (i&&point[i].x == point[i - 1].x&&point[i].y == point[i-1].y)  
                ans[point[i].pos] = ans[point[i - 1].pos];  
            else  
                ans[point[i].pos] = query(1, point[i].x);  
            //printf("[1,%d]=%d\n",point[i].x,query(1,point[i].x));
            update(point[i].x, 1);  
            //printf("  %d=1\n",point[i].x);
        }  
        for (int i = 0; i < N; i++)  
            printf("%d%c", ans[i], i == N - 1 ? '\n' : ' ');  
    }  
}
