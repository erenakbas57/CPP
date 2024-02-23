#ifndef INTERN_HPP
#define INTERN_HPP


#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define PPF_NAME "presidential pardon"
#define RRF_NAME "robotomy request"
#define SCF_NAME "shrubbery creation"

class Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		~Intern();

		Intern &operator=(Intern const &other);

        AForm *makeForm(std::string const &formName, std::string const &target);

        class FormNotFound : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, Intern const &Intern);

#endif