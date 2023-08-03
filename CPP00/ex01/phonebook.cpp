/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:41:01 by makbas            #+#    #+#             */
/*   Updated: 2023/08/03 20:11:49 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


void    PhoneBook::add_contact()
{
    static int i = 0;
    string  str;
    if (i >= 8)
        i = 0;
    cout << "FIRSTNAME : ";
    name:
    getline(cin, str);
    if (str == "\0")
        goto name;
    contact[i].set_name(str);
    cout << "LASTNAME : ";
    lastname:
    getline(cin, str);
    if (str == "\0")
        goto lastname;
    contact[i].set_surname(str);
    cout << "USERNAME : ";
    username:
    getline(cin, str);
    if (str == "\0")
        goto username;
    contact[i].set_username(str);
    cout << "PHONE NUMBER : ";
    phone:
    getline(cin, str);
    if (str == "\0")
        goto phone;
    contact[i].set_phone(str);
    cout << "DARK SECRET : ";
    secret:
    getline(cin, str);
    if (str == "\0")
        goto secret;
    contact[i].set_secret(str);
    cout << endl;
    contact[i].set_index(i + 1);
    if (index_count < 8)
        index_count++;
    i++;
}

string  ten_character(string st)
{
	char str[11];
	int x = -1;
	int len;

	if(st.length() > 10)
	{
		while (++x <= 9)
		{
			if(x == 9)
			{
				str[x++] = '.';
				str[x] = 0;
				break ;
			}
			str[x] = st[x];
		}
		return (str);
	}
	else
	{
		len = st.length();
		len = 10 - len;
		while (st[++x])
			str[x] = st[x];
		while (len--)
			str[x++] = ' ';
		str[x] = 0;
		return (str);
	}
}

void    write_info(PhoneBook *phone, int i)
{
    cout << i + 1 << " | ";
    cout << ten_character(phone->get_contact(i).get_name()) << " | ";
    cout << ten_character(phone->get_contact(i).get_surname()) << " | ";
    cout << ten_character(phone->get_contact(i).get_username()) << " | \n";
}

void    PhoneBook::search(void)
{
    int i;

    i = 0;
    while (i++ < index_count)
        write_info(this, i);
}

