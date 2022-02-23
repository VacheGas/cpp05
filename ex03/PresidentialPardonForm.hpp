#ifndef PRESIDENTPARDONFORM_HPP
#define PRESIDENTPARDONFORM_HPP
#include "Bureaucrat.hpp"
#include "Form.hpp"
class PresidentialPardonForm : public Form
{
private:
	std::string _target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(const std::string &target);
	void Execute(const Bureaucrat& executor) const;
	std::string get_target() const;
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm(void);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	Form *get_clone();
};
#endif