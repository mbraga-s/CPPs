
#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int> A;
	// std::stack<int> B;

	A.push(1);
	A.push(15);
	A.pop();
	A.push(2);
	A.push(20);
	A.pop();
	A.push(3);
	A.push(4);

	// std::stack<int>::iterator it = B.begin(); //Can't compile as stack doesn't have an iterator.
	MutantStack<int>::iterator it_b = A.begin();
	MutantStack<int>::iterator it_e = A.end();
	while (it_b != it_e)
	{
		std::cout << "Stack value: " << *it_b << std::endl;
		it_b++;
	}
	return (0);
}
