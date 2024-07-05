#include "PmergeMe.hpp"

int number_control(int ac, char **av){
    int i = 1;
    while (i < ac) {
        if (std::atoi(av[i]) == 0) {
            std::cerr << "Error: '" << av[i] << "' is not a number" << std::endl;
            return 1;
        }
        i++;
    }
    return (0);
}

void add_container(std::vector<int> &container, int ac, char **av) {
    int i = 1;
    while (i < ac) {
        container.push_back(std::atoi(av[i]));
        i++;
    }
}

void add_container(std::list<int> &container, int ac, char **av) {
    int i = 1;
    while (i < ac) {
        container.push_back(std::atoi(av[i]));
        i++;
    }
}

void printContainer(std::vector<int> v, std::string str) {
    std::cout << str << ":   ";
    std::vector<int>::iterator begin = v.begin();
     std::vector<int>::iterator end = v.end();
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

template <typename T>
void insertSort(T &l, double &time) {
    std::clock_t start = clock(); 
    typename T::iterator begin = l.begin();
    typename T::iterator end = l.end();
    while (begin != end) {
        int current = *(begin);
        int previous = *(std::prev(begin)); 
        while (current < previous && begin != l.begin())
        {
            std::iter_swap(begin, std::prev(begin));
            begin--;
            current = *(begin);
            previous = *(std::prev(begin));
        }
        begin++;
    }
    std::clock_t finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
}

void printTime(double time, int size, std::string type) {
    std::cout << "Time to process a range of " << size << " elements with " << type << " : " << std::fixed << std::setprecision(6) << time << " us" << std::endl;
}

void mergeSort(std::vector<int> &l, double &time) {
    std::clock_t start = clock(); 
    if (l.size() <= 5)
    {
        insertSort(l, time);
        return;
    }
    std::vector<int>::iterator begin = l.begin();
    std::vector<int>::iterator middle = l.begin() + (l.end() - l.begin()) / 2;
    std::vector<int>::iterator end = l.end();
    std::vector<int> left(begin, middle);
    std::vector<int> right(middle, end);
    mergeSort(left, time);
    mergeSort(right, time);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), l.begin());
    std::clock_t finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
}

void mergeSort(std::list<int> &l, double &time) {
    std::clock_t start = clock(); 
    if (l.size() <= 5)
    {
        insertSort(l, time);
        return;
    }
    std::list<int>::iterator begin = l.begin();
    std::list<int>::iterator middle = l.begin();
    std::advance(middle, l.size() / 2);
    std::list<int>::iterator end = l.end();

    std::list<int> left(begin, middle);
    std::list<int> right(middle, end);
    mergeSort(left, time);
    mergeSort(right, time);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), l.begin());
    std::clock_t finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
}
