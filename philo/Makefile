CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD -g3

HEADERS = philo.h

SOURCES = main.c \
		ft_atoi.c \
		parsing.c \
		init_data.c \
		init_mutex.c \
		time.c \
		ft_philo.c \
		sadly_alone_guy.c \
		create_thread.c \
		fn_philo.c \
		cycle.c \
		mutex_printf.c \
		death.c \
		check_end.c \
		error.c \
		destroy_all.c

SRC = srcs/
DIR = objs_deps/
INC = includes/

INCLUDES = -I/$(INCS)

SRCS = $(addprefix $(SRC), $(SOURCES))
OBJS = $(addprefix $(DIR), $(OBJ))
DEPS = $(addprefix $(DIR), $(DEP))
INCS = $(addprefix $(INC), $(HEADERS))

OBJ = $(SOURCES:.c=.o)
DEP = $(SOURCES:.c=.d)

NAME = philo

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)
	@echo "Compilation completed"

$(DIR)%.o : $(SRC)%.c | $(DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(DIR) :
	@echo "Start Compilation for $(NAME)"
	@echo "Wait ..."
	@mkdir -p objs_deps

clean :
	@echo "Deleting Objects and Dependencies"
	@rm -rf $(DIR)

fclean : clean
	@echo "Deleting the executable"
	@rm -f $(NAME)

re : fclean all

-include $(DEPS)

.PHONY : all bonus clean fclean re