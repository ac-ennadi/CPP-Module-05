#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("Default_target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    checkRequirements(executor);

    std::cout << "* BZZZZZT! Vrrrrrrrr! D-D-D-D-D-D-D! *" << std::endl;

    if (rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    }
    else {
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
    }
}