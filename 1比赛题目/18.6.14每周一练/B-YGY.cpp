#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, pair<bool, int> > mp;
typedef pair<bool, int> pa;
mp queue[10000000];
bool used[2][100005];
int head, tail;
vector<int> route[100005];
void steppush(int place)
{
    mp a = queue[place];
    for (int i = 0; i < route[a.first].size(); i++)
    {
        queue[tail++] = mp(route[a.first][i], pa(!a.second.first, place));
    }
}
int judge(mp a)
{
    if (used[a.second.first][a.first])
    {
        return 2;
    }
    return route[a.first].size() > 0;
}
int n, m, s;
void output(int place)
{
    if (place == -1)
        return;
    output(queue[place].second.second);
    cout << queue[place].first << ' ';
}
bool vis[100005];
void dfs(int place)
{
    if (vis[place])
    {
        cout << "Draw";
        exit(0);
    }
    vis[place] = 1;
    for (int i = 0; i < route[place].size(); i++)
    {
        dfs(route[place][i]);
    }
    vis[place] = 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        int p;
        for (int u = 0; u < t; u++)
        {
            cin >> p;
            route[i].push_back(p);
        }
    }
    cin >> s;
    queue[0] = mp(s, pa(0, -1)); //0 first 1 second
    tail = 1;
    while (head != tail)
    {
        if (judge(queue[head]) == 1)
        {
            used[queue[head].second.first][queue[head].first] = 1;
            steppush(head);
            head++;
        }
        else
        {
            if (judge(queue[head]))
            {
                head++;
                continue;
            }
            if (queue[head].second.first)
            {
                cout << "Win\n";
                output(head);
                return 0;
            }
            else
                head++;
        }
    }
    dfs(s);
    cout << "Lose";
}
