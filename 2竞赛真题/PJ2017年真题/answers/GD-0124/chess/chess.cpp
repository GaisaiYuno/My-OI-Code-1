#include <iostream>
#include <stdio.h>
#include <algorithm>
#define YELLOW 1
#define RED 2

struct position{
	int pos_x,pos_y;
};
int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int total,colored_total,min_ans = 99999999;
int chest[101][101];
position route[10001];
int length;

bool found(const position &x){
	for(int i = 0;i < length;i++){
		if(route[i].pos_x == x.pos_x && route[i].pos_y == x.pos_y){
			return true;
		}
	}
	return false;
}

void dfs(int cost,int x,int y){
	if(x == total && y == total){
		if(min_ans > cost){
			min_ans = cost;
		}
		return;
	}
	position a;
	a.pos_x = x;
	a.pos_y = y;
	route[length++] = a;
	if(chest[x][y] != 0){
		for(int i = 0;i < 4;i++){
			position s;
			s.pos_x = x + direction[i][0];
			s.pos_y = y + direction[i][1];
			if(!found(s)){
				if(chest[x + direction[i][0]][y + direction[i][1]] == chest[x][y]){
					dfs(cost,x + direction[i][0],y + direction[i][1]);
				}
				else if(chest[x + direction[i][0]][y + direction[i][1]] != 0){
					dfs(cost + 1,x + direction[i][0],y + direction[i][1]);
				}
				else{
					dfs(cost + 2,x + direction[i][0],y + direction[i][1]);
				}
			}
		}
	}else{
		for(int i = 0;i < 4;i++){
			position s;
			s.pos_x = x + direction[i][0];
			s.pos_y = y + direction[i][1];
			if(!found(s)){
				if(chest[s.pos_x][s.pos_y] == chest[route[length - 3].pos_x][route[length - 3].pos_y]){
					dfs(cost,s.pos_x,s.pos_y);
				}
				else if(chest[s.pos_x][s.pos_y] != 0){
					dfs(cost + 1,s.pos_x,s.pos_y);
				}
			}
		}
	}
	length--;
}

int main(){
	freopen("chest.in","r",stdin);
	freopen("chest.out","w",stdout);
	std::cin >> total >> colored_total;
	int a,b,c;
	for(int i = 0;i < colored_total;i++){
		std::cin >> a >> b >> c;
		if(c == 1) chest[a][b] = YELLOW;
		if(c == 0) chest[a][b] = RED;
	}
	if(n <= 20){
		dfs(0,1,1);
		if(min_ans == 99999999) std::cout << "-1";
		else std::cout << min_ans;
	}else{
		std::cout << "-1";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
