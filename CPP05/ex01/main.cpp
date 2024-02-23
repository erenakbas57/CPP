#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){

    Bureaucrat Employee("Eren", 15);
    std::cout << Employee << std::endl;

    Form form("Rapor", 15, 15);
    std::cout << form << std::endl;
    Employee.signForm(form);
    Employee.signForm(form);
    std::cout << "----------------------------" << std::endl;

    Bureaucrat Employee2("Levi", 10);
    std::cout << Employee2 << std::endl;

    Form form2("Rapor2", 5, 5);
    std::cout << form2 << std::endl;
    Employee2.signForm(form2);
    std::cout << "----------------------------" << std::endl;
}