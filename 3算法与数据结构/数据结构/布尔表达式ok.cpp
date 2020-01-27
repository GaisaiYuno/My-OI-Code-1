#include <iostream>
#include <stack>
#include <string>
using namespace std;
int clean(string& s);
int deal(string s);
void neg();
char calcu();
stack <char> mark;
stack <char> num;
int main()
{
    string line;
    while (1)
    {
    	getline(cin, line);
        clean(line);//去除空格

        deal(line);//进行处理

        while (!mark.empty())
        {
            num.push(calcu());
        }

        cout << num.top() << endl;
    }
}

int clean(string& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            s.erase(i, 1);
        }
    }
    return 0;
}

int deal(string s)//进行处理
{
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == 'F' || c == 'V')
        {
            num.push(c);
        }
        else if (c == '&' || c == '|')
        {
            while (!mark.empty() && mark.top() == '!')
            {
                neg();
            }
            while (c == '|' && !mark.empty() && mark.top() == '&')
            {
                num.push(calcu());
            }
            mark.push(c);
        }
        else if (c == '!')
        {
            mark.push(c);
        }
        else if (c == '(')
        {
            mark.push(c);
        }
        else if (c == ')')
        {
            while (!mark.empty() && mark.top() == '!')
            {
                neg();
            }
            while (mark.top() != '(')
            {
                num.push(calcu());
            }
            mark.pop();

        }
    }
    return 0;
}
char calcu()//单次操作-且操作/或操作
{
    char x;
    x = mark.top();
    mark.pop();
    if (x == '!')
    {
        char tmp = num.top();
        num.pop();
        if (tmp == 'F')
        {
            return 'V';
        }
        else
        {
            return 'F';
        }
    }

    else
    {
        char value1, value2;

        value1 = num.top();
        num.pop();
        value2 = num.top();
        num.pop();

        if (value1 == 'V' && value2 == 'V')
        {
            return 'V';
        }
        else if (value1 == 'F' && value2 == 'F')
        {
            return 'F';
        }
        else if ((value1 == 'V' || value2 == 'V') && x == '|')
        {
            return 'V';
        }
        else if ((value1 == 'F' || value2 == 'F') && x == '&')
        {
            return 'F';
        }
    }
}
void neg() //!操作
{
    char tmp = num.top();
    num.pop();
    if (tmp == 'F')
    {
        num.push('V');
    }
    else
    {
        num.push('F');
    }
    mark.pop();
}
