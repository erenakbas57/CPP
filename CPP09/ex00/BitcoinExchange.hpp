#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <map>

#define BLANK -3
#define NEGATIVE -1
#define MAX -2

#define JAN 31
#define FEB 28
#define MAR 31
#define APR 30
#define MAY 31
#define JUN 30
#define JUL 31
#define AUG 31
#define SEP 30
#define OCT 31
#define NOV 30
#define DEC 31

enum e_type
{
    INT,
    DOUBLE,
    IMPOSSIBLE
};


class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();


        class WrongDate : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class NoBitcoin : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class NoNumber : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class NegativeNumber : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class MaxNumber : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class FutureDate : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class AFewSpace : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::map<std::string, float> read_csv();
std::map<std::string, std::string> read_input(std::string data);

void    printList(std::map<std::string, float> data, std::map<std::string, std::string> input);
int     dateControl(std::string date);
int     maxControl(std::string number);
int     isPrint(std::string str);
int     isNumber(std::string str);
int     numberControl(std::string value);

#endif