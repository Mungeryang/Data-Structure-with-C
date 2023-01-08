#include"Expression.h"

int main()
{
	char opnd;
	char *exp = "(1+3)*2/4#";
	opnd = EvaluateExpression(exp);
	printf("作为用例，%s的计算结果为：%d",exp,opnd - '0');
	return 0;
}
