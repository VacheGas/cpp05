#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5)
{
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5) , _target("")
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form("PresidentialPardonForm", 25, 5)
{
    this->_target = other.get_target();
}

std::string PresidentialPardonForm::get_target() const
{
    return (this->_target);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if(this == &other)
		return (*this);
    this->_target = other.get_target();
	return (*this);
}

void PresidentialPardonForm::Execute(const Bureaucrat& executor) const
{
    this->checkExecute(executor);
    std::cout << executor.getName() << " Tells us "<< this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

Form *PresidentialPardonForm::get_clone()
{
    return (new PresidentialPardonForm(this->_target));
}