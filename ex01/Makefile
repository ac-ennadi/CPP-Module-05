CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Form
SRC = main.cpp Bureaucrat.cpp Form.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) a.out

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: