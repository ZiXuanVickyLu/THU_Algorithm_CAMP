#include <stack>
#include<iostream>
using namespace std;

// ================= ����ʵ�ֿ�ʼ =================

/* �������ﶨ������Ҫ��ȫ�ֱ��� */

int a[7][7] = {//front:��ǰ��back��buffer_top
/*		top	* + - & ^ | \0 */ // p_vs_top: 0"==",2">",1"<" >:get_into_stack,=:pop_a_opt,<:pop_2_num_1_opt
	/*p	* */	1,2,2,2,2,2,2,
	/*	+ */	1,1,1,2,2,2,2,
	/*	- */	1,1,1,2,2,2,2,
	/*	& */	1,1,1,1,2,2,2,
	/*	^ */	1,1,1,1,1,2,2,
	/*	| */	1,1,1,1,1,2,2,
	/*	\0 */	1,1,1,1,1,1,0
};
// ����һ���������ʽ str��������ģ 2^32 �����µ�ֵ
// str��������
// ����ֵ���������ʽ��ģ 2^32 �����µ�ֵ
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
	case '+':
		return 1;
	case '-':
		return 2;
	case '&':
		return 3;
	case '^':
		return 4;
	case '|':
		return 5;
	default:
		return 6;
	}
}
unsigned int calc_num(int opt, int numf, int numb)
{
	switch (opt) {
	case 0:
		return numf * numb;
	case 1:
		return numf + numb;
	case 2:
		return numf - numb;
	case 3:
		return numf & numb;
	case 4:
		return numf ^ numb;
	case 5:
		return numf | numb;
	}
}
unsigned int getAnswer(string str)
{
	stack<unsigned int> opt;
	stack<unsigned int> num;
	stack<char> calc;
	//_initialize
	opt.push(6);
	bool last_num = 0;
	//_start
	for (int i = str.size(); i >= 0; --i)
		calc.push(str[i]);
	while (!calc.empty())
	{
		char Ele = calc.top();
		if (isdigital(Ele))//isditial,push_into_stack_of_num
		{
			if (last_num)
			{
				int tmp = 10 * num.top();
				num.pop();
				num.push(tmp + (int)(Ele - '0'));
			}
			else
				num.push((int)(Ele - '0'));

			calc.pop();
			last_num = 1;
		}
		else
		{
			int p = calc_opt(Ele), tops = opt.top();

			switch (a[p][tops]) {
			case 1://pop_2_num_1_opt
			{
				int numbac = num.top();
				num.pop();
				int numfro = num.top();
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
			last_num = 0;
		}

	}
	return num.top();
}

// ================= ����ʵ�ֽ��� =================

int main()
{
	string str;
	cin >> str;
	cout << getAnswer(str) << endl;
	return 0;
}