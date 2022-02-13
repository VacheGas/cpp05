#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#define MINBUR 150
#define MAXBUR 1
# include <iostream>
# include <exception>
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

	void incrementGrade(void);
	void decrementGrade(void);

};
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
#endif
