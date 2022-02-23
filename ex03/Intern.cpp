#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &copy)
{
    *this = copy;
    return ;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(Intern const &rhs)
{
    if (this == &rhs)
		return (*this);
	return (*this);
}

Form	*Intern::makeForm(std::string const &formName, std::string const &target)
{
    ShrubberyCreationForm shrub(target);
	RobotomyRequestForm robot(target);
	PresidentialPardonForm pres(target);
	Form *arr_form[] = {&shrub, &robot, &pres};
    int i;

    i = 0;
    while (i < 3)
    {
        if (formName == arr_form[i]->getName())
            return(arr_form[i]->get_clone());
        i++;
    }
    std::cout << "form name miss" << std::endl;
    return (NULL);
}