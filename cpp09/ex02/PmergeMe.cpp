#include "PmergeMe.hpp"

CountUnit::CountUnit() : value(0) {}

CountUnit::CountUnit(unsigned int v) : value(v) {}

CountUnit::CountUnit(const CountUnit& copy) {
    *this = copy;
}

CountUnit::~CountUnit() {}

CountUnit&  CountUnit::operator=(const CountUnit& other) {
	if (this != &other)
		value = other.value;
	return *this;
}

bool CountUnit::operator<(const CountUnit& other) const
{
	++counter();
	return value < other.value;
}

bool CountUnit::operator>(const CountUnit& other) const
{
	++counter();
	return value > other.value;
}

bool CountUnit::operator>=(const CountUnit& other) const
{
	++counter();
	return value >= other.value;
}

bool CountUnit::operator<=(const CountUnit& other) const
{
	++counter();
	return value <= other.value;
}

unsigned int CountUnit::getValue() {
	return value;
}

static bool	isDigitStr(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

PmergeMe::PmergeMe() {
//	std::cout << "PmergeMe STD constructor called" << std::endl;
}

PmergeMe::PmergeMe(int ac, char** av) {
//	std::cout << "PmergeMe ac, av constructor called" << std::endl;
	_vector.reserve(ac - 1);
	unsigned long nb;
	for (int i = 1; av[i]; i++) {
		if (!isDigitStr(av[i]))
			throw errorPrint("input can only have digits");
		nb = strtoul(av[i], NULL, 10);
		if (nb < 0 || nb > UINT_MAX)
			throw errorPrint("input has numbers bigger them unsigned int max");
		_vector.push_back(static_cast<unsigned int>(nb));
		_list.push_back(static_cast<unsigned int>(nb));
	}
}

PmergeMe::PmergeMe(const PmergeMe& copy) {
//	std::cout << "PmergeMe COPY constructor called" << std::endl;
	*this = copy;
}

PmergeMe::~PmergeMe() {
//	std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
//	std::cout << "PmergeMe ASSIGNMENT operator called" << std::endl;
	if (this != &other) {
		_vector = other._vector;
		_list = other._list;
	}
	return *this;
}

void	PmergeMe::sort() {
	clock_t	startVec, endVec, startList, endList;
	
	printVector(true);
	startVec = std::clock();
	fordJohnsonSortVector(_vector);
	endVec = std::clock();
	printVector(false);
	std::cout << std::endl;

	size_t compVect = CountUnit::getCounter();
	
	printList(true);
	startList = std::clock();
	fordJohnsonSortList(_list);
	endList = std::clock();
	printList(false);
	std::cout << std::endl;


	std::cout << "Comparisons: " << compVect << std::endl;
	printTime(startVec, endVec, true);
	std::cout << std::endl;
	std::cout << "Comparisons: " << CountUnit::getCounter() << std::endl;
	printTime(startList, endList, false);
}

std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n) {
    std::vector<size_t> jacob;
    if (n == 0)
        return jacob;

    size_t j0 = 1;
    size_t j1 = 3;

    jacob.push_back(j0);

    while (j1 <= n && j1 > j0) {
        jacob.push_back(j1);

        if (j1 > (static_cast<size_t>(-1) - 2 * j0))
            break;

        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }

    return jacob;
}

void PmergeMe::fordJohnsonSortVector(std::vector<CountUnit>& data) {
    size_t n = data.size();
    if (n <= 1)
        return;

    std::vector<CountUnit> small;
    std::vector<CountUnit> large;
	vectSplit(data, small, large);

    bool hasLeftover = (n % 2 != 0);
    CountUnit leftover;
    if (hasLeftover)
        leftover = data[n - 1];

    fordJohnsonSortVector(large);

	std::vector<CountUnit> result = insertSmallVec(small, large);

    if (hasLeftover) {
        std::vector<CountUnit>::iterator pos = std::lower_bound(result.begin(), result.end(), leftover);
        result.insert(pos, leftover);
    }

    data.swap(result);
}

void	PmergeMe::vectSplit(std::vector<CountUnit>& data, std::vector<CountUnit>& small, std::vector<CountUnit>& large) {
	size_t n = data.size();
	
	for (size_t i = 0; i + 1 < n; i += 2) {
        if (data[i] < data[i + 1]) {
            small.push_back(data[i]);
            large.push_back(data[i + 1]);
        }
        else {
            small.push_back(data[i + 1]);
            large.push_back(data[i]);
        }
    }
}

std::vector<size_t>	PmergeMe::insertOrder(std::vector<CountUnit>& data) {
	std::vector<size_t> jacob = generateJacobsthalIndices(data.size());
	std::vector<size_t> insertionOrder;

	if (data.size() > 0) {
		insertionOrder.push_back(0);
		for (size_t i = 1; i < jacob.size(); ++i) {
			size_t start = jacob[i - 1];
			size_t end = std::min(jacob[i], data.size());
			for (size_t j = end; j > start; --j)
				insertionOrder.push_back(j - 1);
		}
		if (insertionOrder.size() < data.size()) {
			size_t last = jacob.empty() ? 0 : jacob.back();
			for (size_t j = data.size(); j > last; --j)
				insertionOrder.push_back(j - 1);
		}
	}

	return insertionOrder;
}

std::vector<CountUnit>	PmergeMe::insertSmallVec(std::vector<CountUnit>& smalls, std::vector<CountUnit>& larges) {
	std::vector<size_t> insertion_order = insertOrder(smalls);
    std::vector<CountUnit> result = larges;

    for (size_t k = 0; k < insertion_order.size(); ++k) {
        CountUnit val = smalls[insertion_order[k]];
        std::vector<CountUnit>::iterator pos = std::lower_bound(result.begin(), result.end(), val);
        result.insert(pos, val);
    }

	return result;
}

void PmergeMe::fordJohnsonSortList(std::list<CountUnit>& data) {
    size_t n = data.size();
    if (n <= 1)
        return;

    std::list<CountUnit> small;
    std::list<CountUnit> large;
	listSplit(data, small, large);

    bool hasLeftover = (n % 2 != 0);
    CountUnit leftover;
    if (hasLeftover) {
        leftover = small.back();
        small.pop_back();
    }

    fordJohnsonSortList(large);

	std::list<CountUnit> result = large;
	insertSmallList(small, result);

    if (hasLeftover)
    {
        std::list<CountUnit>::iterator pos = result.begin();
        for (; pos != result.end(); ++pos)
        {
            if (*pos >= leftover)
                break;
        }
        result.insert(pos, leftover);
    }

    data.swap(result);
}

void	PmergeMe::listSplit(std::list<CountUnit>& data, std::list<CountUnit>& small, std::list<CountUnit>& large) {
    std::list<CountUnit>::iterator it = data.begin();

    while (it != data.end()) {
        CountUnit a = *it++;
        if (it != data.end()) {
            CountUnit b = *it++;
            if (a < b) {
                small.push_back(a);
                large.push_back(b);
            }
            else {
                small.push_back(b);
                large.push_back(a);
            }
        }
        else {
            small.push_back(a);
            break;
        }
    }
}

void	PmergeMe::insertSmallList(std::list<CountUnit>& small, std::list<CountUnit>& result) {
    std::vector<CountUnit> smallVec(small.begin(), small.end());
    std::vector<size_t> insertion_order = insertOrder(smallVec);

    for (size_t k = 0; k < insertion_order.size(); ++k){
        CountUnit val = smallVec[insertion_order[k]];
        std::list<CountUnit>::iterator pos = result.begin();
        for (; pos != result.end(); ++pos) {
            if (*pos >= val)
                break;
        }
        result.insert(pos, val);
    }
}

void	PmergeMe::printVector(bool before) {
	if (before)
		std::cout << "Before (vector): ";
	else
		std::cout << "After (vector): ";
	
	for (unsigned int i = 0; i < _vector.size(); i++)
		std::cout << _vector[i].getValue() << ' ';
	std::cout << std::endl;
}

void	PmergeMe::printList(bool before) {
	if (before)
		std::cout << "Before (list): ";
	else
		std::cout << "After (list): ";
	
	for (std::list<CountUnit>::iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << it->getValue() << ' ';
	std::cout << std::endl;
}

void	PmergeMe::printTime(clock_t start, clock_t end, bool vector) {
	double	time;

	if (vector)
		std::cout << "Time it took vector: ";
	else
		std::cout << "Time it took list: ";

	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << time << " seconds" << std::endl;
}

errorPrint::errorPrint(std::string msg) : std::runtime_error("Error: " + msg) {}