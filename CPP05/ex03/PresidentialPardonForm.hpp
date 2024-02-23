#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP


#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    std::string const  _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &other);
        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

        std::string getTarget() const;
        
        void        execute(Bureaucrat const & executor) const;
        
};

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &PresidentialPardonForm);

#endif