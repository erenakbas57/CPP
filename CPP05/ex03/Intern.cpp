#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
    *this = other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &other)
{
    (void)other;
    return (*this);
}

AForm *newPresidentialForm(const std::string &target){
    return (new PresidentialPardonForm(target));
}

AForm *newShrubberyForm(const std::string &target){
    return (new ShrubberyCreationForm(target));
}

AForm *newRobotomyForm(const std::string &target){
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
    AForm *form = NULL;

    std::string f_name[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm *(*choose[3])(const std::string &) = {
        choose[0] = &newPresidentialForm,
        choose[1] = &newRobotomyForm,
        choose[2] = &newShrubberyForm
    };
    for (int i = 0; i < 3; i++)
    {
        if (f_name[i] == formName)
        {
            form = choose[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return (form);
        }
    }
    if (!form)
        throw FormNotFound();
    return form;
}

const char *Intern::FormNotFound::what() const throw()
{
    return ("Form not found");
}