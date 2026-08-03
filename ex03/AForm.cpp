#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
    : name(""), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if(this != &other)
        isSigned = other.isSigned;
    return (*this);
}

AForm::~AForm(void)
{
}

const std::string &AForm::getName(void) const
{
    return (name);
}

bool AForm::getIsSigned(void) const
{
    return (isSigned);
}

int AForm::getGradeToSign(void) const
{
    return (gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
    return (gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade()  <= gradeToSign)
    {
        isSigned = true;
    }
    else
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("AForm grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("AForm grade is too low");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << form.getName() << ", signed: "
        << (form.getIsSigned() ? "true" : "false")
        << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute();
    return (out);
}
