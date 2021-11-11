#include<string>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

// ================= 代码实现开始 =================
queue<string> a;
int c = 0;
void equeue(string name) {
    a.push(name);
    c++;
}
string dqueue() {
    string temp;
    temp = a.front();
    a.pop();
    --c;
    return temp;
    
}

// 询问队列中某个位置上的人的姓名（队首位置为1，往后位置依次递增）
// pos：询问的位置
// 返回值：pos位置上人的姓名
string query(int pos) {

    int i;
    for (i = 1; i < pos; i++)
    {
        a.push(a.front());
        a.pop();
    }
    string temp = a.front();
    for (; i <= c; ++i)
    {
        a.push(a.front());
        a.pop();
    }
    return temp;
}

// ================= 代码实现结束 =================

int main() {
    int n;
    scanf("%d", &n);
    char name[20];
    for (; n--; ) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%s", name);
            equeue(name);
        } else if (op == 2) {
            printf("%s\n", dqueue().c_str());
        } else {
            int pos;
            scanf("%d", &pos);
            printf("%s\n", query(pos).c_str());
        }
    }
    return 0;
}
