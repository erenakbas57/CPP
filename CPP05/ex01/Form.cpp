#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(75), _gradeToExecute(75)
{

}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    try
    {
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw Form::GradeTooHighException();
        else if (gradeToSign > 150 || gradeToExecute > 150)
            throw Form::GradeTooLowException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Form::Form(Form const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
{
    *this = other;
}

Form::~Form()
{

}

Form &Form::operator=(Form const &other)
{
    _signed = other._signed;
    return *this;
}


std::string         Form::getName() const{
    return _name;
}

bool                Form::getSigned() const{
    return _signed;
}

int                 Form::getGradeToSign() const{
    return _gradeToSign;
}

int                 Form::getGradeToExecute() const{
    return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{

    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    else if (_signed)
        throw Form::FormAlreadySigned();
    else
        _signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form Grade too low";
}   

const char *Form::GradeNotEnough::what() const throw()
{
    return "Bureaucrat Grade not enough";
}

const char *Form::FormAlreadySigned::what() const throw()
{
    return "Form already signed";
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
    os << "Form name: " << form.getName() << std::endl;
    os << "Form signed: " << form.getSigned() << std::endl;
    os << "Grade required to sign: " << form.getGradeToSign() << std::endl;
    os << "Grade required to execute: " << form.getGradeToExecute();
    return os;
}