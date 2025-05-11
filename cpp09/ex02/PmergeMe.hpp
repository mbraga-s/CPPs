
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <cstdlib>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		int add_to_vector(int argc, char **argv);
		int add_to_list(int argc, char **argv);
		void print_vector();
		void print_list();

		int ford_johnson_vector(std::vector<int>& current);
		int ford_johnson_list(std::list<int>& current);
		void  binary_ins_vector(std::vector<int>& main, int nmb);
		void  binary_ins_list(std::list<int>& main, int nmb);

		std::vector<int> s_vector;
		std::list<int> s_list;

	private:
		PmergeMe(const PmergeMe& copy);
		PmergeMe &operator=(const PmergeMe& src);

};


#endif