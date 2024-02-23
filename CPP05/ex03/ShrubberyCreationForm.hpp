#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP


#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    std::string const  _target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &other);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

        std::string getTarget() const;

        void        execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &ShrubberyCreationForm);

#endif