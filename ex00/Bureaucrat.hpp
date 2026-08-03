/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:44:48 by mnaouss           #+#    #+#             */
/*   Updated: 2026/07/30 17:35:37 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_H
# define Bureaucrat_H

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        std::string const name;
        int grade;

    public:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(void);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat(void);

        int getGrade(void) const;
        std::string getName(void) const;
        void incrementGrade(void);
        void decrementGrade(void);

        
        
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
