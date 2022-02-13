 #include "Form.hpp"

 int main()
 {
    Bureaucrat b("aram",4);
   Form f("accounting", 15, 12);
   Form f2("acc2",1, 1);
    std::cout << f << f2;
   f = f2;
    std::cout << f << f2;
    f2.beSigned(b);
    std::cout << f << f2;
    f.beSigned(b);
   return (0);
 }