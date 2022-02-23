#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
# include <string>

class Intern {

private:
    std::string get_ShrubberyCreationForm(const std::string &target) const;
    std::string get_PresidentialPardonForm(const std::string &target) const;
    std::string get_RobotomyRequestForm(const std::string &target) const;
public:
	Intern();
	Intern(Intern const &copy);
	virtual ~Intern();
	Intern	&operator=(Intern const &rhs);
	Form	*makeForm(std::string const &formName, std::string const &target);
};

#endif