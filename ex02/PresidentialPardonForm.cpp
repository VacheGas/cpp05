#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5)
{
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5) , _target("")
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form("PresidentialPardonForm", 25, 5), _target(other.getTarget())
{
}

int PresidentialPardonForm::get_target()
{
    return (this->_target);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &operator=(const PresidentialPardonForm &other)
{
    if(this == &other)
		return (*this);
    this->target = other.get_target();
	return (*this);
}

void PresidentialPardonForm::Execute(const Bureaucrat& executor)
{
    this->check
}