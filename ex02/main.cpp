#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    std::srand(std::time(NULL));

    Bureaucrat chief("Chief", 1);
    Bureaucrat manager("Manager", 40);
    Bureaucrat intern("Intern", 150);
    ShrubberyCreationForm shrubbery("garden");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << chief << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;

    intern.executeForm(shrubbery);
    intern.signForm(shrubbery);
    manager.signForm(shrubbery);
    manager.executeForm(shrubbery);

    manager.signForm(robotomy);
    manager.executeForm(robotomy);

    chief.signForm(pardon);
    manager.executeForm(pardon);
    chief.executeForm(pardon);

    return (0);
}
