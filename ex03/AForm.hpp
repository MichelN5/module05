#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

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

        AForm(void);
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm(void);

        const std::string &getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;

        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const =0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
