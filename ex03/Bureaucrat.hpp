#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#define MAXBUR 150
#define MINBUR 1
# include <iostream>
# include <exception>
# include <string>
#include "Form.hpp"
class Form;
class Bureaucrat
{
private:
	int grade;
	std::string name;
public:
	Bureaucrat(/* args */);
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	virtual ~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &other);
	std::string const &getName(void) const;
	int getGrade(void) const;
	void signForm(Form & form) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void executeForm(Form const & form) const;

};
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
#endif
