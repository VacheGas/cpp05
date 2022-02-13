#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#define MAXBUR 150
#define MINBUR 1
#include "Bureaucrat.hpp"
class Form
{
private:
	const				std::string name
	bool				iswhether;
	const int			grade_sign;
	const int			grade_execute;
public:
	Form(std::string const &new_name, int new_garde_sign, int new_grade_execute);
	Form &operator=(Form const &other);
	std::string const &getName(void) const;
	int getGrade_sign(void) const;
	int getGrade_execute(void) const;
	void beSigned(Bureaucrat const &bureaucrat);
	bool getisSigned();
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class AssignException : public std::exception
	{
		virtual const char* what() const throw();
	};
	Bureaucrat(Bureaucrat const &other);
	~Form();
};
#endif