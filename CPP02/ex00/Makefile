NAME	 = Fixed
SRCS	 = main.cpp Fixed.cpp
CPP		 = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ	 	 = $(SRCS:.cpp=.o)
RM		 = rm -rf

all:	$(OBJ)
		$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean: 	
		$(RM) *.o

fclean:	clean
		$(RM) $(NAME)

re:		fclean all