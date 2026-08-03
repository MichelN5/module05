#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), target(other.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
}
