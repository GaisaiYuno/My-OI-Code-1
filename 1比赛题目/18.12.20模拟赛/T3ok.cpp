#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,m;
double x[maxn];
double y[maxn];

double get_sumx(double l,double r) {
    return (l+r)*(r-l+1)/2;
}

double get_sumsqx(double l,double r) {
    return r*(r+1)*(2*r+1)/6-(l-1)*l*(2*l-1)/6;
}

struct segment_tree {
#define lson pos<<1
#define rson pos<<1|1
    struct node {
        int l;
        int r;
        double sx;
        double sy;
        double sqx;
        double xy;
        double addx;
        double addy;
        double len() {
            return r-l+1;
        }
        bool set;
    } tree[maxn<<2];

    void push_up(int pos) {
        tree[pos].sx=tree[lson].sx+tree[rson].sx;
        tree[pos].sy=tree[lson].sy+tree[rson].sy;
        tree[pos].sqx=tree[lson].sqx+tree[rson].sqx;
        tree[pos].xy=tree[lson].xy+tree[rson].xy;
    }

    void push_down(int pos) {
        int son=pos<<1;
        if(tree[pos].set) {
            for(int i=0; i<=1; i++) {
                son=son|i;
                tree[son].addx=tree[son].addy=0;
                tree[son].sx=tree[son].sy=get_sumx(tree[son].l,tree[son].r);
                tree[son].xy=tree[son].sqx=get_sumsqx(tree[son].l,tree[son].r);
                tree[son].set=1;
            }
            tree[pos].set=0;
        }
        if(tree[pos].addx||tree[pos].addy) {
        	son=pos<<1;//之前下推set标记后son会变，并不等于pos，所以要重新赋值 
            double mkx=tree[pos].addx;
            double mky=tree[pos].addy;
            for(int i=0; i<=1; i++) {
                son=son|i;
                tree[son].addx+=mkx;
                tree[son].addy+=mky;
                tree[son].sqx+=2*tree[son].sx*mkx+mkx*mkx*tree[son].len();
                tree[son].xy+=tree[son].len()*mkx*mky+tree[son].sx*mky+tree[son].sy*mkx;
                tree[son].sx+=mkx*tree[son].len();
                tree[son].sy+=mky*tree[son].len();
            }
            tree[pos].addx=tree[pos].addy=0;
        }
    }


    void build(int l,int r,int pos,double *x,double *y) {
        tree[pos].l=l;
        tree[pos].r=r;
        if(l==r) {
            tree[pos].sx=x[l];
            tree[pos].sy=y[l];
            tree[pos].sqx=x[l]*x[l];
            tree[pos].xy=x[l]*y[l];
            return;
        }
        int mid=(l+r)>>1;
        build(l,mid,pos<<1,x,y);
        build(mid+1,r,pos<<1|1,x,y);
        push_up(pos);
    }

    void add_segment(int L,int R,int pos,double s,double t) {
        if(L<=tree[pos].l&&R>=tree[pos].r) {
            tree[pos].addx+=s;
            tree[pos].addy+=t;
            tree[pos].xy+=tree[pos].sx*t+tree[pos].sy*s+s*t*tree[pos].len();
            tree[pos].sqx+=2*tree[pos].sx*s+s*s*tree[pos].len();
            tree[pos].sx+=s*tree[pos].len();
            tree[pos].sy+=t*tree[pos].len();
            return;
        }
        push_down(pos);
        int mid=(tree[pos].l+tree[pos].r)>>1;
        if(L<=mid) add_segment(L,R,pos<<1,s,t);
        if(R>mid) add_segment(L,R,pos<<1|1,s,t);
        push_up(pos);
    }

    void set_segment(int L,int R,int pos) {
        if(L<=tree[pos].l&&R>=tree[pos].r) {
            tree[pos].set=1;
            tree[pos].addx=tree[pos].addy=0;
            tree[pos].sx=tree[pos].sy=get_sumx(tree[pos].l,tree[pos].r);
            tree[pos].sqx=tree[pos].xy=get_sumsqx(tree[pos].l,tree[pos].r);
            return;
        }
        push_down(pos);
        int mid=(tree[pos].l+tree[pos].r)>>1;
        if(L<=mid) set_segment(L,R,pos<<1);
        if(R>mid) set_segment(L,R,pos<<1|1);
        push_up(pos);
    }

    double query_sx(int L,int R,int pos) {
        if(L<=tree[pos].l&&R>=tree[pos].r) {
            return tree[pos].sx;
        }
        push_down(pos);
        double ans=0;
        int mid=(tree[pos].l+tree[pos].r)>>1;
        if(L<=mid) ans+=query_sx(L,R,pos<<1);
        if(R>mid) ans+=query_sx(L,R,pos<<1|1);
        return ans;
    }

    double query_sy(int L,int R,int pos) {
        if(L<=tree[pos].l&&R>=tree[pos].r) {
            return tree[pos].sy;
        }
        push_down(pos);
        double ans=0;
        int mid=(tree[pos].l+tree[pos].r)>>1;
        if(L<=mid) ans+=query_sy(L,R,pos<<1);
        if(R>mid) ans+=query_sy(L,R,pos<<1|1);
        return ans;
    }

    double query_sqx(int L,int R,int pos) {
        if(L<=tree[pos].l&&R>=tree[pos].r) {
            return tree[pos].sqx;
        }
        push_down(pos);
        double ans=0;
        int mid=(tree[pos].l+tree[pos].r)>>1;
        if(L<=mid) ans+=query_sqx(L,R,pos<<1);
        if(R>mid) ans+=query_sqx(L,R,pos<<1|1);
        return ans;
    }

    double query_xy(int L,int R,int pos) {
        if(L<=tree[pos].l&&R>=tree[pos].r) {
            return tree[pos].xy;
        }
        push_down(pos);
        double ans=0;
        int mid=(tree[pos].l+tree[pos].r)>>1;
        if(L<=mid) ans+=query_xy(L,R,pos<<1);
        if(R>mid) ans+=query_xy(L,R,pos<<1|1);
        return ans;
    }

#undef lson
#undef rson
} T;

void debug(){
	printf("debug:\n");
	for(int i=1;i<=n;i++){
		printf("%.0f ",T.query_sx(i,i,1)); 
	} 
	printf("\n");
	for(int i=1;i<=n;i++){
		printf("%.0f ",T.query_sy(i,i,1)); 
	} 
	printf("\n");
	printf("\n");
}
int main() {
    int cmd,l,r;
    double s,t;
    double up,down,ax,ay;
    double sumx,sumy,sumxy,sumsqx;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%lf",&x[i]);
    }
    for(int i=1; i<=n; i++) {
        scanf("%lf",&y[i]);
    }
    T.build(1,n,1,x,y);
    for(int i=1; i<=m; i++) {
        scanf("%d",&cmd);
        if(cmd==2) {
            scanf("%d %d %lf %lf",&l,&r,&s,&t);
            T.add_segment(l,r,1,s,t);
        } else if(cmd==3) {
            scanf("%d %d %lf %lf",&l,&r,&s,&t);
            T.set_segment(l,r,1);
            T.add_segment(l,r,1,s,t);
        } else {
            scanf("%d %d",&l,&r);
            sumx=T.query_sx(l,r,1);
            sumy=T.query_sy(l,r,1);
            sumxy=T.query_xy(l,r,1);
            sumsqx=T.query_sqx(l,r,1);
//			printf("x=%.0f y=%.0f xy=%.0f x^2=%.0f\n",sumx,sumy,sumxy,sumsqx);
            ax=sumx/(r-l+1);
            ay=sumy/(r-l+1);
            up=ax*ay*(r-l+1)+sumxy-ay*sumx-ax*sumy;
            down=sumsqx-2*ax*sumx+(r-l+1)*ax*ax;
            printf("%.10f\n",up/down);
        }
//        debug();
    }
}
/*
8 10
8 4 9 6 10 5 10 9 
6 6 9 10 7 3 8 3 
1 4 6
1 7 7
3 4 8 3 3
2 2 8 3 2
3 5 5 6 9
3 1 8 8 3
1 1 7
2 3 7 3 5
3 6 7 1 7
1 1 3
*/
