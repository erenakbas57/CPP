#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(100) {
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade) {
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name){
    *this = other;
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other){
    _grade = other.getGrade();
    return *this;
}

Bureaucrat& Bureaucrat::operator++(void){
    this->_grade++;
    return (*this);
}

Bureaucrat Bureaucrat::operator++(int){
    Bureaucrat res = *this;
    this->_grade++;
    return (res);
}

Bureaucrat& Bureaucrat::operator--(void){
    this->_grade--;
    return (*this);
}

Bureaucrat Bureaucrat::operator--(int){
    Bureaucrat res = *this;
    this->_grade--;
    return (res);
}

std::string	        Bureaucrat::getName() const{
    return _name;
}

int					Bureaucrat::getGrade() const{
    return _grade;
}

void				Bureaucrat::incrementGrade(){
    try
    {
        if (_grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        _grade--;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void				Bureaucrat::decrementGrade(){
    try
    {
        if (_grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        _grade++;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Bureaucrat::signForm(AForm &form){
    try {
        form.beSigned(*this);
        std::cout << "\033[34m" << _name << " is signing " << form.getName() << "\033[0m" << std::endl;
        std::cout << "\033[1;32mSIGNED SUCCESSFULLY\033[0m" << std::endl;
    }
    catch (std::exception &e){
        std::cout << "\033[34m" << _name << " couldn’t sign " << form.getName() << " because " << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[1;31mSIGNED FAILED\033[0m" << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form){
    try {
        std::cout << "\033[34m" << _name << " is executing " << form.getName() << "\033[0m" << std::endl;
        form.execute(*this);
        std::cout << "\033[1;32mEXECUTED SUCCESSFULLY\033[0m" << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
        std::cout << "\033[1;31mEXECUTED FAILED\033[0m" << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "\033[1;31mBureaucrat Grade too high\033[0m";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "\033[1;31mBureaucrat Grade too low\033[0m";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &Bureaucrat){
    os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
    return os;
}