NAME			=	philo


SRC_PATH		=	src/

SRC				=\
	main.c


DIR_INCS		=\
	include/			\
	$(LIBFT_INCLUDES)	\
	/opt/homebrew/opt/readline/include

INCLUDES		=	$(addprefix -I , $(DIR_INCS))

DIR_BUILD		=	.build/
OBJS			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRC))
DEPS			=	$(patsubst %.c, $(DIR_BUILD)%.d, $(SRC))
DEPS_FLAGS		=	-MMD -MP
CFLAGS			=	-Wall -Wextra -Werror  -g3 -fsanitize=address -g3
RM				=	rm -rf
AR				=	ar rcs


LIBFT_PATH		=	lib/libft/
LIBFT_INCLUDES	=	$(LIBFT_PATH)include
LIBFT_L			=	-L$(LIBFT_PATH) -lft
LIBFT_L_DEBUG	=	-L$(LIBFT_PATH) -lft_debug
LIBFT_A			=	$(LIBFT_PATH)libft.a
LIBFT_A_DEBUG	=	$(LIBFT_PATH)libft_debug.a
MAKE_LIBFT		=	$(MAKE) -C $(LIBFT_PATH)

DEPENDENCIES	=	$(LIBFT_A)

.PHONY:		all
all:
			$(MAKE_LIBFT)
			$(MAKE) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_L) -o $(NAME)


.PHONY:	clean
clean:
		$(MAKE_LIBFT) clean
		$(RM) $(DIR_BUILD)

.PHONY:	fclean
fclean:	clean
		$(MAKE_LIBFT) fclean
		$(RM) $(NAME)

.PHONY:	re
re:		fclean
		$(MAKE) all

.PHONY:	leaks
leaks:	all
		echo "{" > valgrind_ignore_leaks.txt
		echo "    leak readline" >> valgrind_ignore_leaks.txt
		echo "    Memcheck:Leak" >> valgrind_ignore_leaks.txt
		echo "    ..." >> valgrind_ignore_leaks.txt
		echo "    fun:readline" >> valgrind_ignore_leaks.txt
		echo "}" >> valgrind_ignore_leaks.txt
		echo "{" >> valgrind_ignore_leaks.txt
		echo "    leak add_history" >> valgrind_ignore_leaks.txt
		echo "    Memcheck:Leak" >> valgrind_ignore_leaks.txt
		echo "    ..." >> valgrind_ignore_leaks.txt
		echo "    fun:add_history" >> valgrind_ignore_leaks.txt
		echo "}" >> valgrind_ignore_leaks.txt
		valgrind --suppressions=valgrind_ignore_leaks.txt --leak-check=full\
			--show-leak-kinds=all --track-origins=yes --verbose\
			--show-mismatched-frees=yes --read-var-info=yes ./${NAME}

-include $(DEPS)

$(DIR_BUILD)%.o : $(SRC_PATH)%.c $(LIBFT_A)
		mkdir -p $(shell dirname $@)
		$(CC) $(CFLAGS) $(DEPS_FLAGS) $(INCLUDES) -c $< -o $@
