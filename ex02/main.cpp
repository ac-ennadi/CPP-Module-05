#include "Bureaucrat.hpp"
#include "AForm.hpp"

class TestForm : public AForm {
public:
    TestForm(const std::string& name, int gradeToSign, int gradeToExecute)
        : AForm(name, gradeToSign, gradeToExecute) {}

    void execute(const Bureaucrat& executor) const {
        checkRequirements(executor);
        std::cout << executor.getName() << " is doing the work."
                  << std::endl;
    }
};

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat worker("Worker", 100);
        TestForm form("Important document", 50, 25);

        std::cout << form << std::endl;
        worker.signForm(form);
        boss.signForm(form);
        worker.executeForm(form);
        boss.executeForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        TestForm invalidForm("Invalid document", 0, 50);
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
