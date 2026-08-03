*This project has been created as part of the 42 curriculum by mnaouss.*

# CPP Module 05

## Description

CPP Module 05 is the sixth C++ module in the 42 curriculum. Its goal is to
introduce exception handling while reinforcing Orthodox Canonical Form,
inheritance, abstract classes, and polymorphism in C++98.

The project contains four exercises:

- `ex00`: `Bureaucrat`, a class with a constant name and a grade constrained
  between 1 and 150, including exceptions for invalid grade operations.
- `ex01`: `Form`, which introduces sign and execution grade requirements and
  allows bureaucrats to sign forms when their grade is high enough.
- `ex02`: `AForm`, an abstract base class with three concrete forms:
  `ShrubberyCreationForm`, `RobotomyRequestForm`, and
  `PresidentialPardonForm`.
- `ex03`: `Intern`, which uses a factory method to create the requested concrete
  form from its name and target.

## Instructions

Each exercise has its own `Makefile`. Build and run it from its exercise
directory.

### ex00

```sh
cd ex00
make
./bureaucrat
make fclean
```

### ex01

```sh
cd ex01
make
./bureaucrat
make fclean
```

### ex02

```sh
cd ex02
make
./forms
make fclean
```

### ex03

```sh
cd ex03
make
./forms
make fclean
```

The project is written for C++98 and is compiled with:

```sh
c++ -Wall -Wextra -Werror -std=c++98
```

## Resources

- C++ reference: https://cplusplus.com/reference/
- Exceptions: https://cplusplus.com/doc/tutorial/exceptions/
- Classes: https://cplusplus.com/doc/tutorial/classes/
- Inheritance: https://cplusplus.com/doc/tutorial/inheritance/
- Polymorphism: https://cplusplus.com/doc/tutorial/polymorphism/
- File streams: https://cplusplus.com/doc/tutorial/files/

AI was used as a learning assistant to clarify concepts, review project
requirements, and help prepare documentation. The final code was reviewed and
tested locally with the required compiler flags.
