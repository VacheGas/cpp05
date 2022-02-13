#include "Form.hpp"

Form::Form(std::string const &new_name, int new_garde_sign, int new_grade_execute) : name(new_name) , grade_sign(new_garde_sign), grade_execute(new_grade_execute)
{
    this->isSigned = false;
}

const char*  Form::GradeTooHighException::what() const throw()
{
	return ("Hight 1(Form)");
}

const char*  Form::GradeTooLowException::what() const throw()
{
	return ("low 150(Form)");
}

int Form::getGrade_execute(void) const
{
	return (this->grade_execute);
}

int Form::getGrade_sign(void) const
{
	return (this->grade_sign);
}

std::string const &Form::getName(void) const
{
	return (this->name);
}

Form &Form::operator=(Form const &other)
{
   if(this == &other)
        return (*this);
    this->isSigned = other.isSigned;
    return (*this);
}

Form::Form(Form const &other) : name(other.name) , grade_sign(other.grade_sign), grade_execute(other.grade_execute)
{
    this->isSigned = other.isSigned;
    if (this->grade_execute < MINBUR && this->grade_sign < MINBUR)
		throw (Bureaucrat::GradeTooHighException());
	if (this->grade_execute > MINBUR && this->grade_sign > MINBUR)
		throw (Bureaucrat::GradeTooLowException());
}