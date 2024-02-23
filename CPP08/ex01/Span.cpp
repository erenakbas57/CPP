#include "Span.hpp"

Span::Span() : list(0), len(MAX) {}

Span::Span(unsigned int n){
    len = n;
    list.reserve(n);
}

Span::Span(Span const &other)
{
    this->list = other.list;
    this->len = other.len;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    try
    {
        if (list.size() >= len)
            throw SpanFull();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return ;
    }
    list.push_back(number);
}

std::vector<int> Span::getList() const
{
    return list;
}


int randomNumber()
{
    return (rand() % 1000000);
}

void Span::fullAdd()
{
    try
    {
        if (list.size() > len)
            throw SpanFull();
        for (unsigned int i = 0; i < this->len; i++)
        {
            list.push_back(randomNumber());
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

long long Span::shortestSpan()
{
    try
    {
        if (list.size() <= 1)
            throw SpanEmpty();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (0);
    }
    std::sort(list.begin(), list.end());
    long long min = 99999999999999;
    for (int i = 1; i < (int)list.size(); i++)
    {
        long long x = static_cast<long long>(list[i]);
        long long y = static_cast<long long>(list[i - 1]);
        if ((x - y) < min)
            min = (x - y);
    }
    return (min);
}

int Span::numberSign(long min, long max)
{
    if (min < 0 && max < 0)
        return 2;
    else if (min < 0 || max < 0)
        return 1;
    return 0;
}

long long Span::longestSpan()
{
    try
    {
        if (list.size() <= 1)
            throw SpanEmpty();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (0);
    }
    long long max = static_cast<long long>(list[len - 1]);
    long long min = static_cast<long long>(list[0]);
    return (max - min);
}


const char *Span::SpanFull::what() const throw()
{
    return "Span is full!";
}
const char *Span::SpanEmpty::what() const throw()
{
    return "Span is empty or Span have one number!";
}