#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    Bureaucrat boss("Boss", 1);
    Intern intern;

    std::cout << "Creating a robotomy request" << std::endl;
    AForm* robotomy = intern.makeForm("robotomy request", "Bender");
    if (robotomy) {
        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);
        delete robotomy;
    }

    std::cout << "\nCreating a shrubbery form" << std::endl;
    AForm* shrubbery = intern.makeForm("shrubbery creation", "Garden");
    if (shrubbery) {
        boss.signForm(*shrubbery);
        boss.executeForm(*shrubbery);
        delete shrubbery;
    }

    std::cout << "\nCreating a presidential pardon" << std::endl;
    AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
    if (pardon) {
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
        delete pardon;
    }

    std::cout << "\nTrying an unknown form" << std::endl;
    AForm* unknown = intern.makeForm("tax evasion", "Nobody");
    if (unknown) {
        delete unknown;
    }

    return 0;
}