#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
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

    AForm *form4 = new RobotomyRequestForm("Hitler");

    Employee2.signForm(*form4);

    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;

    Bureaucrat Employee3("Eren", 50);

    AForm *form5 = new RobotomyRequestForm("Saddam");

    Employee3.signForm(*form5);
    Employee3.executeForm(*form5);

    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;

    Bureaucrat Employee4("Eren", 1);

    AForm *form6 = new RobotomyRequestForm("Muammer Kaddafi");

    Employee4.executeForm(*form6);

    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "----------------------------" << std::endl;

    Bureaucrat Employee5("Eren", 1);

    AForm *form7 = new PresidentialPardonForm("Joe Biden");

    Employee5.signForm(*form7);
    Employee5.signForm(*form7);

	std::cout << "----------------------------" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "----------------------------" << std::endl;

	try
	{
		Intern bob;
		PresidentialPardonForm *ptr1;
		RobotomyRequestForm *ptr2;
		ShrubberyCreationForm *ptr3;
		// AForm *ptr4;

		ptr1 = (PresidentialPardonForm*)bob.makeForm(PPF_NAME, "Samuel II Croonie");
		ptr2 = (RobotomyRequestForm*)bob.makeForm(RRF_NAME, "GHY 5900");
		ptr3 = (ShrubberyCreationForm*)bob.makeForm(SCF_NAME, "home");
		// ptr4 = bob.makeForm("basic form","whatever");
		
        Bureaucrat Employee6("Eren", 1);
        Employee6.signForm(*ptr1);
        Employee6.signForm(*ptr1);
        Employee6.executeForm(*ptr1);
        std::cout << ptr1->getTarget() << " is target name" << std::endl;

		delete ptr1;
		delete ptr2;
		delete ptr3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}