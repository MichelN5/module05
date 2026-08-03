/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:37:52 by mnaouss           #+#    #+#             */
/*   Updated: 2026/08/03 14:40:27 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern(void)
{
}

AForm* Intern::createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, 
    const std::string& target) const
{
    typedef AForm* (*Creator)(const std::string&);

    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    Creator creators[3] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }

    std::cerr << "Intern cannot create unknown form: "
              << formName << std::endl;
    return NULL;
}
