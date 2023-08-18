/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:41:01 by makbas            #+#    #+#             */
/*   Updated: 2023/08/03 23:57:45 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

bool    is_number(string number)
{
    int i = 0;
    while (number[i])
    {
        if (!(number[i] > '0' && number[i] < '9'))
            return (0);
        i++;
    }
    return (1);
}


void    PhoneBook::add_contact()
{
    static int i = 0;
    string  str;
    if (i >= 8)
        i = 0;
    cout << "..........................\n";
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
    cin >> str;
    if (!is_number(str))
        goto phone;
    contact[i].set_phone(str);
    cout << "DARK SECRET : ";
    secret:
    getline(cin, str);
    if (str == "\0")
        goto secret;
    contact[i].set_secret(str);
    cout << "..........................\n";
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

void    write_detail_info(PhoneBook *phone, int i)
{
    cout << "..........................\n";
    cout << "Name : " << phone->get_contact(i).get_name() << endl;
    cout << "Surname : " << phone->get_contact(i).get_surname() << endl;
    cout << "Username : " << phone->get_contact(i).get_username() << endl;
    cout << "Phone Number : " << phone->get_contact(i).get_phone() << endl;
    cout << "Dark Secret : " << phone->get_contact(i).get_secret() << endl;
    cout << "..........................\n\n";
}

void    PhoneBook::search(void)
{
    int i;
    int index;
    
    i = 0;
    cout << "..........................\n";
    while (i < index_count)
    {
        write_info(this, i);
        i++;
    }
    cout << "..........................\n";
    cout << "Enter index for person's information : ";
    cin >> index;
    if (index <= index_count)
        write_detail_info(this, index - 1);
    else if (index <= 0 || index > index_count)
        cout << "invalid value\n\n";
    else
        cout << "No Records Found\n\n";
}

