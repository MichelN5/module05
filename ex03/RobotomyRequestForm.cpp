#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully"
                  << std::endl;
    else
        std::cout << "Robotomy of " << target << " failed" << std::endl;
}
