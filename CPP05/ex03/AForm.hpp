#ifndef AFORM_HPP
#define AFORM_HPP


#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeToSign;
        int const           _gradeToExecute;

    public:
        AForm();
        AForm(std::string const &name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &other);
        virtual ~AForm();

        AForm &operator=(AForm const &other);

        std::string         getName() const;
        bool                getSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;

        void                beSigned(Bureaucrat &bureaucrat);
        virtual void        execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeNotEnough : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class FormNotSigned : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class NotExecuted : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class FormAlreadySigned : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, AForm const &AForm);

#endif