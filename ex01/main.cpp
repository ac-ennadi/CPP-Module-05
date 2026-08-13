#include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 5);
        Form formA("A42", 10, 20);
        std::cout << formA << std::endl;
        bob.signForm(formA);
        std::cout << formA << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat low("Low", 100);
        Form formB("B42", 50, 80);
        low.signForm(formB);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Form invalid("C42", 0, 50);
        std::cout << invalid << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Form invalid2("D42", 50, 151);
        std::cout << invalid2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}