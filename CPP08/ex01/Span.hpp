#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define MAX 2147483647

class Span
{
    private:
        std::vector<int> list;
        unsigned int   len;

    public:
        Span();
        Span(unsigned int n);
        Span(Span const &other);
        ~Span();
        Span &operator=(Span const &other);

        void addNumber(int number);
        void fullAdd();
        long long shortestSpan();
        long long longestSpan();
        int numberSign(long min, long max);

        std::vector<int> getList() const;

        class SpanFull : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class SpanEmpty : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif