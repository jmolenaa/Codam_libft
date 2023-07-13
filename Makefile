NAME = libft.a
SRC_FILES_LIBFT =	ft_is_functions.c ft_str_functions.c ft_atoi.c ft_change_str_functions.c\
					ft_mem_functions.c ft_split.c ft_itoa.c ft_alloc_functions.c ft_str_join_functions.c\
					ft_put_char_str_fd.c ft_putnbr_fd.c ft_sing_list_functions1.c ft_sing_list_functions2.c\
					ft_array_functions.c ft_safe_alloc_and_free_null.c ft_dbl_list_functions1.c ft_dbl_list_functions2.c
SRC_FILES_GNL =		get_next_line.c get_next_line_utils.c
SRC_FILES_PRINTF =	char_conversion.c decimal_conversion.c flag_functions.c flag_validate.c ft_printf.c helper_functions.c\
					hexa_conversion.c percent_conversion.c pointer_conversion.c string_conversion.c unsigned_conversion.c validation.c
OBJFILES = $(SRC_FILES_LIBFT:%.c=obj/libft/%.o) $(SRC_FILES_GNL:%.c=obj/get_next_line/%.o) $(SRC_FILES_PRINTF:%.c=obj/printf/%.o)
OBJDIR = obj
DIRECTORIES = obj obj/libft obj/libft/chnstr/ obj/libft/mem obj/libft/lst obj/get_next_line obj/printf
CFLAGS ?= -Wall -Wextra -Werror
CC = cc
LIGHTGREEN=\033[1;32m
EXIT=\033[0m
DIM=\033[2m
YELLOW=\033[1;33m

all: $(NAME)

$(NAME): $(OBJFILES)
	@ar -csr $@ $^
	@echo " ${LIGHTGREEN}+-+-+-+-+-+-+";
	@echo " |S|u|c|c|e|s|";
	@echo " +-+-+-+-+-+-+${EXIT}";

obj/%.o: src/%.c $(OBJDIR)
	@$(CC) -iquote includes -c $(CFLAGS) -o $@ $<

$(OBJDIR):
	@echo " $(LIGHTGREEN)+-+-+-+-+-+-+-+-+-+  +-+-+-+-+-+";
	@echo " |C|o|m|p|i|l|i|n|g|  |l|i|b|f|t|";
	@echo " +-+-+-+-+-+-+-+-+-+  +-+-+-+-+-+$(EXIT)";
	@echo "$(DIM)\n...\n$(EXIT)"
	@mkdir $(DIRECTORIES)

clean:
	@echo " $(YELLOW)+-+-+-+-+-+-+-+-+  +-+-+-+  +-+-+-+-+-+";
	@echo " |C|l|e|a|n|i|n|g|  |o|b|j|  |f|i|l|e|s|";
	@echo " +-+-+-+-+-+-+-+-+  +-+-+-+  +-+-+-+-+-+$(EXIT)";
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "\n $(YELLOW)+-+-+-+-+-+-+-+-+  +-+-+-+-+-+";
	@echo " |D|e|l|e|t|i|n|g|  |l|i|b|f|t|";
	@echo " +-+-+-+-+-+-+-+-+  +-+-+-+-+-+$(EXIT)";
	@rm -f $(NAME)

re: fclean
	@echo "\n"
	@$(MAKE) all

.PHONY: all fclean clean re
