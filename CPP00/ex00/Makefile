C++ = c++
SRCS = megaphone.cpp
OBJ = $(SRCS:.cpp=.o)
NAME = megaphone
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(CPPFLAGS) $(OBJ) -o $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) *.o

re: fclean all

.PHONY: all clean