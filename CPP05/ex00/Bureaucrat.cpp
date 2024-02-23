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

std::string         Bureaucrat::getName() const{
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

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &Bureaucrat){
    os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
    return os;
}