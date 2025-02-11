# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 17:23:13 by theog             #+#    #+#              #
#    Updated: 2025/02/11 19:49:26 by tcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Fixed1.cpp bsp.cpp Point.cpp
OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
NAME = BSP

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compilation des fichiers objets
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJDIR)

# Nettoyage complet (obj + binaire)
fclean: clean
	rm -f $(NAME) a.out

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
