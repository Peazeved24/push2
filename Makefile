NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c utils.c utils2.c opRotate.c opSwap.c opPush.c opReverserotate.c opSort.c opRadix.c split.c utilsmain.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)


.PHONY: all clean fclean re

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
