
NAME = form_28B

SRCS = main 

CLS = Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS:=.o) $(CLS:=.o)
	$(CXX) $(CXXFLAGS) $(SRCS:=.o) $(CLS:=.o) -o $(NAME)
	@echo "\e[0;32m Exercise : \e[1;36m$(NAME)\e[0;32m compiled successfully\e[0m"

clean:
	@rm -fr $(SRCS:=.o) $(CLS:=.o)
	@echo "\e[0;31m Removed object files.\e[0m"

fclean: clean
	@rm -fr $(NAME)
	@rm -fr *.txt
	@echo "\e[0;31m Removed executable \e[1;36m$(NAME)\e[0;31m.\e[0m"

re: fclean $(NAME)

rec: re
	@rm -fr $(SRCS:=.o) $(CLS:=.o)
	@rm -fr *.txt
	@echo "\e[0;31m Removed object files.\e[0m"

.PHONY: all clean fclean re rec