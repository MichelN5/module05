#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
    : name(""), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if(this != &other)
        isSigned = other.isSigned;
    return (*this);
}

Form::~Form(void)
{
}

const std::string &Form::getName(void) const
{
    return (name);
}

bool Form::getIsSigned(void) const
{
    return (isSigned);
}

int Form::getGradeToSign(void) const
{
    return (gradeToSign);
}

int Form::getGradeToExecute(void) const
{
    return (gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade()  <= gradeToSign)
    {
        isSigned = true;
    }
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << ", signed: "
        << (form.getIsSigned() ? "true" : "false")
        << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute();
    return (out);
}
