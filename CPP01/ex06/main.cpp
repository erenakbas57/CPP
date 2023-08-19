#include "Harl.hpp"

int main(int ac, char **av)
{
   Harl deneme;
   if (ac == 2)
   {
      std::string answer;
      answer = av[1];
      deneme.complain(answer);
   }
   return (0);
}