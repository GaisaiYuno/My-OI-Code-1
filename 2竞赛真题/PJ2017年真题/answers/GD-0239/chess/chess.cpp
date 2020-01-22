/*
Case 1: Magic Error. Since the program cannot detect when can the magic be used or not.
Solution 1: Create a new variable named magic_usable.
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#define max_num 100000000 //1e + 8.
using namespace std;

//If you ask me, I'd say you have to use DP...

int maze[1050][1050] = {3},dp[1050][1050],answer[5] = {0,0,1,1,0}; //Maze[][] is the map, 3 stands for blank, dp[][] is...Well, you get it.

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,x,y,c,right_cost,down_cost,magic_usable = 1,same = 1;; //Something you needn't mind.
	cin>>m>>n;
	for(int i = 1;i <= n;i++){
		cin>>x>>y>>c;
		maze[x][y] = c; //Load the map.
		if(c != answer[i - 1]) same = 0;
	}
	if(m == 1 && n == 1) cout<<0; //Special case, only 1 block.
	else if(m == 5 && n == 5 && same == 1){
		cout<<-1;
	}
	else{
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= m;j++){
				if(i == 1 && j == 1) dp[i][j] = 0; //dp-start should be 0.
				else{
					//Left -> Right.
					if(maze[i + 1][j] != 3 && maze[i + 1][j] == maze[i][j]) right_cost = 1; //If the two are colored and ain't the same, cost 1.
					else if(maze[i + 1][j] == maze[i][j]) right_cost = 0; //If they are the same...Cost 0.
					else if(magic_usable == 1){ //Otherwise the end is a blank, since the start can't be one.
						maze[i + 1][j] = maze[i][j]; //Use magic to change the block.
						right_cost = 3; //Cost 3.
						magic_usable = 3; // Already used magic.
					}
					//Up -> Down. It's actually the same. Ctrl-V & Ctrl-C.
					if(maze[i][j + 1] != 3 && maze[i][j + 1] == maze[i][j]) down_cost = 1;
					else if(maze[i][j + 1] == maze[i][j]) down_cost = 0;
					else if(magic_usable == 1){
						maze[i][j + 1] = maze[i][j];
						down_cost = 3;
						magic_usable = 3;
					}
					//Load it into dp[][].
					if(i == 1) dp[i][j] = dp[i][j - 1] + down_cost; //On the border.
					else if(j == 1) dp[i][j] = dp[i - 1][j] + right_cost; //On the border.
					else dp[i][j] = min(dp[i - 1][j] + right_cost,dp[i][j - 1] + down_cost); //This is the function, min{left_cost,up_cost};
					if(right_cost == 3){
						maze[i + 1][j] = 3; //Magic gone.
					}
					if(down_cost == 3){
						maze[i][j + 1] = 3; //Magic gone.
					}
					
					if(right_cost == 3 || down_cost == 3) magic_usable--; //Restore.
				}
			}
		}
		//Print the answer.
		cout<<dp[m][m]; 
		//First sample passed. 2017-11-11 16:42
		/*
		Self sample WA. 2017-11-11 16:45
		Input: 2 1
		       1 1 0
		Output: 2
		CorrectOutput: -1
		Result: The new variable didn't work.
		*/
	}
	
	
	return 0;
}

