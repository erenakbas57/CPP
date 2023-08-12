NAME		= Human
SRCS		= main.cpp
CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
OBJ			= $(SRCS:.cpp=.o)
RM 			= rm -rf

all		: $(NAME)

$(NAME): $(OBJ)
		 $(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

fclean	: clean
		  $(RM) $(NAME)

clean	: 
		 $(RM) *.o

re		: fclean all

.PHONY	: all clean