#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
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

    try {
        Form invalidForm("Invalid document", 0, 50);
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
