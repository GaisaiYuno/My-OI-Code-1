#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
using namespace std;
// 刷新当前屏幕
inline void Refresh(char q[][22], int grade, int gamespeed){
	int i,j;
	cout << endl;
	for(i=0;i<22;i++){
		cout << "\t";
		for(j=0;j<22;j++)
			cout<<q[i][j]<<' '; // 输出贪吃蛇棋盘
		if(i==0) cout << "\t等级为：" << grade;
		if(i==4) cout << "\t自动前进时间";
		if(i==6) cout << "\t间隔为：" << gamespeed << "ms";
		cout<<endl;
	}
}
int main() {
	char tcsQipan[22][22]; // 贪吃蛇棋盘是一个二维数组(如22*22，包括墙壁)
	int i,j;
	for(i=1;i<=20;i++)
		for(j=1;j<=20;j++)
			tcsQipan[i][j]=' '; // 初始化贪吃蛇棋盘中间空白部分
	for(i=0;i<=21;i++)
		tcsQipan[0][i] = tcsQipan[21][i] = '-'; //初始化贪吃蛇棋盘上下墙壁
	for(i=1;i<=20;i++)
		tcsQipan[i][0] = tcsQipan[i][21] = '|'; //初始化贪吃蛇棋盘左右墙壁
	int tcsZuobiao[2][100]; //蛇的坐标数组
	for(i=0; i<4; i++){
		tcsZuobiao[0][i] = 1;
		tcsZuobiao[1][i] = i + 1;
	}
	int head = 3,tail = 0;
	for(i=1;i<=3;i++)
	tcsQipan[1][i]='*'; //蛇身
	tcsQipan[1][4]='#'; //蛇头
	int x1, y1; // 随机出米
	srand(time(0));
	do{
	x1=rand()%20+1;
	y1=rand()%20+1;
	}while(tcsQipan[x1][y1]!=' ');
	tcsQipan[x1][y1]='0';
	cout<<"\n\n\t\t贪吃蛇游戏即将开始 !"<<endl;//准备开始;;
	long start;
	int grade = 1, length = 4;
	int gamespeed = 5000;
	cout<<"设置前进时间间隔"<<endl; //前进时间间隔
	cin>>gamespeed;
	for(i=3;i>=0;i--) {
		start=clock();
		while(clock()-start<=100);
			system("cls");
		if(i>0)
		cout << "\n\n\t\t进入倒计时：" << i << endl;
		else
			Refresh(tcsQipan,grade,gamespeed);
	}
	int timeover;
	char direction = 77; // 初始情况下，向右运动
	int x,y;
	while(1){
		timeover = 1;
		start = clock();
		while((timeover=(clock()-start<=gamespeed))&&!kbhit());
			//如果有键按下或时间超过自动前进时间间隔则终止循环
			if(timeover){
				getch();direction = getch();
			}
		switch(direction){
			case 72: x= tcsZuobiao[0][head]-1; y= tcsZuobiao[1][head];break; // 向上
			case 80: x= tcsZuobiao[0][head]+1; y= tcsZuobiao[1][head];break; // 向下
			case 75: x= tcsZuobiao[0][head]; y= tcsZuobiao[1][head]-1;break; // 向左
			case 77: x= tcsZuobiao[0][head]; y= tcsZuobiao[1][head]+1; // 向右
		}
		if(!(direction==72||direction==80||direction==75 ||direction==77)){ // 按键非方向键
			cout << "\tGame over!" << endl;return 0;
		}
		if(x==0 || x==21 ||y==0 || y==21){ // 碰到墙壁
			cout << "\tGame over!" << endl;return 0;
		}
		if(tcsQipan[x][y]!=' '&&!(x==x1&&y==y1)){ // 蛇头碰到蛇身
			cout << "\tGame over!" << endl;return 0;
		}
		if(x==x1 && y==y1){ // 吃米，长度加1
			length ++;
		if(length>=8){
			length -= 8;
		grade ++;
		if(gamespeed>=200)
			gamespeed = 550 - grade * 50; // 改变自动前进时间间隔
		}
		tcsQipan[x][y]= '#';
		tcsQipan[tcsZuobiao[0][head]][tcsZuobiao[1][head]] = '*';
		head= (head+1)%100;
		tcsZuobiao[0][head] = x;
		tcsZuobiao[1][head] = y;
		do {
			x1=rand()%20+1;
			y1=rand()%20+1;
		}while(tcsQipan[x1][y1]!=' ');
		tcsQipan[x1][y1]='0';
		Refresh(tcsQipan,grade,gamespeed);
		} else { // 不吃米
			tcsQipan [tcsZuobiao[0][tail]][tcsZuobiao[1][tail]]=' ';
			tail=(tail+1)%100;
			tcsQipan [tcsZuobiao[0][head]][tcsZuobiao[1][head]]='*';
			head=(head + 1) % 100;
			tcsZuobiao[0][head] = x;
			tcsZuobiao[1][head]=y;
			tcsQipan[tcsZuobiao[0][head]][tcsZuobiao[1][head]]='#';
			Refresh(tcsQipan,grade,gamespeed);
		}
	}
	return 0;
}
