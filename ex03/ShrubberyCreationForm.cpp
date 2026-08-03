#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream output((target + "_shrubbery").c_str());
    if (!output)
        throw std::runtime_error("Could not create shrubbery file");

    output << "           /\\\n"
           << "          /**\\\n"
           << "         /****\\\n"
           << "        /******\\\n"
           << "       /********\\\n"
           << "      /**********\\\n"
           << "     /************\\\n"
           << "          ||\n"
           << "          ||\n";
}
