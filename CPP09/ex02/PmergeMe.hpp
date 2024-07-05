#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP


#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip>

int number_control(int ac, char **av);


void add_container(std::vector<int> &container, int ac, char **av);
void add_container(std::list<int> &container, int ac, char **av);

void printContainer(std::vector<int> v, std::string str);

template <typename T>
void insertSort(T &l, double &time);

void printTime(double time, int size, std::string type);

void mergeSort(std::vector<int> &l, double &time);
void mergeSort(std::list<int> &l, double &time);

#endif