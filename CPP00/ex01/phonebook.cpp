/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:41:01 by makbas            #+#    #+#             */
/*   Updated: 2023/10/23 16:52:25 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
    cout << i + 1 << "- FIRSTNAME : ";
    name:
    getline(cin, str);
    if (str == "\0")
    {
        cout << "Please enter a value.\nFIRSTNAME : ";
        goto name;
    }
    contact[i].set_name(str);
    cout << i + 1 << "- LASTNAME : ";
    lastname:
    getline(cin, str);
    if (str == "\0")
    {
        cout << "Please enter a value.\nLASTNAME : ";
        goto lastname;
    }
    contact[i].set_surname(str);
    cout << i + 1 << "- USERNAME : ";
    username:
    getline(cin, str);
    if (str == "\0")
    {
        cout << "Please enter a value.\nUSERNAME : ";
        goto username;
    }
    contact[i].set_username(str);
    cout << i + 1 << "- PHONE NUMBER : ";
    phone:
    getline(cin, str);
    if (!is_number(str))
    {
        cout << "Contains characters other than numbers. try again...\nPHONE NUMBER : ";
        goto phone;
    }
    else if (str == "\0")
    {
        cout << "Please enter a value.\nPHONE NUMBER : ";
        goto phone;
    }
    contact[i].set_phone(str);
    cout << i + 1 << "- DARK SECRET : ";
    secret:
    getline(cin, str);
    if (str == "\0")
    {
        cout << "Please enter a value.\nDARK SECRET : ";
        goto secret;
    }
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
	int x = 0;

	if(st.length() > 10)
	{
        while (x < 9)
        {
            str[x] = st[x];
            x++;
        }
        str[x] = '.';
        x++;
        str[x] = 0;
		return (str);
	}
	else
	{
        while (st[x])
        {
            str[x] = st[x];
            x++;
        }
        while (x <= 9)
        {
            str[x] = ' ';
            x++;
        }
        str[x] = 0;
		return (str);
	}
}

void    write_info(PhoneBook *phone, int i)
{
    cout << i + 1 << "          | ";
    cout << ten_character(phone->get_contact(i).get_name()) << " | ";
    cout << ten_character(phone->get_contact(i).get_surname()) << " | ";
    cout << ten_character(phone->get_contact(i).get_username()) << " | \n";
}

void    write_detail_info(PhoneBook *phone, int i)
{
    cout << "--------------------------\n";
    cout << "Name : " << phone->get_contact(i).get_name() << endl;
    cout << "Surname : " << phone->get_contact(i).get_surname() << endl;
    cout << "Username : " << phone->get_contact(i).get_username() << endl;
    cout << "Phone Number : " << phone->get_contact(i).get_phone() << endl;
    cout << "Dark Secret : " << phone->get_contact(i).get_secret() << endl;
    cout << "--------------------------\n\n";
}

void    PhoneBook::search(void)
{
    int i;
    string input;
    int index = -1;
    bool isNumber = true;
    i = 0;
    if (index_count <= 0)
        cout << "No Records Found\n\n";
    else
    {
        cout << "..........................\n";
        while (i < index_count)
        {
            write_info(this, i);
            i++;
        }
        cout << "..........................\n";
        cout << "Enter index for person's information : ";
        getline(cin, input);
        if (!is_number(input))
            isNumber = false;
        if (!isNumber)
            cout << "The value you entered is not a number\n\n";
        else if (input == "\0")
            cout << "The value is a Empty\n\n";
        else
        {
            index = stoi(input);
            if (index <= index_count)
                write_detail_info(this, index - 1);
            else if (index <= 0 || index > index_count)
                cout << "invalid value\n\n";
        }
    }
}