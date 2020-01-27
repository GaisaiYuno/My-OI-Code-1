#include<cstdio>
#include<cstring>
#include<set>
#include<queue>
using namespace std;
typedef int State[9];
set<int> vis;
struct node_bfs{
	int step;
	State s;
};
queue<node_bfs>q;
void init_lookup_table() {
	vis.clear();
}
int try_to_insert(State s){
	int v = 0;
	for(int i = 0; i < 9; i++) v = v * 10 + s[i];
	if(vis.count(v)) return 0;
	vis.insert(v);
	return 1;
}
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
State start,end;
int bfs() {
	node_bfs now,nex;
	init_lookup_table();
	while(!q.empty()) q.pop();
    memcpy(now.s,start,sizeof(start));
    now.step=0;
    q.push(now);
	while(!q.empty()) {
		now=q.front();
		q.pop();
		if(memcmp(end,now.s,sizeof(now.s)) == 0) return now.step;
		int z;
		for(z = 0; z < 9; z++) if(!now.s[z]) break;
		int x = z/3, y = z%3;
		for(int d = 0; d < 4; d++) {
			int newx = x + dx[d];
			int newy = y + dy[d];
			int newz = newx * 3 + newy;
			if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {
				memcpy(nex.s,now.s,sizeof(now.s));
				nex.s[newz]=now.s[z];
				nex.s[z]=now.s[newz];
                nex.step=now.step+1;
                if(try_to_insert(nex.s)) q.push(nex);
			}
		}
	}
	return -1;
}

int main() {
	for(int i = 0; i < 9; i++)
		scanf("%d", &start[i]);
	for(int i = 0; i < 9; i++)
		scanf("%d", &end[i]);
	int ans = bfs();
	printf("%d\n",ans);
	return 0;
}
/*
2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2
*/
