/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:47:29 by makbas            #+#    #+#             */
/*   Updated: 2023/10/28 17:45:28 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void    list_main(PhoneBook &phone)
{
    cout << "***Choose your action***\n";
    cout << "1- ADD\n2- SEARCH\n3- EXIT\n\nYour Choose: ";
    string choose;
    getline(cin, choose);
    if (choose == "ADD")
    {
        phone.add_contact();
    }
    else if (choose == "SEARCH")
    {
        phone.search();
    }
    else if (choose == "EXIT")
    {
        exit(0);
    }
    else
        cout << "An invalid choice has been made. Try again...\n\n";
}

int main()
{
    PhoneBook phone;
    cout << "WELCOME TO THE YOUR PHONE\n";
    cout << "*************************\n\n";
    while (1)
        list_main(phone);
}