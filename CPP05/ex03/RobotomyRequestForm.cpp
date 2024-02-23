#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    AForm::operator=(other);
    return *this;
}

std::string RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeNotEnough();
    else if (!this->getSigned())
        throw AForm::FormNotSigned();
    else
    {
        std::cout << "\033[1;33m* TRANK TRANK TRANK *\033[0m" << std::endl;
        if (rand() % 2 == 1)
            std::cout << "\033[1;33m" << this->getTarget() << " has been robotomized successfully %50 of the time.\033[0m" << std::endl;
        else
        {
            std::cout << "\033[1;33m" << this->getTarget() << " robotomization failed.\033[0m" << std::endl;
            throw RobotomyRequestForm::NotExecuted();
        }
    }
}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &robotomyRequestForm) {
    os << robotomyRequestForm.getName() << " is ";
    if (robotomyRequestForm.getSigned())
        os << "signed";
    else
        os << "not signed";
    os << " and requires grade " << robotomyRequestForm.getGradeToSign() << " to be signed and grade " << robotomyRequestForm.getGradeToExecute() << " to be executed." << std::endl;
    return os;
}