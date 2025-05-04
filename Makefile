# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 15:27:16 by ilchahbi          #+#    #+#              #
#    Updated: 2024/12/29 14:43:06 by kid-ouis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

BNAME = cub3D_bonus

MAN_DIR = man_cub

BO_DIR = cub_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror 

MLX_P = MLX42/build

MLX_LIB = -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

SRC = $(MAN_DIR)/main.c $(MAN_DIR)/get_next_line.c $(MAN_DIR)/get_next_line_utils.c $(MAN_DIR)/tools.c \
		$(MAN_DIR)/check_content.c $(MAN_DIR)/ft_split.c $(MAN_DIR)/ft_atoi.c $(MAN_DIR)/check_map.c \
		$(MAN_DIR)/fill_textures.c $(MAN_DIR)/ft_buttons.c $(MAN_DIR)/ren_again.c \
		$(MAN_DIR)/ft_rays_cast.c $(MAN_DIR)/ft_walls_rend.c $(MAN_DIR)/utils_functions.c $(MAN_DIR)/utils_functions2.c \
		$(MAN_DIR)/tools_2.c $(MAN_DIR)/fill_textures_2.c $(MAN_DIR)/get_data.c $(MAN_DIR)/cast_utils.c
		
BSRC = $(BO_DIR)/main_bonus.c $(BO_DIR)/get_next_line_bonus.c $(BO_DIR)/get_next_line_utils_bonus.c $(BO_DIR)/tools_bonus.c \
		$(BO_DIR)/check_content_bonus.c $(BO_DIR)/ft_split_bonus.c $(BO_DIR)/ft_atoi_bonus.c $(BO_DIR)/check_map_bonus.c \
		$(BO_DIR)/fill_textures_bonus.c $(BO_DIR)/alternate_func_bonus.c $(BO_DIR)/ft_buttons_bonus.c $(BO_DIR)/ren_again_bonus.c \
		$(BO_DIR)/ft_rays_cast_bonus.c $(BO_DIR)/ft_walls_rend_bonus.c $(BO_DIR)/utils_functions_bonus.c $(BO_DIR)/utils_functions2_bonus.c \
		$(BO_DIR)/mini_map_bonus.c $(BO_DIR)/tools_2_bonus.c $(BO_DIR)/fill_textures_2_bonus.c $(BO_DIR)/get_data_bonus.c $(BO_DIR)/cast_utils_bonus.c

OBJ = $(SRC:$(MAN_DIR)/%.c=$(MAN_DIR)/%.o)

BOBJ = $(BSRC:$(BO_DIR)/%bonus.c=$(BO_DIR)/%bonus.o)

all: mlx $(NAME)

mlx : $(MLX_P) $(MLX_P)/libmlx42.a

$(MLX_P) :
	cmake -S ./MLX42 -B $(MLX_P)

$(MLX_P)/libmlx42.a :
	make -C $(MLX_P)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_P)/libmlx42.a $(MLX_LIB) $(FRAMEWORKS) -o $@

bonus: mlx $(BNAME)
$(BNAME): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) $(MLX_P)/libmlx42.a $(MLX_LIB) $(FRAMEWORKS) -o $@

$(BO_DIR)/%.o: $(BO_DIR)/%.c $(BO_DIR)/cub3D_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(MAN_DIR)/%.o: $(MAN_DIR)/%.c $(MAN_DIR)/cub3D.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME) $(BNAME)
	rm -rf $(MLX_P)

re: fclean all
