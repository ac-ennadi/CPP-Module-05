#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat john("John", 42);
        std::cout << john << std::endl;
        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;
        john.decrementGrade();
        std::cout << "After decrement: " << john << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat boss("Boss", 0);
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat slacker("Slacker", 151);
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat overachiever("Overachiever", 1);
        std::cout << overachiever << std::endl;
        overachiever.incrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat underachiever("Underachiever", 150);
        std::cout << underachiever << std::endl;
        underachiever.decrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}