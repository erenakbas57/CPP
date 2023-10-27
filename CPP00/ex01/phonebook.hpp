/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:41:07 by makbas            #+#    #+#             */
/*   Updated: 2023/10/23 16:52:33 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class   Contact{
    private:
        int     index;
        string  name;
        string  surname;
        string  username;
        string  phone_number;
        string  dark_secret;

    public:
        // SETTER
        void    set_index(int i) {index = i;}
        void    set_name(string str) {name = str;}
        void    set_surname(string str) {surname = str;}
        void    set_username(string str) {username = str;}
        void    set_phone(string nbr) {phone_number = nbr;}
        void    set_secret(string str) {dark_secret = str;}

        // GETTER
        int     get_index() {return (index);};
        string  get_name() {return (name);};
        string  get_surname() {return (surname);};
        string  get_username() {return (username);};
        string  get_phone() {return (phone_number);};
        string  get_secret() {return (dark_secret);};
};

class PhoneBook{
    private:
        Contact contact[8];
        int     index_count;
    public:
        PhoneBook() {index_count = 0;}
        Contact& get_contact(int index) { return (contact[index]);}
        void    add_contact();
        void    search();
};
#endif
