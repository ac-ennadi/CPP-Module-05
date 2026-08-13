#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(const std::string &name, const int signGrade, const int executeGrade)
    : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (this->signGrade < 1)
        throw GradeTooHighException();
    if (this->signGrade > 150)
        throw GradeTooLowException();
    if (this->executeGrade < 1)
        throw GradeTooHighException();
    if (this->executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecuteGrade() const { return executeGrade; }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= signGrade)
    {
        isSigned = true;
        return;
    }
    throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << form.getName() << ", sign grade " << form.getSignGrade()
       << ", execute grade " << form.getExecuteGrade()
       << ", signed: " << (form.getIsSigned() ? "true" : "false");
    return os;
}
