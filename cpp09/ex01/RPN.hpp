
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cctype>
# include <limits>

class RPN
{
	public:
		RPN(void);
		~RPN(void);
		
		int parse_input(char *str);
		void reverse_polish(char *input);
		
	private:
		RPN(const RPN& copy);
		RPN &operator=(const RPN& src);
		std::stack<long int> stk;
};

#endif