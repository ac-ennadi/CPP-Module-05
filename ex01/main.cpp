#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "Signing a form" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat worker("Worker", 100);
        Form form("Important document", 50, 25);

        std::cout << form << std::endl;
        worker.signForm(form);
        boss.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nInvalid bureaucrat grades" << std::endl;
    try {
        Bureaucrat tooHigh("Too high", 0);
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat tooLow("Too low", 151);
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nChanging grades" << std::endl;
    try {
        Bureaucrat high("High", 1);
        high.incrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << "Increment failed: " << e.what() << std::endl;
    }

    try {
        Bureaucrat low("Low", 150);
        low.decrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << "Decrement failed: " << e.what() << std::endl;
    }

    Bureaucrat middle("Middle", 75);
    middle.incrementGrade();
    std::cout << "After increment: " << middle << std::endl;
    middle.decrementGrade();
    std::cout << "After decrement: " << middle << std::endl;

    std::cout << "\nBoundary grades" << std::endl;
    try {
        Bureaucrat best("Best", 1);
        Bureaucrat last("Last", 150);
        std::cout << best << std::endl;
        std::cout << last << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nInvalid form grades" << std::endl;
    try {
        Form invalidForm("Invalid form", 0, 50);
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Form invalidForm("Invalid form", 50, 151);
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nCopy and assignment" << std::endl;
    Bureaucrat signer("Signer", 1);
    Form original("Original form", 50, 25);
    original.beSigned(signer);
    Form copy(original);
    Form assigned;
    assigned = original;
    std::cout << copy << std::endl;
    std::cout << assigned << std::endl;

    return 0;
}
