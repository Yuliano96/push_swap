# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 17:37:32 by ypacileo          #+#    #+#              #
#    Updated: 2025/02/09 21:21:25 by yuliano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Nombre del ejecutable
NAME = push_swap

# Archivos objeto
OBJS = apply_moves.o cal_mov_1.o cal_mov_2.o instructions_1.o instructions_2.o \
       mecanical_turk.o push_b.o sort_b.o sort_three.o util_1.o util_2.o main.o \
	   validation.o print_moves.o
# Flags del compilador
# -I./ indica que los headers están en el directorio actual
CFLAGS = -Wall -Wextra -Werror -I./

# Librerías necesarias
LIBS_1 = libft/libft.a
LIBS_2 = ft_printf/libftprintf.a

# Regla principal: compila todo
all: libs $(NAME)
	@echo "DONE"

# Compila las librerías
libs:
	@make -C libft
	@make -C ft_printf

# Compila el programa
$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(LIBS_1) $(LIBS_2) -o $(NAME)
	@echo "PUSH_SWAP COMPILED\n"

# Regla para compilar archivos .c a .o
%.o : %.c
	gcc -c $(CFLAGS) $< -o $@

# Limpieza de archivos objeto y librerías
clean:
	@make fclean -C ft_printf
	@make fclean -C libft
	rm -f $(OBJS)
# Limpieza completa (incluye ejecutables y librerías)
fclean: clean
	rm -f $(NAME)

# Regla para recompilar desde cero
# Llama a fclean y luego vuelve a compilar todo
re: fclean all
# Especificamos que estas reglas no son archivos reales, solo comandos
.PHONY: all clean fclean re libs
