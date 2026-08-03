#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    std::srand(std::time(NULL));

    Bureaucrat chief("Chief", 1);
    Intern intern;
    Intern copy(intern);
    Intern assigned;
    AForm *forms[4];

    assigned = copy;
    forms[0] = intern.makeForm("shrubbery creation", "garden");
    forms[1] = intern.makeForm("robotomy request", "Bender");
    forms[2] = intern.makeForm("presidential pardon", "Arthur Dent");
    forms[3] = intern.makeForm("coffee request", "Chief");

    for (int i = 0; i < 4; ++i)
    {
        if (forms[i] != NULL)
        {
            std::cout << *forms[i] << std::endl;
            chief.signForm(*forms[i]);
            chief.executeForm(*forms[i]);
            delete forms[i];
        }
    }

    return (0);
}
