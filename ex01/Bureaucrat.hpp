#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <ostream>
#include <iostream>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
        static const int highest = 1;
        static const int lowest = 150;

    public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    
    void incrementGrade();
    void decrementGrade();
    int getGrade() const;
    const std::string &getName() const;
    
    class GradeTooHighException : public std::exception {virtual const char *what() const throw();};
    class GradeTooLowException : public std::exception {virtual const char *what() const throw();};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif