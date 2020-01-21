#include<iostream>
#include<stdlib.h>
#include<ctime>
#include <conio.h>
using namespace std;
string a[40]= {
	"       ",
	"艾心玥	",
	"曾与点	",
	"封羽真	",
	"郭宇轩	",
	"国  星	",
	"何思源	",
	"黄碧紫	",
	"刘  灿	",
	"刘嘉鹏	",
	"刘嘉宇	",
	"罗  林	",
	"孟涵宇	",
	"年子丰	",
	"钱子扬	",
	"邱俊晰	",
	"孙皓天	",
	"唐  超	",
	"王天乐	",
	"王之畅	",
	"翁翊翔	",
	"谢泰然	",
	"徐  奔	",
	"徐子扬	",
	"杨邓弘	",
	"杨皓天	",
	"杨景云	",
	"杨培源	",
	"余星辰	",
	"袁  昊	",
	"詹乐澍	",
	"张佳皓	",
	"张文韬	",
	"张越敏	",
	"张政亮	",
	"郑楷奇	",
	"周星言	",
	"朱俊行	",
	"朱正婷	",
	"纵纬韬	"
};
int used[40];
int main() {
	while(1) {
		srand((unsigned)time(NULL));
		int x;
		while(x=rand()%39) {
			srand((unsigned)time(NULL));
			if(x!=28){
			   break;
			} 
		}
		cout<<"抽取的学生为："<<a[x+1];
		cout<<endl;
		system("pause"); 
		cout<<endl;
	}
}

