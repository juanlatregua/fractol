# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_Unix.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 21:36:38 by W2Wizard          #+#    #+#              #
#    Updated: 2024/10/03 09:25:32 by jsilva-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
RED		:= \033[31;1m
GREEN	:= \033[32;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m
U_LINE	:= \033[4m
BLUE = \033[1;38;5;27m

#//= Make Rules =//#
$(NAME): $(OBJS)
	@ar rc $@ $^
	@echo "\n$(WHITE)$(U_LINE)  MLX42: Compiled $(RESET)\n"

%.o: %.c $(HDRS)
	@echo "$(BLUE)MLX Compiling:$(RESET) $(notdir $<)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

# Convert shaders to .c files
$(SRC_DIR)/mlx_%_shader.c: $(SHADER_DIR)/default.%
#	@echo "$(GREEN)$(BOLD)Shader to C: $< -> $@$(RESET)"
	@bash tools/compile_shader.sh $< > $@

clean:
	@echo "$(RED)Cleaning...$(RESET)"
	@rm -f $(OBJS) $(SHDR)

fclean: clean
	@rm -f $(NAME)
