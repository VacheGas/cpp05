 #include "Bureaucrat.hpp"

 int main()
 {
     Bureaucrat b("aram",4);

    std::cout << b;
    b.incrementGrade();
    std::cout << b;
    b.decrementGrade();
    std::cout << b;
    try
    {
        Bureaucrat a("grno",0);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    Bureaucrat a(b);
    std::cout << b << a;
    b.decrementGrade();
    b.decrementGrade();
    b.decrementGrade();
    std::cout << b;
    try
    {
        b.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        Bureaucrat c("grno",151);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    Bureaucrat  c = a;
    std::cout << c << a;
    try
    {
        c = Bureaucrat("grno",151);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        c = Bureaucrat("grno",0);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
 }