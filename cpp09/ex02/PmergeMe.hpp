#pragma once 

#include <ios>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include <climits>
#include <ctime>

class CountUnit
{
	protected:
		unsigned int value;

		static size_t& counter()
		{
			static size_t count = 0; // function-local static (not global variable)
			return count;
		}

	public:
		CountUnit();
		CountUnit(unsigned int);
		CountUnit(const CountUnit&);
		~CountUnit();

		CountUnit&  operator=(const CountUnit&);
		bool operator<(const CountUnit&) const;
		bool operator>(const CountUnit&) const;
		bool operator>=(const CountUnit&) const;
		bool operator<=(const CountUnit&) const;

		static void resetCounter() { counter() = 0; }
		size_t getCounter() { return counter(); }
		unsigned int getValue();
};

class PmergeMe : CountUnit {
		std::vector<CountUnit>	_vector;
		std::list<CountUnit>	_list;

		void	fordJohnsonSortVector(std::vector<CountUnit>&);
		void	vectSplit(std::vector<CountUnit>&, std::vector<CountUnit>&, std::vector<CountUnit>&);
		std::vector<size_t>	insertOrder(std::vector<CountUnit>&);
		std::vector<CountUnit>	insertSmallVec(std::vector<CountUnit>&, std::vector<CountUnit>&);
		void	fordJohnsonSortList(std::list<CountUnit>&);
		void	listSplit(std::list<CountUnit>&, std::list<CountUnit>&, std::list<CountUnit>&);
		void	insertSmallList(std::list<CountUnit>&, std::list<CountUnit>&);

	public:
		PmergeMe();
		PmergeMe(int, char**);
		PmergeMe(const PmergeMe&);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe&);
		void	sort();
		std::vector<size_t> generateJacobsthalIndices(size_t);
		void	printVector(bool);
		void	printList(bool);
		void	printTime(clock_t, clock_t, bool);
};

class errorPrint : public std::runtime_error {
	public:
		errorPrint(std::string msg);
};