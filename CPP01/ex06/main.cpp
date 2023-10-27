#include "Harl.hpp"

int main(int ac, char **av)
{
   Harl ex;
   if (ac == 2)
   {
      std::string answer;
      answer = av[1];
      ex.complain(answer);
   }
   return (0);
}