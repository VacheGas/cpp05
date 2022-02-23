#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
class Bureaucrat;
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
	virtual ~Form();
	Form &operator=(Form const &other);
	std::string const &getName(void) const;
	int getGrade_sign(void) const;
	int getGrade_execute(void) const;
	bool getbwSigned() const;
	virtual void Execute(const Bureaucrat& executor) const = 0;
	void beSigned(Bureaucrat bureaucrat);
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
	void checkExecute(const Bureaucrat &buro) const;
	virtual Form	*get_clone() = 0;
};

std::ostream &operator<<(std::ostream &out, Form const &obj_form);
# endif