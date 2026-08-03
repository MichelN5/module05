/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:50:46 by mnaouss           #+#    #+#             */
/*   Updated: 2026/07/30 20:10:56 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low";
}

Bureaucrat :: Bureaucrat(const std::string &name, int grade) : name(name) , grade(grade)
{
    if(grade < 1)
        throw GradeTooHighException();

    if(grade > 150 )
        throw GradeTooLowException();

    
}

Bureaucrat :: Bureaucrat(): name("") , grade(10)
{
    
}

Bureaucrat :: Bureaucrat(const Bureaucrat &other): name(other.name) , grade(other.grade)
{
}

Bureaucrat &Bureaucrat :: operator=(const Bureaucrat &other)
{
    if(this != &other)
    {
        grade = other.grade;
    }
    return (*this);
}

Bureaucrat:: ~Bureaucrat()
{
    
}

std::string Bureaucrat :: getName(void) const
{
    return name;
}

int Bureaucrat:: getGrade(void) const
{
    return grade;
}

void Bureaucrat :: incrementGrade(void)
{
    if(grade - 1 == 0)
    {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat :: decrementGrade(void)
{
    if(grade == 150)
    {
        throw GradeTooLowException();
    }
    grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName()
        << ", bureaucrat grade "
        << bureaucrat.getGrade()
        << ".";

    return out;
}


void Bureaucrat :: signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << name << " couldn't sign " << f.getName() 
            << " because " <<  e.what() << std::endl;
    }   
}


void Bureaucrat :: executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << name << " couldn't execute " << form.getName() 
            << " because " <<  e.what() << std::endl;
    }   
    
}