# include <iostream>
# include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat valid("Alice", 42);
        std::cout << valid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat lowest("Bob", 150);
        std::cout << lowest << std::endl;
        lowest.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat highest("Charlie", 1);
        std::cout << highest << std::endl;
        highest.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat invalidLow("Dan", 0);
        std::cout << invalidLow << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat invalidHigh("Eve", 151);
        std::cout << invalidHigh << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return (0);
}