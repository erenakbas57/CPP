NAME = Serialization
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98


all: $(NAME)

$(NAME): *.o 
	$(CC) $(FLAGS) -o $(NAME) *.o

*.o: *.cpp
	$(CC) $(FLAGS) -c *.cpp

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re