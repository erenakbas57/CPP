#include "Bureaucrat.hpp"


int main(){

    Bureaucrat Employee("eren", 1);
    std::cout << "----------------------" << std::endl;
    std::cout << Employee << std::endl;
    Employee.incrementGrade();
    std::cout << "----------------------" << std::endl;
    std::cout << Employee << std::endl;

    Bureaucrat Invalid("Donal Trump", 0);
    std::cout << "----------------------" << std::endl;
    std::cout << Invalid << std::endl;

    Bureaucrat Employee1("eren", 150);
    std::cout << "----------------------" << std::endl;
    std::cout << Employee1 << std::endl;
    
    Bureaucrat Invalid1("Donal Trump", 151);
    std::cout << "----------------------" << std::endl;
    std::cout << Invalid1 << std::endl;
}