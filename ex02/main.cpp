#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));

    std::cout << "--- Creating Bureaucrats ---" << std::endl;
    Bureaucrat boss("The Boss", 1);
    Bureaucrat middleManager("Middle Manager", 50);
    Bureaucrat lowerManager("lowerManager", 150);

    std::cout << boss << "\n" << middleManager << "\n" << lowerManager << "\n" << std::endl;

    std::cout << "--- Testing Shrubbery Creation Form ---" << std::endl;
    ShrubberyCreationForm shrub("Home");
    lowerManager.executeForm(shrub);
    boss.signForm(shrub);
    lowerManager.executeForm(shrub);
    middleManager.executeForm(shrub);

    std::cout << "\n--- Testing Robotomy Request Form ---" << std::endl;
    RobotomyRequestForm robot("Bender");
    middleManager.signForm(robot);
    middleManager.executeForm(robot);
    boss.executeForm(robot);
    boss.executeForm(robot);

    std::cout << "\n--- Testing Presidential Pardon Form ---" << std::endl;
    PresidentialPardonForm pardon("Ford Prefect");
    middleManager.signForm(pardon);
    boss.signForm(pardon);
    boss.executeForm(pardon);

    return 0;
}