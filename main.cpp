#include <iostream>
#include <stack>

struct Leksema
{
	char type;
	double value;
};


void Math(std::stack <Leksema> &Stack_n , std::stack <Leksema> &Stack_oper, Leksema &item)
{
	double a = Stack_n.top().value;
	double b, c;
	Stack_n.pop();
	switch (Stack_oper.top().type)
	{
	case '+':
		b = Stack_n.top().value;
		Stack_n.pop();
	    c = a + b;
		Stack_oper.pop();
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		break;
	case '-':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = b - a;
		Stack_oper.pop();
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		break;
	case '*':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = a * b;
		Stack_oper.pop();
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		break;
	case '/':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = b / a;
		Stack_oper.pop();
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		break;
	}
}

int getrang(char op)
{
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

int main()
{
	double value;
	std::stack <Leksema> Stack_n;
	std::stack <Leksema> Stack_oper;
	Leksema item;

	while (1)
	{
		char ch = std::cin.peek();
		if (ch == '\n')
			break;
		if (ch >= '0' && ch <= '9')
		{
			std::cin >> value;
			item.type = '0';
			item.value = value;
			Stack_n.push(item); // operation pushing item in stack with value
			continue;
		}
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			if (Stack_oper.size() == 0) // if stack with operations empty
			{
				item.type = ch;
				item.value = 0;
				Stack_oper.push(item); //operation pushing item in stack with operation
				std::cin.ignore();
				continue;
			}
			else if (Stack_oper.size() != 0 && getrang(ch) > getrang(Stack_oper.top().type)) // if stack with operations not empty and operator rang more than top operator in stack
			{
				item.type = ch;
				item.value = 0;
				Stack_oper.push(item);
				std::cin.ignore();
				continue;
			}
			else if (Stack_oper.size() != 0 && getrang(ch) <= getrang(Stack_oper.top().type)) // if stack with operations not empty and operator rang less than top operator in stack
			{
				Math(Stack_n, Stack_oper, item);
				continue;
			}
		}
	}
	while (!Stack_oper.empty()) {
		Math(Stack_n, Stack_oper, item);
	}
	std::cout << Stack_n.top().value;
	return 0;
}