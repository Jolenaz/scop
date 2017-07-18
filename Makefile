NAME = wordProScop

#==============#
#_- Compiler -_#
#==============#

CC = gcc
CFLAGS = -Werror -Wall -Wextra -g
RM = rm -rf

#====================#
#_- Programes Path -_#
#====================#

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/

#===========#
#_- Color -_#
#===========#

# color #
# red = 9
# hard_red = 196
# orange = 214
# violet = 140
# green = 47

TITLE_COLOR = 214
CLEAN_COLOR = 9
LINK_COLOR = 47
OBJ_COLOR = 47

MAKE_COLOR = 47
MAKE_ALREADY = 140
MAKE_FAIL = 9

#==============#
#_- Fonction -_#
#==============#

cmd_color = echo "\033[38;5;$(1)m$(2)\033[0m"; \
			$(2)

put_title = echo "\033[38;5;$(TITLE_COLOR)m[ $(1) ]\033[0m"

#==================#
#_- Source Files -_#
#==================#

SRC_NAME = main.c \
			init_world.c \
			init_shader.c 

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC = $(addprefix -I, $(INC_PATH)) -I/Users/jbelless/.brew/include/SDL2
LIB = -L/Users/jbelless/.brew/lib -lSDL2 -framework OpenGL

#INC = $(addprefix -I, $(INC_PATH)) -I/usr/local/include/SDL2#
#LIB = -L/usr/local/lib -lSDL2 -framework OpenGL#

#===========#
#_- Rules -_#
#===========#
all: $(NAME)

#	linking
$(OBJ_PATH)%.o:  $(SRC_PATH)%.c
	@$(call cmd_color,$(LINK_COLOR),$(CC) $(CFLAGS) $(INC)  -o $@ -c $< )

#	preLinking
$(OBJ_PATH):
	@$(call put_title,Linking)
	@mkdir -p $(OBJ_PATH)

#	Object Compiation
$(NAME): $(OBJ_PATH) $(OBJ)
	@$(call put_title,Compilation)
	@$(call cmd_make, $(LIB_PATH))
	@$(call cmd_color,$(OBJ_COLOR),$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB))

#	Removing object
clean:
	@$(call put_title,Cleaning)
	@$(RM) $(OBJ_PATH)
	@$(call cmd_color,$(CLEAN_COLOR),rm -rf $(OBJ))

#	Removeing binary
fclean : clean
	@$(RM) $(NAME)
	@$(call cmd_color,$(CLEAN_COLOR),rm -rf $(NAME))

re: fclean all