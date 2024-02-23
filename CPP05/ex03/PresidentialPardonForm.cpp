#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 72, 45), _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 72, 45), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    AForm::operator=(other);
    return *this;
}

std::string PresidentialPardonForm::getTarget() const {
    return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeNotEnough();
    else if (!this->getSigned())
        throw AForm::FormNotSigned();
    else
    {
        std::cout << "\033[1;33m" << this->getTarget() << " has been pardoned by Zafod Beeblebrox.\033[0m" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &presidentialPardonForm) {
    os << presidentialPardonForm.getName() << " is ";
    if (presidentialPardonForm.getSigned())
        os << "signed";
    else
        os << "not signed";
    os << " and requires grade " << presidentialPardonForm.getGradeToSign() << " to be signed and grade " << presidentialPardonForm.getGradeToExecute() << " to be executed." << std::endl;
    return os;
}