#include "Bureaucrat.hpp"

std::string const &Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if ((this->grade + 1) > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if ((this->grade - 1) < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->grade++;
}

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string const &new_name, int new_grade)
{
	if (new_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (new_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = new_grade;
	this->name = new_name;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	if (other.getGrade() < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (other.getGrade() > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = other.getGrade();
	this->name = other.getName();
}

const char*  Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Hight 150");
}

const char*  Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("low 1");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << "Name = " << bureaucrat.getName() << "  Grade = " << bureaucrat.getGrade() << std::endl;
 
	return (out);
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	this->grade = other.grade;
	this->name = other.name;
	if (this->grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (this->grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	return (*this);
}

void Bureaucrat::signForm(Form & form) const
{
	if(form.getbwSigned())
		std::cout << this->getName() << " its not ok because "<<form.getName()<<" arden signed" << std::endl;   
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->name << " signs " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << this->getName() << " cannot assighn because " << form.getName() << e.what() << '\n';
		}		
	}
}

void Bureaucrat::executeForm(Form const & form) const
{
	try
	{
		form.Execute(*this);
		std::cout << this->name << " execute " << form.getName();
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " can not execute " << form.getName() << "because ";
		std::cerr << e.what() << '\n';
	}
}
