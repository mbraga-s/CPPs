
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

int PmergeMe::add_to_vector(int argc, char **argv)
{
	for (int i = 1; i < argc; i++) 
	{
		int nmb = std::atoi(argv[i]);
		if (nmb <= 0)
		{
			std::cerr << "Error: Invalid input" << std::endl;
			return (1);
		}
		s_vector.push_back(nmb);
	}
	return (0);
}

int PmergeMe::add_to_list(int argc, char **argv)
{
		for (int i = 1; i < argc; i++) 
	{
		int nmb = std::atoi(argv[i]);
		if (nmb <= 0)
		{
			std::cerr << "Error: Invalid input" << std::endl;
			return (1);
		}
		s_list.push_back(nmb);
	}
	return (0);
}

void PmergeMe::print_vector()
{
	std::vector<int>::iterator it_b = s_vector.begin();
	std::vector<int>::iterator it_e = s_vector.end();
	while (it_b != it_e)
	{
		std::cout << *it_b << " ";
		it_b++;
	}
	std::cout << std::endl;
}

void PmergeMe::print_list()
{	
	std::list<int>::iterator it_b = s_list.begin();
	std::list<int>::iterator it_e = s_list.end();
	while (it_b != it_e)
	{
		std::cout << *it_b << " ";
		it_b++;
	}
	std::cout << std::endl;

}

int PmergeMe::ford_johnson_vector(std::vector<int>& current)
{
	std::vector<int> main;
	std::vector<int> pend;
	std::vector<int>::iterator it_b = current.begin();
	std::vector<int>::iterator it_e = current.end();
		
	if (current.size() <= 1)
		return (0);
	while (it_b + 1 < it_e)
	{
		if (*it_b > *(it_b + 1))
		{
			main.push_back(*it_b);
			pend.push_back(*(it_b + 1));
		}
		else
		{
			main.push_back(*(it_b + 1));
			pend.push_back(*it_b);
		}
		it_b = it_b + 2;
	}
	ford_johnson_vector(main);
	if (current.size() % 2 == 1)
		pend.push_back(*(it_e - 1));

	std::vector<int>::iterator it_pb = pend.begin();
	std::vector<int>::iterator it_pe = pend.end();

	for (it_b = it_pb; it_b < it_pe; ++it_b)
		binary_ins_vector(main, *it_b);
	current = main;
	return (0);
}

void  PmergeMe::binary_ins_vector(std::vector<int>& main, int nmb)
{
	std::vector<int>::iterator left = main.begin();
	std::vector<int>::iterator right = main.end() - 1;
	std::vector<int>::iterator middle;

	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if (*middle > nmb)
			right = middle - 1;
		else
			left = middle + 1;
	}
	main.insert(left, nmb);
}



int PmergeMe::ford_johnson_list(std::list<int>& current)
{
	std::list<int> main;
	std::list<int> pend;
	std::list<int>::iterator it_b = current.begin();
	std::list<int>::iterator it_next = current.begin();
		
	if (current.size() <= 1)
		return (0);
	it_next++;
	while (it_b != current.end() && it_next != current.end())
	{
		if (*it_b > *it_next)
		{
			main.push_back(*it_b);
			pend.push_back(*it_next);
		}
		else
		{
			main.push_back(*it_next);
			pend.push_back(*it_b);
		}
		it_b++;
		it_b++;
		it_next++;
		it_next++;
	}
	ford_johnson_list(main);
	if (current.size() % 2 == 1)
	{
		it_next = current.end();
		--it_next;
		pend.push_back(*it_next);
	}

	std::list<int>::iterator it_pb = pend.begin();
	std::list<int>::iterator it_pe = pend.end();

	for (it_b = it_pb; it_b != it_pe; ++it_b)
		binary_ins_list(main, *it_b);
	current = main;
	return(0);
}

void PmergeMe::binary_ins_list(std::list<int>& main, int nmb)
{
	std::list<int>::iterator it = main.begin();

	while (it != main.end() && *it < nmb)
		++it;
	main.insert(it, nmb);
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& src)
{
	(void)src;
	return *this;
}
