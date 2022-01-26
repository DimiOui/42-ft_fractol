define building
	@echo -n "$(shell tput setaf 6)Building $1 $(shell tput sgr0)"
	@make -sC $1 > /dev/null 2> /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define compiling
	@echo -n "$(shell tput bold)$(shell tput setaf 3)Compiling $1 $(shell tput sgr0)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $1 -o $2
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define finishing
	@echo -n "$(shell tput bold)$(shell tput setaf 2)Finishing $1 $(shell tput sgr0)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) $(LIBS) > /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define cleaning
	@echo -n "$(shell tput bold)$(shell tput setaf 8)Cleaning $1 $(shell tput sgr0)"
	@make $2 -sC $1 > /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define removing
	@echo -n "$(shell tput bold)$(shell tput setaf 8)Removing $1 $(shell tput sgr0)"
	@$(RM) $1 > /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

DONE		= @echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"

SRCS		= $(addprefix	srcs/, \
							algorithm.c \
							colors.c \
							hooks.c \
							main.c \
							display.c \
				)

OBJS		= $(SRCS:.c=.o)

NAME		= fract-ol

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g -O3

CPPFLAGS	= -I/usr/includes  -I minilibx -I includes

LIBS		= ./libft/libft.a minilibx/libmlx_Linux.a -lXext -lX11 -lm

%.o : %.c
			$(call compiling,$<,$(<:.c=.o),0)

${NAME}:	$(OBJS)
			$(call building,libft)
			$(call building,minilibx)
			$(call finishing,$(NAME))

all:		$(NAME)

clean:
			$(call removing,$(OBJS))

fclean:		clean
			$(call cleaning,libft,fclean)
			$(call cleaning,minilibx,clean)
			$(call removing,fract-ol)

re:			fclean all
