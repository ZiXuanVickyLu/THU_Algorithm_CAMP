#include <bits/stdc++.h>
#include<string>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */
static int marker=0;
struct mylist
{
    string names="NaN";
};
struct mylist data_[100000];
void push(string name) {
    ++marker;
    data_[marker].names = name;
}

// 弹出栈顶
// 返回值：被弹出人的姓名
string pop() {
    --marker;
    string temp = data_[marker + 1].names;
    data_[marker + 1].names = "NaN";
        return temp;
}

// 询问栈中某个位置上的人的姓名（栈底位置为1，向栈顶方向的位置依次递增）
// pos：询问的位置
// 返回值：pos位置上人的姓名
string query(int pos) {
    return data_[pos].names;
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
            push(name);
        } else if (op == 2) {
            printf("%s\n", pop().c_str());
        } else {
            int pos;
            scanf("%d", &pos);
            printf("%s\n", query(pos).c_str());
        }
    }
    return 0;
}
