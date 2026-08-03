#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat bureaucrat("Bob", 42);

        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        std::cout << "After increment: " << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
        std::cout << "After decrement: " << bureaucrat << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat tooHigh("Alice", 0);
        std::cout << tooHigh << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat tooLow("Charlie", 151);
        std::cout << tooLow << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat highest("Diana", 1);

        std::cout << highest << std::endl;
        highest.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat lowest("Edward", 150);

        std::cout << lowest << std::endl;
        lowest.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
