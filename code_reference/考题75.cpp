#include<iostream>
#include<stdio.h>
#include<algorithm>
#define MAXN 100000

using namespace std;


struct node{
    int x, y;
    void read() {
        scanf("%d%d", &x, &y);
    }
};

struct segment {
    node a, b;
    void read() {
        a.read();
        b.read();
    }
};

double operator^(node a, node b) { return (double)a.x * b.y - a.y * b.x; }
node operator+(node a, node b) {
    return node{ a.x + b.x,a.y + b.y };
}
node operator-(node a, node b) {
    return node{ a.x-b.x,a.y -b.y };
}
// n: 苹果树棵数
int n;
// p: 所有苹果树的坐标
node p[MAXN + 10];
// s: 每条篱笆所在的线段
node pol[3];
segment s[3];
bool toleft(segment seg, node c)
{
    return( (seg.b - seg.a) ^ (c-seg.a)) < 0;
}
bool iscross(segment a,segment b)
{
    if ((toleft(a, b.a) ^ toleft(a, b.b)) && (toleft(b, a.a) ^ toleft(b, a.b)))
        return true;
    return false;
}
bool isinline(segment a, segment b)
{
    if ((((a.b-a.a)^(b.b-a.a))==0)&&(b.b.x<=max(a.a.x,a.b.x)&&b.b.x>=min(a.a.x,a.b.x)))
        return true;
    if ((((a.b - a.a) ^ (b.a - a.a)) == 0) && (b.a.x <= max(a.a.x, a.b.x) && b.a.x >= min(a.a.x, a.b.x)))
        return true;
    if ((((b.b - b.a) ^ (a.b - b.a)) == 0) && (a.b.x <= max(b.a.x, b.b.x) && a.b.x >= min(b.a.x, b.b.x)))
        return true;
    if ((((b.b - b.a) ^ (a.b - b.a)) == 0) && (a.b.x <= max(b.a.x, b.b.x) && a.b.x >= min(b.a.x, b.b.x)))
        return true;
    return false;
}
bool isclose()
{
    bool ans=1;
    for (int i = 0; i < 3; i++)
        ans &= (iscross(s[i % 3], s[(i + 1) % 3]) || isinline(s[i % 3], s[(i + 1) % 3]));
    return ans;
}

bool isin(int i)
{
    if (toleft(s[0], p[i]) && toleft(s[1], p[i]) && toleft(s[2], p[i]))
        return true;
    if ((!toleft(s[0], p[i])) && (!toleft(s[1], p[i])) && (!toleft(s[2], p[i])))
        return true;
    return false;
}

bool dir()
{
    return (toleft(s[0], s[1].b) && toleft(s[1], s[2].b) && (toleft(s[2], s[0].b))) || (!toleft(s[0], s[1].b) && (!toleft(s[1], s[2].b)) && (!toleft(s[2], s[0].b)));
}
void calc_polar()
{
    for (int i = 0; i < 1; i++)
    {

        if (dir())//000
            return;
        swap(s[2].a, s[2].b);

        if (dir())//001
            return;
        swap(s[1].a, s[1].b);

        if (dir())//011
            return;
        swap(s[2].a, s[2].b);

         if (dir()) //010
              return;
         swap(s[1].a, s[1].b);//000
         swap(s[0].a, s[0].b);//100
             
        
    }

 }

// 在此实现你的代码，返回答案
int get_ans() {
    int isint = 0;
    if (isclose())
    {
        calc_polar();
        s;
       
        for (int i = 0; i < n; i++)
            if (isin(i))
                isint++;
    }
    
    return (n - isint);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) p[i].read();
    for (int i = 0; i < 3; i++) s[i].read();

    int ans = get_ans();
    printf("%d\n", ans);

    return 0;
}