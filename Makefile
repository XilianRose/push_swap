# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mstegema <mstegema@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/12 13:58:59 by mstegema      #+#    #+#                  #
#    Updated: 2023/07/21 13:46:14 by mstegema      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

# compilation
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
HEADER	= $(INCDIR)/$(NAME).h
LIBFT	= libft/bin/libft.a

ifdef DEBUG
LINKS	+= -fsanitize=address -g
endif

# directories
SRCDIR	= src
INCDIR	= inc
OBJDIR	= obj
BINDIR	= bin

# sources
SRCS	= src/main.c \
	src/parse.c \
	src/push.c \
	src/reverse-rotate.c \
	src/rotate.c \
	src/swap.c \
	src/stack-manipulation.c \
	src/median.c \
	src/pivot.c \
	src/sort1.c \
	src/sort2.c \
	src/utils.c

# objects
OBJS	= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# colours
PURPLE	= \033[0;35m
NC		= \033[0m

# rules
all: $(LIBFT) $(BINDIR)/$(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(BINDIR)/$(NAME): $(OBJS)
	@mkdir -p $(BINDIR)
	@$(CC) -o $(BINDIR)/$(NAME) $(OBJS) $(LIBFT) $(LINKS)
	@echo "$(PURPLE)$(NAME)$(NC) has been created"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	@$(CC) -c $(CFLAGS) $(LINKS) $< -o $@
	@echo "Compiling: $(PURPLE)$<$(NC)"

debug:
	$(MAKE) DEBUG=1

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJDIR)
	@echo "$(PURPLE)object files$(NC) have been removed"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(BINDIR)
	@echo "$(PURPLE)$(NAME) & directories$(NC) have been removed"

re: fclean all

.PHONY: all clean fclean re
