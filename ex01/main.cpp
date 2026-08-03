#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat chief("Alice", 1);
        Bureaucrat intern("Bob", 150);
        Form permit("Building permit", 42, 20);

        std::cout << chief << std::endl;
        std::cout << intern << std::endl;
        std::cout << permit << std::endl;

        intern.signForm(permit);
        std::cout << permit << std::endl;

        chief.signForm(permit);
        std::cout << permit << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form invalid("Invalid form", 1, 151);
        std::cout << invalid << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
