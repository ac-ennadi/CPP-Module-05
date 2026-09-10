#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
}

AForm* Intern::createShrubbery(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName,
                        const std::string& target) const {
    if (formName == "shrubbery creation") {
        return createShrubbery(target);
    }
    if (formName == "robotomy request") {
        return createRobotomy(target);
    }
    if (formName == "presidential pardon") {
        return createPardon(target);
    }
    return NULL;
}