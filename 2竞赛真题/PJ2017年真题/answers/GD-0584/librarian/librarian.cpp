#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define min(a,b) a<b?a:b

using namespace std;
const int oo=2147483647;
int n,q,book_li,book_cus,book_cus_len,_book[10000005];
int main()
{
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
    _book[2123]=oo;
    for (int i=1;i<=10000005;i++)
      _book[i]=oo;
    scanf("%d%d",&n,&q);
    for (int i=1; i<=n; i++)
    {
      scanf("%d",&book_li);
      _book[book_li]=min(_book[book_li],book_li);
      int MOD=10;
      //cout << book_li <<endl;
      while (book_li/MOD)
      {
          //cout << _book[book_li%MOD] << endl;
         _book[book_li%MOD]=min(_book[book_li%MOD],book_li);
       //  printf("%d %d %d\n",book_li,MOD,_book[book_li%MOD]);
       //   cout << _book[book_li%MOD] << endl;
         MOD*=10;//100 1000
      
      }
    }
    for (int i=1; i<=q; i++)
    {
        scanf("%d%d",&book_cus_len,&book_cus);
        if (_book[book_cus]!=oo) printf("%d\n",_book[book_cus]);
        else printf("-1\n");
    }
    return 0;
}
