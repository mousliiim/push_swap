NAME			=	push_swap

NAME_BONUS		=	checker

LIBFT			=	includes/libft/libft.a

PRINTF			=	includes/ft_printf/libftprintf.a

GNL				=	bonus/includes_bonus/get_next_line_bonus/get_next_line_bonus.c \
					bonus/includes_bonus/get_next_line_bonus/get_next_line_utils_bonus.c \

SRCS			=	main.c misc/parsing.c misc/movement.c misc/movement_utils.c \
					misc/utils.c misc/utils_second.c misc/sort_algo.c misc/algo_lis.c \
					misc/run_best_move.c misc/find_best_move.c misc/utils_third.c \

SRCS_BONUS 		=	bonus/main_bonus.c bonus/misc_bonus/parsing_bonus.c \
					bonus/misc_bonus/movement_bonus.c bonus/misc_bonus/movement_utils_bonus.c \
					bonus/misc_bonus/utils_bonus.c bonus/misc_bonus/utils_second_bonus.c \
					bonus/misc_bonus/utils_third_bonus.c \

# Colors
DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
PURPLE= \033[38;2;255;105;180m

OBJS			=	${SRCS:.c=.o}

OBJS_BONUS		= 	${SRCS_BONUS:.c=.o}

HEAD			=	-I includes

CFLAGS			=	-Wall -Werror -Wextra -D BENCH=0

all				:	${NAME}

.c.o	:
		@cc  ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}=== MAKE ${PURPLE}MANDATORY ⌛${DEF_COLOR}${GREEN}===${DEF_COLOR}"
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}\n"
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}LIBFT ⌛${DEF_COLOR}${GREEN}=====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}\n"
	@make --no-print-directory -C includes/libft
	@echo "\t\t\t${GREEN}=============================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}FT_PRINTF${DEF_COLOR} ⌛${GREEN} =====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}=============================${DEF_COLOR}\n"
	@make --no-print-directory -C includes/ft_printf
	@echo "\t\t\t${GREEN}==============================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}==== ALL IS ${PURPLE}COMPILATED${DEF_COLOR} ✅${GREEN} ====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}==============================${DEF_COLOR}"
	@cc $(OBJS) ${LIBFT} ${PRINTF} -o $(NAME)


$(NAME_BONUS) : $(OBJS_BONUS)
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}=== MAKE ${PURPLE}BONUS ⌛${DEF_COLOR}${GREEN}===${DEF_COLOR}"
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}\n"
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}LIBFT ⌛${DEF_COLOR}${GREEN}=====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}\n"
	@make --no-print-directory -C includes/libft
	@echo "\t\t\t${GREEN}=============================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}FT_PRINTF${DEF_COLOR} ⌛${GREEN} =====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}=============================${DEF_COLOR}\n"
	@make --no-print-directory -C includes/ft_printf
	@echo "\t\t\t${GREEN}==============================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}==== ALL IS ${PURPLE}COMPILATED${DEF_COLOR} ✅${GREEN} ====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}==============================${DEF_COLOR}"
	@cc $(OBJS_BONUS) ${GNL} ${LIBFT} ${PRINTF} -o $(NAME_BONUS)

bonus: ${NAME_BONUS}

clean			:
					make clean -C includes/libft/
					make clean -C includes/ft_printf/
					rm -rf ${OBJS}
					rm -rf ${OBJS_BONUS}

fclean			:	clean
					make fclean -C includes/libft/
					make fclean -C includes/ft_printf/
					rm -rf ${LIBFT}
					rm -rf ${PRINTF}
					rm -rf ${NAME} ${NAME_BONUS}

re				:	fclean all

.PHONY			:	all clean fclean re bonus
