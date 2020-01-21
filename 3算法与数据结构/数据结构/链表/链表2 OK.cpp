#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
struct node
{
    int val;
    node *next;
};
node *last;
node *head;
node* team[1000+5];
map<int,int>tid;
int n,num;
void init()
{
    tid.clear();//num=0;
    //head=last=(node*)malloc(sizeof(node));
    //head=last=(node*)malloc(sizeof(node));
    head->next=NULL;
    for(int i=1;i<=n;i++)
        team[i]=NULL;
}
void in()
{
    int k;
    node* t;

    scanf("%d",&k);
    t=new node();
  //  t=&a[num++];
    t->val=k;t->next=NULL;
    int ttid=tid[k];
    if(team[ttid]==NULL)
    {
        team[ttid]=t;
        last->next=t;
        last=t;
    }
    else
    {
        node *p;
        p=team[ttid];
        t->next=p->next;
        p->next=t;
        team[ttid]=t;
        if(last==p)     //此处要注意，否则RE
            last=t;
    }

}
void out()
{
    int k=head->next->val;
    int kk=tid[k];
    if(head->next==team[kk])
    {
        printf("%d\n",k);
        team[kk]=NULL;
    }
    else
       printf("%d\n",k);


   head=head->next;

}
int main()
{
	//freopen("data.txt","r",stdin);
    int cas=1;
    while(scanf("%d",&n),n)
    {
        printf("Scenario #%d\n",cas++);
        init();
        for(int i=1;i<=n;i++)
        {
            int k;
            scanf("%d",&k);
            for(int j=1;j<=k;j++)
            {
                int kk;
                scanf("%d",&kk);
                tid[kk]=i;
            }
        }
        char ss[200];
        while(1)
        {
            scanf("%s",ss);
            if(strcmp(ss,"STOP")==0)
                break;
            else if(strcmp(ss,"ENQUEUE")==0)
                in();
            else
                out();
        }
        printf("\n");

    }


    return 0;
}

