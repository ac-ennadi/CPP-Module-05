#include "Bureaucrat.hpp"
#include <iostream>


Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
	if (this->grade < highest)
		throw GradeTooHighException();
	if (this->grade > lowest)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat() : name("Default"), grade(highest) {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {if (this != &other) {grade = other.grade;} return *this;}

int Bureaucrat::getGrade() const {return (grade);}
const std::string &Bureaucrat::getName() const {return (name);}

const char *Bureaucrat::GradeTooHighException::what() const throw () {
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void Bureaucrat::incrementGrade() {
	if (grade <= highest)
		throw GradeTooHighException();
	--grade;
}

void Bureaucrat::decrementGrade() {
	if (grade >= lowest)
		throw GradeTooLowException();
	++grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}