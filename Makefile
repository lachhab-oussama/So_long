NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = key_hooks.c prepare_map.c put_background.c so_long.c wall_img.c ./get_next_line_utils.c ./get_next_line.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@ rm -f $(OBJS)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
