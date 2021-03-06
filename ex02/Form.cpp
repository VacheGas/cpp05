#include "Form.hpp"

Form::Form(std::string const &new_name, int new_garde_sign, int new_grade_execute) : name(new_name) , grade_sign(new_garde_sign), grade_execute(new_grade_execute)
{
	if (this->grade_execute < MINBUR || this->grade_sign < MINBUR)
		throw (Form::GradeTooHighException());
	if (this->grade_execute > MAXBUR || this->grade_sign > MAXBUR)
		throw (Form::GradeTooLowException());
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
const char*  Form::GradeAssighn::what() const throw()
{
	return ("arden assighn exach chi");
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
	if (this->grade_execute > MAXBUR && this->grade_sign > MAXBUR)
		throw (Bureaucrat::GradeTooLowException());
}

void Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > this->grade_sign)
	{
		throw Form::GradeTooLowException();
	}
	this->isSigned = true;
}

Form::~Form()
{
}

bool Form::getbwSigned() const
{
	return (this->isSigned);
}

std::ostream &operator<<(std::ostream &out, Form const &obj_form)
{
	std::string signed_str;
	if(obj_form.getbwSigned())
		signed_str = "Signed";
	else
		signed_str = "UnSigned";
	out << "Name = " << obj_form.getName() << "  Grade sign = " << obj_form.getGrade_sign() << " getGrade execute = " << obj_form.getGrade_execute() << " signed = "<< signed_str << std::endl;
	return (out);
}

void Form::checkExecute(const Bureaucrat &buro) const
{
	if (this->isSigned == false)
		throw GradeAssighn();
	if (this->grade_execute < buro.getGrade())
		throw GradeTooLowException();
}