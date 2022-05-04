NAME = so_long
MAN_SRC 			= ft_so_long.c ft_so_long_utils.c ft_change_axi_position.c ft_check_filename.c \
					ft_check_map_char.c ft_check_map_rect.c ft_draw_map.c ft_draw_utils.c \
					ft_get_file_to_str.c ft_init_draw_utils_func_ptr.c ft_init_game_parametor.c \
					ft_init_map.c ft_init_mlx_instance.c ft_keyevent.c
BONUS_SRC 			= ft_so_long_bonus.c ft_so_long_utils_bonus.c ft_change_axi_position_bonus.c \
					ft_check_filename_bonus.c ft_check_map_char_bonus.c ft_check_map_rect_bonus.c \
					ft_draw_map_bonus.c ft_draw_utils_bonus.c ft_get_file_to_str_bonus.c \
					ft_init_draw_utils_func_ptr_bonus.c ft_init_game_parametor_bonus.c \
					ft_init_map_bonus.c ft_init_mlx_instance_bonus.c ft_keyevent_bonus.c ft_enemy_bonus.c
MAN_OBJ 			= $(MAN_SRC:.c=.o)
MAN_OBJ_FULLNAME 	= $(addprefix ./obj/src_obj/, $(MAN_OBJ))
MAN_DEPS 			= $(MAN_SRC:.c=.d)
MAN_DEPS_FULLNAME	= $(addprefix ./obj/src_obj/, $(MAN_DEPS))
BONUS_OBJ 			= $(BONUS_SRC:.c=.o)
BONUS_OBJ_FULLNAME 	= $(addprefix ./obj/bonus_src_obj/, $(BONUS_OBJ))
BONUS_DEPS			= $(BONUS_SRC:.c=.d)
BONUS_DEPS_FULLNAME = $(addprefix ./obj/bonus_src_obj/, $(BONUS_DEPS))
MLXDIR				= ./minilibx-linux
SRCDIR				= ./src
BONUS_SRCDIR		= ./bonus_src
OBJDIR 				= ./obj
SRC_OBJDIR 			= $(OBJDIR)/src_obj
BONUS_SRC_OBJDIR 	= $(OBJDIR)/bonus_src_obj
LIBFTDIR 			= ./libft
LIBFT_OBJDIR 		= $(OBJDIR)/libft_obj
LIBFTNAME 			= $(LIBFTDIR)/libft.a
PRINTFDIR			= ./printf
PRINTF_OBJDIR 		= $(OBJDIR)/printf_obj
SRCPRINTF 			= ft_printf.c ft_fmt_csper.c ft_fmt_diuxXp.c ft_printf_utils.c
OBJPRINTF 			= $(SRCPRINTF:.c=.o)
OBJPRINTF_FULLNAME  = $(addprefix ./obj/printf_obj/, $(OBJPRINTF))
CC 					= gcc
DEBUG_FLAG 			=
CFLAG 				= -Wall -Wextra -Werror $(DEBUG_FLAG)
DEPSFLAG 			= -MMD -MP

UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
LIB_FLAG 	= -L$(MLXDIR) -lmlx_Linux -L/usr/lib -lXext -lX11
else ifeq ($(UNAME), Darwin)
LIB_FLAG 	= -L$(MLXDIR) -lmlx_Darwin -L/usr/lib -L/usr/X11R6/lib -lXext -lX11
endif

ifdef SO_LONG_BONUS
OBJ 	= $(BONUS_OBJ_FULLNAME)
DEPS 	= $(BONUS_DEPS_FULLNAME)
INC_FLAG 	= -I/usr/include -I$(MLXDIR) -I./include/inc_bonus_src -I$(LIBFTDIR) -I$(PRINTFDIR)
else
OBJ 	= $(MAN_OBJ_FULLNAME)
DEPS 	= $(MAN_DEPS_FULLNAME)
INC_FLAG 	= -I/usr/include -I$(MLXDIR) -I./include/inc_src -I$(LIBFTDIR) -I$(PRINTFDIR)
endif

all:make-objdir make-mlx make-libft make-printf $(NAME)

$(NAME): $(LIBFTNAME) $(OBJPRINTF_FULLNAME) $(OBJ)
	$(CC) $(CFLAG) $(INC_FLAG) $(OBJ) $(LIB_FLAG) $(OBJPRINTF_FULLNAME) $(LIBFTNAME)  -o $(NAME)

$(SRC_OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAG) $(DEPSFLAG) $(INC_FLAG) -o $@ -c $<

$(BONUS_SRC_OBJDIR)/%.o:$(BONUS_SRCDIR)/%.c
	$(CC) $(CFLAG) $(DEPSFLAG) $(INC_FLAG) -o $@ -c $<

make-objdir:
	if [ ! -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi
	if [ ! -d $(SRC_OBJDIR) ]; then mkdir $(SRC_OBJDIR); fi
	if [ ! -d $(BONUS_SRC_OBJDIR) ]; then mkdir $(BONUS_SRC_OBJDIR); fi
	if [ ! -d $(LIBFT_OBJDIR) ]; then mkdir $(LIBFT_OBJDIR); fi
	if [ ! -d $(PRINTF_OBJDIR) ]; then mkdir $(PRINTF_OBJDIR); fi
make-mlx:
	$(MAKE) -C $(MLXDIR)
make-libft:
	$(MAKE) -C $(LIBFTDIR)
make-printf:
	$(MAKE) -C $(PRINTFDIR)

bonus:
	make SO_LONG_BONUS="true"

clean:
	rm -rf $(MAN_OBJ_FULLNAME)
	rm -rf $(BONUS_OBJ_FULLNAME)
	rm -rf $(MAN_DEPS_FULLNAME)
	rm -rf $(BONUS_DEPS_FULLNAME)
	$(MAKE) clean -C $(MLXDIR)
	$(MAKE) fclean -C $(LIBFTDIR)
	$(MAKE) clean -C $(PRINTFDIR)

fclean:clean
	rm -rf $(NAME)

re:fclean all

debug:
	make DEBUG_FLAG="-g -fsanitize=address -fsanitize=leak"
debug-bonus:
	make bonus DEBUG_FLAG="-g -fsanitize=address -fsanitize=leak"
valgrind:
	make DEBUG_FLAG="-g" && valgrind --leak-check=full --track-origins=yes ./so_long maps/big_map.ber
valgrind-bonus:
	make bonus DEBUG_FLAG="-g" && valgrind --leak-check=full --track-origins=yes ./so_long maps/big_map.ber

.PHONY:all bonus clean fclean re make-objdir make-mlx make-libft make-printf debug valgrind

-include $(DEPS)
