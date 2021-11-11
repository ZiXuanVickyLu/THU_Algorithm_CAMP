#include <stack>
#include<iterator>
#include<list>
#include<iostream>
#include<utility>
#include<list>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */
typedef pair<list<char>::iterator, list<char>::iterator> pii;
list<char> ans;
char optc[] = { '*','/','+','-' };
int a[5][5] = {//front:当前；back：buffer_top
/*		top  	* / + - \0 */ // p_vs_top: 0"==",2">",1"<" >:get_into_stack,=:pop_a_opt,<:pop_2_num_1_opt
	/*p	* */	1,1,2,2,2,
	/*	/ */	1,1,2,2,2,
	/*	+ */	1,1,1,1,2,
	/*	- */	1,1,1,1,2,
	/*	\0 */	1,1,1,1,0,
};
// 给定一个常量表达式 str，求它在模 2^32 意义下的值
// str：如题意
// 返回值：常量表达式在模 2^32 意义下的值
bool isdigital(char s)
{
	if ((int)s - '0' >= 0 && (int)s - '0' <= 9)
		return true;
	return false;
}

unsigned int calc_opt(char s)
{
	switch (s) {
	case '*':
		return 0;
	case '/':
		return 1;
	case '+':
		return 2;
	case '-':
		return 3;
	default:
		return 4;
	}
}
 pii calc_num(int opt, pii numf, pii numb)
{
		 auto fi = ans.insert(numf.first, '(');
		 ans.insert(numb.first, optc[opt]);
		 ans.emplace_back(')');
		 auto se = next(numb.second);
		 return make_pair(fi, se);
}
void getAnswer(string str)
{
	stack<unsigned int> opt;
	stack<pii> num;
	stack<char> calc;
	//_initialize
	opt.push(4);
	//_start
	for (int i = str.size(); i >= 0; --i)
		calc.push(str[i]);
	while (!calc.empty())
	{
		char Ele = calc.top();
		if (isdigital(Ele))//isditial,push_into_stack_of_num
		{
			auto se=ans.insert(ans.end(),Ele);
			num.push(make_pair(se,se));
			calc.pop();
		}
		else
		{
			int p = calc_opt(Ele), tops = opt.top();
			switch (a[p][tops]) {
			case 1://pop_2_num_1_opt
			{
				pii numbac = num.top();
				num.pop();
				pii numfro = num.top();
				num.pop();
				opt.pop();
				num.push(calc_num(tops, numfro, numbac));
				break;
			}
			case 2://push
			{
				calc.pop();
				opt.push(p);
				break;
			}
			default: //clear_a_pair'\0'
			{
				opt.pop();
				calc.pop();
				break;
			}

			}
		}

	}
}

// ================= 代码实现结束 =================

int main()
{
	string str;
	cin >> str;
	getAnswer(str);
	for (auto Ele : ans)
		printf("%c", Ele);
	return 0;
}