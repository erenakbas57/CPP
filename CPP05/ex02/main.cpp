#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
    Bureaucrat Employee("Eren", 1);

    AForm *form = new RobotomyRequestForm("Donald Trump");
    AForm *form2 = new PresidentialPardonForm("Joe Biden");
    AForm *form3 = new ShrubberyCreationForm("Barack Obama");

    Employee.signForm(*form);
    Employee.signForm(*form2);
    Employee.signForm(*form3);

    Employee.executeForm(*form);
    Employee.executeForm(*form2);
    Employee.executeForm(*form3);

    delete form;
    delete form2;
    delete form3;

    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;

    Bureaucrat Employee2("Eren", 150);

    AForm *form4 = new RobotomyRequestForm("Donald Trump");

    Employee2.signForm(*form4);

    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;

    Bureaucrat Employee3("Eren", 50);

    AForm *form5 = new RobotomyRequestForm("Donald Trump");

    Employee3.signForm(*form5);
    Employee3.executeForm(*form5);

    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;

    Bureaucrat Employee4("Eren", 1);

    AForm *form6 = new RobotomyRequestForm("Donald Trump");

    Employee4.executeForm(*form6);

    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;

    Bureaucrat Employee5("Eren", 1);

    AForm *form7 = new PresidentialPardonForm("Joe Biden");

    Employee5.signForm(*form7);
    Employee5.signForm(*form7);

    exit(0);
}