/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:47:29 by makbas            #+#    #+#             */
/*   Updated: 2023/08/03 19:57:05 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void    list_main(PhoneBook &phone)
{
    cout << "select the action you want to do\n";
    cout << "1- ADD\n2- SEARCH\n3- EXIT\nYour Choose: ";
    int choose;
    cin >> choose;
    if (choose == 1)
    {
        phone.add_contact();
    }
    else if (choose == 2)
    {
        phone.search();
    }
    else if (choose == 3)
    {
        exit(0);
    }
    else
    {
        cout << "An invalid choice has been made. Try again...\n    ";
        list_main(phone);
    }
}

int main(int ac, char **av)
{
    PhoneBook phone;
    while (1)
        list_main(phone);
}