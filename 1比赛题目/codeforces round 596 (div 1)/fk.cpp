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
    strcpy(a[0][0].str,"Ԫ�ػ��ϼ�����");
    strcpy(a[1][0].str,"Ԫ��ʧ����");
    strcpy(a[2][0].str,"����������Ӧ");
    strcpy(a[3][0].str,"Ԫ�ر�����");
    strcpy(a[4][0].str,"������������");
    strcpy(a[0][1].str,"Ԫ�ػ��ϼ۽���");
    strcpy(a[1][1].str,"Ԫ�صõ���");
    strcpy(a[2][1].str,"������ԭ��Ӧ");
    strcpy(a[3][1].str,"Ԫ�ر���ԭ");
    strcpy(a[4][1].str,"���ɻ�ԭ����");
}
void Query() {
    srand(time(NULL));
    system("cls");
    puts("������ԭ��Ӧ���� ���� zyd����");
    puts("ע�������ʱ���벻Ҫ���뺺�֡����������ַ�����������ĸ��������ܻ������쳣\n\n");
    int type=rand()&1;
    int x=rand()%5,y=rand()%5;
    while(x==y) {
        x=rand()%5;
        y=rand()%5;
    }
    printf("��֪%s\n",a[x][type].str);
    printf("��ô�� ��\n");
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
        printf("��ȷ\n\n\n");
        printf("����0�����������������������......");
    } else {
        printf("����\n");
        printf("��ȷ�𰸣�%c\n\n",ans);
        printf("����0�����������������������......");
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
