#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP


#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    std::string const  _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &other);
        ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

        std::string getTarget() const;

        void        execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &RobotomyRequestForm);

#endif