/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:33:41 by makbas            #+#    #+#             */
/*   Updated: 2023/08/02 17:49:46 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int i;
    int j;
    
    i = 1;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (av[i])
        {
            j = 0;
            while (av[i][j])
            {
                if (av[i][j] >= 97 && av[i][j] <= 122)
                    av[i][j] -= 32;
                std::cout << av[i][j];
                j++;
            }
            std::cout << " ";
            i++;
        }
    }
    std::cout << "\n";
}