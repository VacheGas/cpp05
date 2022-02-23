#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <fstream>
class ShrubberyCreationForm : public Form
{
private:
	std::string _target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(const std::string &target);
	void Execute(const Bureaucrat& executor) const;
	std::string get_target() const;
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	Form *get_clone();
};
#endif