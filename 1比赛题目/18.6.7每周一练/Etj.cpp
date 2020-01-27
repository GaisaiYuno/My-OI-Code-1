#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 300007

using namespace std;

int n,m,q;
vector<int> e[MAX];
int fa[MAX];
int ans[MAX];

void clear()
{
    for ( int i = 0 ; i < MAX ; i++ )
        e[i].clear();
    for ( int i = 1 ; i < MAX ; i++ )
        fa[i] = i;
}

void add ( int u , int v )
{
    e[u].push_back ( v );
    e[v].push_back ( u );
}

int _find ( int x )
{
    return x == fa[x]?x:fa[x] = _find ( fa[x] );
}

void _union ( int x , int y , int f )
{
    x = _find ( x );
    y = _find ( y );
    if ( x > y ) swap ( x , y );
    fa[y] = x;
    if ( f ) return;
    int xx = ans[x];
    int yy = ans[y];
    ans[x] = max ( max ( xx , yy ) , (xx+1)/2 + (yy+1)/2 +1 );
}

bool used[MAX];
bool mark[MAX];
int pp,dis;

void dfs ( int u , int d , int p )
{
    if ( d > dis )
    {
        dis = d;
        pp = u;
    }
    for ( int i = 0 ; i < e[u].size() ; i++ )
    {
        int v = e[u][i];
        if ( v == p ) continue;
        dfs  ( v , d+1 , u );
    }
}


int main ( )
{
	freopen("tree.in","r",stdin);
	freopen("tree.out2","w",stdout);
    while ( ~scanf ( "%d%d%d" , &n , &m , &q) )
    {
        clear();
        int x,y,z;
        for ( int i = 0 ; i < m ; i++ )
        {
            scanf ( "%d%d" , &x, &y);
            add ( x , y );
            _union ( x , y , 1 );
        }
        memset ( used , 0 , sizeof ( used ) );
        int cnt=0;
        for ( int i = 1 ; i <= n ; i++ )
        {
            int x = _find ( i );
            if ( used[x] ) continue;
            pp = dis = -1;
            used[x] = true;
            dfs ( x , 1 , -1 );
            dis = 0;
            dfs ( pp , 0 , -1 );
            ans[x] = dis;
            cnt++;
        }
//        printf("dfs %d times",cnt);
        for ( int i = 0 ; i < q ; i++ )
        {
            scanf ( "%d" , &z );
            if ( z == 1 )
            {
                scanf ( "%d" , &x );
                printf ( "%d\n" , ans[_find(x)] );
            }
            else
            {
                scanf ( "%d%d" , &x , &y );
                if ( _find(x) == _find(y) ) continue;
                _union ( x , y , 0 );
            }
        }
    }
}
