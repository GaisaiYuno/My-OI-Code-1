#include<stdio.h>
#include<windef.h>
#include<conio.h>
#include<time.h>
#include<windows.h> 
#define re register int
using namespace std;
const int Size=15;
struct task {
    char str[Size];
} a[5][2];
void Init() {
    strcpy(a[0][0].str,"元素化合价升高");
    strcpy(a[1][0].str,"元素失电子");
    strcpy(a[2][0].str,"发生氧化反应");
    strcpy(a[3][0].str,"元素被氧化");
    strcpy(a[4][0].str,"生成氧化产物");
    strcpy(a[0][1].str,"元素化合价降低");
    strcpy(a[1][1].str,"元素得电子");
    strcpy(a[2][1].str,"发生还原反应");
    strcpy(a[3][1].str,"元素被还原");
    strcpy(a[4][1].str,"生成还原产物");
}
void Query() {
    srand(time(NULL));
    system("cls");
    puts("氧化还原反应练刁 —— zyd制作");
    puts("注：输入答案时，请不要输入汉字、输入特殊字符或输入多个字母，否则可能会运行异常\n\n");
    int type=rand()&1;
    int x=rand()%5,y=rand()%5;
    while(x==y) {
        x=rand()%5;
        y=rand()%5;
    }
    printf("已知%s\n",a[x][type].str);
    printf("那么（ ）\n");
    char ans;
    if(rand()&1) {
        printf("A. %s\n",a[y][type].str);
        printf("B. %s\n",a[y][type^1].str);
        ans='A';
    } else {
        printf("A. %s\n",a[y][type^1].str);
        printf("B. %s\n",a[y][type].str);
        ans='B';
    }
    char in=getchar();
    while(!isalpha(in)) {
        in=getchar();
    }
    in=toupper(in);
    if(in==ans) {
        printf("正确\n\n\n");
        printf("按下0结束，按下其他任意键继续......");
    } else {
        printf("错误\n");
        printf("正确答案：%c\n\n",ans);
        printf("按下0结束，按下其他任意键继续......");
    }
}
int main() {
    system("color 0F");
    Init();
    char ch=0;
    while(ch!='0') {
        Query();
        ch=getch();
    }
    return 0;
}
