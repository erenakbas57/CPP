#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(75), _gradeToExecute(75)
{

}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    try
    {
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw AForm::GradeTooHighException();
        else if (gradeToSign > 150 || gradeToExecute > 150)
            throw AForm::GradeTooLowException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

AForm::AForm(AForm const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
{
    *this = other;
}

AForm::~AForm()
{

}

AForm &AForm::operator=(AForm const &other)
{
    _signed = other._signed;
    return *this;
}

// GETTERS
std::string         AForm::getName() const{
    return _name;
}

bool                AForm::getSigned() const{
    return _signed;
}

int                 AForm::getGradeToSign() const{
    return _gradeToSign;
}

int                 AForm::getGradeToExecute() const{
    return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeNotEnough();
    else if (_signed)
        throw AForm::FormAlreadySigned();
    else
        _signed = true;
}

// EXCEPTIONS

const char *AForm::GradeTooHighException::what() const throw()
{
    return "\033[1;31mAForm Grade too high\033[0m";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "\033[1;31mAForm Grade too low\033[0m";
}   

const char *AForm::GradeNotEnough::what() const throw()
{
    return "\033[1;31mBureaucrat Grade not enough\033[0m";
}

const char *AForm::FormNotSigned::what() const throw()
{
    return "\033[1;31mForm not signed\033[0m";
}

const char *AForm::NotExecuted::what() const throw()
{
    return "\033[1;31mForm not executed\033[0m";
}

const char *AForm::FormAlreadySigned::what() const throw()
{
    return "\033[1;31mForm already signed\033[0m";
}

// OPERATOR OVERLOADS

std::ostream &operator<<(std::ostream &os, AForm const &AForm)
{
    os << "Form name: " << AForm.getName() << std::endl;
    os << "Form signed: " << AForm.getSigned() << std::endl;
    os << "Grade required to sign: " << AForm.getGradeToSign() << std::endl;
    os << "Grade required to execute: " << AForm.getGradeToExecute();
    return os;
}