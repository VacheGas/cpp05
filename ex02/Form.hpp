#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Form
{
private:
	const				std::string name;
	bool				isSigned;
	const int			grade_sign;
	const int			grade_execute;
public:
	Form(std::string const &new_name, int new_garde_sign, int new_grade_execute);
	Form(Form const &other);
	Form();
	~Form();
	Form &operator=(Form const &other);
	std::string const &getName(void) const;
	int getGrade_sign(void) const;
	int getGrade_execute(void) const;
	bool getbwSigned() const;
	void beSigned(Bureaucrat const &bureaucrat);
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeAssighn : public std::exception
	{
		virtual const char* what() const throw();
	};
	void checkExecute(const Bureaucrat &buro);
};

std::ostream &operator<<(std::ostream &out, Form const &obj_form);
# endif