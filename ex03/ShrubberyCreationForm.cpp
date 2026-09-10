#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("Default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    checkRequirements(executor);

    std::ofstream outFile((_target + "_shrubbery").c_str());
    if (outFile.is_open()) {
        outFile << "       _-_" << std::endl;
        outFile << "    /~~   ~~\\" << std::endl;
        outFile << " /~~         ~~\\" << std::endl;
        outFile << "{               }" << std::endl;
        outFile << " \\  _-     -_  /" << std::endl;
        outFile << "   ~  \\\\ //  ~" << std::endl;
        outFile << "_- -   | | _- _" << std::endl;
        outFile << "  _ -  | |   -_" << std::endl;
        outFile << "      // \\\\" << std::endl;
        outFile.close();
    }
    else {
        std::cerr << "Error: Could not open file for writing." << std::endl;
    }
}