#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP


#include <iostream>


class Bureaucrat
{
    private:
        std::string const	_name;
        int					_grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &other);
        ~Bureaucrat();

        Bureaucrat &operator=(Bureaucrat const &other);
        Bureaucrat &operator++();
        Bureaucrat operator++(int);
        Bureaucrat &operator--();
        Bureaucrat operator--(int);

        std::string     getName() const;
        int				getGrade() const;

        void			incrementGrade();
        void			decrementGrade();

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
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif