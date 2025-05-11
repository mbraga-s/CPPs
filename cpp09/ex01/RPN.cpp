
#include "RPN.hpp"

RPN::RPN(void)
{

}

RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN::~RPN(void)
{

}

RPN &RPN::operator=(const RPN& src)
{
	(void)src;
	return *this;
}

int RPN::parse_input(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && !isdigit(str[i]))	
			return (1);
	}
	return (0);
}

void RPN::reverse_polish(char *input)
{
	for (int i = 0; input[i]; i++)
	{
		if (isdigit(input[i]))
			stk.push(static_cast<long int>(input[i] - '0'));
		else if (input[i] == ' ')
			continue;
		else
		{
			if (stk.size() < 2)
			{
				std::cerr << "Error: Wrong syntax" << std::endl;
				return;
			}
			long int b = stk.top();
			stk.pop();
			long int a = stk.top();
			stk.pop();
			long int total = 0;
			switch(input[i])
			{
				case '+':
				{
					total = a + b;
					break;
				}
				case '-':
				{
					total = a - b;
					break;
				}
				case '*':
				{
					total = a * b;
					break;
				}
				case '/':
				{
					if (b == 0)
					{
						std::cerr << "Error: Divide by 0" << std::endl;
						return ;
					}
					total = a / b;
					break;
				}
				default:
					std::cerr << "Error: Invalid input" << std::endl;
			}
			if (total < std::numeric_limits<int>::min() || total > std::numeric_limits<int>::max())
			{
				std::cerr << "Error: Integer overflow" << std::endl;
				return ;
			}
			stk.push(total);
		}
	}
	if (stk.size() != 1)
	{
		std::cerr << "Error: Stack contains too many elements" << std::endl;
		return ;
	}
	std::cout << "Result: " << stk.top() << std::endl;
}