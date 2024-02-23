#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    AForm::operator=(other);
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeNotEnough();
    else if (!this->getSigned())
        throw AForm::FormNotSigned();
    else
    {
        std::ofstream ofs;
        ofs.open(this->getTarget() + "_shrubbery", std::ios::out | std::ios::trunc);
        if (ofs.is_open())
        {
            ofs << "       _-_" << std::endl;
            ofs << "    /~~   ~~\\" << std::endl;
            ofs << " /~~         ~~\\" << std::endl;
            ofs << "{               }" << std::endl;
            ofs << " \\  _-     -_  /" << std::endl;
            ofs << "   ~  \\\\ //  ~" << std::endl;
            ofs << "_- -   | | _- _" << std::endl;
            ofs << "  _ -  | |   -_" << std::endl;
            ofs << "      // \\\\" << std::endl;
            ofs.close();
            std::cout << "\033[1;33m" << this->getTarget() << "_shrubbery has been created successfully.\033[0m" << std::endl;
        }
        else
        {
            std::cout << "\033[1;33m" << this->getTarget() << "_shrubbery creation failed.\033[0m" << std::endl;
            throw ShrubberyCreationForm::NotExecuted();
        }
    }
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &shrubberyCreationForm) {
    os << shrubberyCreationForm.getName() << " is ";
    if (shrubberyCreationForm.getSigned())
        os << "signed";
    else
        os << "not signed";
    os << " and requires grade " << shrubberyCreationForm.getGradeToSign() << " to be signed and grade " << shrubberyCreationForm.getGradeToExecute() << " to be executed." << std::endl;
    return os;
}