#include<iostream>
#include<stdlib.h>
#include<ctime>
#include <conio.h>
using namespace std;
string a[40]= {
	"       ",
	"���īh	",
	"�����	",
	"������	",
	"������	",
	"��  ��	",
	"��˼Դ	",
	"�Ʊ���	",
	"��  ��	",
	"������	",
	"������	",
	"��  ��	",
	"�Ϻ���	",
	"���ӷ�	",
	"Ǯ����	",
	"����	",
	"�����	",
	"��  ��	",
	"������	",
	"��֮��	",
	"�����	",
	"л̩Ȼ	",
	"��  ��	",
	"������	",
	"��˺�	",
	"�����	",
	"���	",
	"����Դ	",
	"���ǳ�	",
	"Ԭ  �	",
	"ղ����	",
	"�ż��	",
	"�����	",
	"��Խ��	",
	"������	",
	"֣����	",
	"������	",
	"�쿡��	",
	"������	",
	"��γ�	"
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
		cout<<"��ȡ��ѧ��Ϊ��"<<a[x+1];
		cout<<endl;
		system("pause"); 
		cout<<endl;
	}
}

