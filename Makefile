NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = $(wildcard ./srcs/*.c)
SRCS_BONUS = $(wildcard ./srcs_bonus/*.c)
OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -o $@
re: fclean all

.PHONY: fclean all clean re bonus