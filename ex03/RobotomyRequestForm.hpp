#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Bureaucrat.hpp"
#include "Form.hpp"
class RobotomyRequestForm : public Form
{
private:
	std::string _target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(const std::string &target);
	void Execute(const Bureaucrat& executor) const;
	std::string get_target() const;
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm(void);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	Form *get_clone();
};

#endif