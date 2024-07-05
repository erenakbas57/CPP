#include "PmergeMe.hpp"

int control(int ac, char**av){
    for (int i = 1; i < ac; i++)
    {
        int arg = std::atoi(av[i]);

        if (arg <= 0 || std::string(av[i]) != std::to_string(arg)) {
            return -1;
        }
    }
    return (0);
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Usage: " << av[0] << " number number number ..." << std::endl;
        return 1;
    }
    if (control(ac, av))
    {
        std::cout << "Error\n";
        return 1;
    }
    if (number_control(ac, av)) {
        return 1;
    }
    double listTime;
    double vectorTime;
    std::vector<int> v;
    std::list<int> l;

    add_container(v, ac, av);
    add_container(l, ac, av);
    printContainer(v, "Before ");
    mergeSort(v, vectorTime);
    mergeSort(l, listTime);
    printContainer(v, "After  ");
    printTime(vectorTime, ac - 1, "std::vector<int>");
    printTime(listTime, ac - 1, "std::list<int>  ");
    

    return 0;
}