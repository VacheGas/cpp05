#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form("RobotomyRequestForm", 72, 45)
{
    this->_target = target;
}

void RobotomyRequestForm::Execute(const Bureaucrat& executor) const
{
    this->checkExecute(executor);
    std::cout << "drilling noise" << std::endl;
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized successfully " << std::endl;
    else
        std::cout << this->_target << "has been robotomized failed" << std::endl;
}

std::string RobotomyRequestForm::get_target() const
{
    return (this->_target);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this == &other)
		return (*this);
    this->_target = other.get_target();
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form("RobotomyRequestForm", 72, 45)
{
    this->_target = other.get_target();
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}


RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
{
}

Form *RobotomyRequestForm::get_clone()
{
    return (new RobotomyRequestForm(this->_target));
}