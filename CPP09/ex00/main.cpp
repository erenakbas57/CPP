#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file.\n";
        return (1);
    }
    else
    {
        std::map<std::string, float> data;
        std::map<std::string, std::string> input;

        data = read_csv();
        input = read_input(av[1]);
        if (input.size() == 0)
        {
            std::cout << "Error: could not open input file.\n";
            return (1);
        }
        else if (data.size() == 0)
        {
            std::cout << "Error: could not open data file.\n";
            return (1);
        }
        printList(data, input);
    }
    return (0);
}