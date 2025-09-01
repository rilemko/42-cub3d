# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 23:43:39 by mconreau          #+#    #+#              #
#    Updated: 2024/03/28 14:30:02 by mconreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#///// PROJECT : CONFIGURATION ////////////////////////////////////////////////#

# > GENERAL <<<<<<<<<<<<<<

PROJECT_NAME			:=	cub3d
PROJECT_ARCHIVES		:=	./libraries/42-libft/libft.a ./libraries/MLX42/build/libmlx42.a
PROJECT_DEPENDENCIES	:=	./libraries/42-libft
PROJECT_HEADERS			:=	./includes ./libraries/42-libft/includes ./libraries/MLX42/include/MLX42
PROJECT_LIBRARIES		:=	

# > COMPILATION <<<<<<<<<<

COMPILER_PROGRAM		:=	clang-12
COMPILER_PROGRAM_DEBUG	:=	-fsanitize=undefined
COMPILER_PROGRAM_FLAGS	:=	-O3 -o
ifeq ($(filter-out $@,$(shell uname)), Linux)
COMPILER_PROGRAM_OTHER	:=	-ldl -lglfw -pthread -lm
else ifeq ($(filter-out $@,$(shell uname)), Darwin)
COMPILER_PROGRAM_OTHER	:=	-framework Cocoa -framework OpenGL -framework IOKit -lglfw
endif
COMPILER_OBJECTS		:=	clang-12
COMPILER_OBJECTS_FLAGS	:=	-O3 -g -Wall -Werror -Wextra

# > EXTENSIONS <<<<<<<<<<<

EXTENSION_SOURCE		:=	.c
EXTENSION_OBJECT		:=	.o

# > DIRECTORIES <<<<<<<<<<

FOLDER_SOURCES			:=	./sources

#///// PROJECT : SOURCES //////////////////////////////////////////////////////#

# > MANDATORY <<<<<<<<<<<<

PROJECT_SOURCES			:=	$(addprefix $(FOLDER_SOURCES)/, main.c			\
							app/ft_app_abort.c								\
							app/ft_app_exit.c								\
							bootstrap/ft_bootstrap.c						\
							bootstrap/process/ft_bot_process_err.c			\
							bootstrap/process/ft_bot_process_key.c			\
							bootstrap/process/ft_bot_process_rdr.c			\
							bootstrap/process/ft_bot_process_src.c			\
							bootstrap/process/ft_bot_process_tkn.c			\
							canvas/ft_canvas_darken.c						\
							canvas/ft_canvas_lighten.c						\
							canvas/ft_canvas_pixel_get.c 					\
							canvas/ft_canvas_pixel_set.c 					\
							colors/ft_color_byte_h.c						\
							colors/ft_color_byte_l.c						\
							colors/ft_color_lighten.c						\
							colors/ft_color_darken.c						\
							colors/ft_color_toint.c							\
							filesystem/ft_close.c							\
							filesystem/ft_exists.c							\
							filesystem/ft_fopen.c							\
							filesystem/ft_fread.c							\
							filesystem/ft_open.c							\
							filesystem/ft_read.c							\
							filesystem/ft_write.c							\
							game/ft_game_move_axe.c							\
							game/ft_game_move_pos.c							\
							game/ft_game_move_run.c							\
							game/ft_game_move_use.c							\
							game/ft_game_swap_map.c							\
							hooker/ft_hook.c								\
							hooker/process/ft_hok_process_065.c				\
							hooker/process/ft_hok_process_068.c				\
							hooker/process/ft_hok_process_069.c				\
							hooker/process/ft_hok_process_077.c				\
							hooker/process/ft_hok_process_082.c				\
							hooker/process/ft_hok_process_083.c				\
							hooker/process/ft_hok_process_087.c				\
							hooker/process/ft_hok_process_256.c				\
							hooker/process/ft_hok_process_262.c				\
							hooker/process/ft_hok_process_263.c				\
							math/ft_hypot.c									\
							parser/ft_parse.c								\
							parser/utilities/ft_parse_abort.c				\
							parser/utilities/ft_parse_open.c				\
							parser/utilities/ft_parse_path.c				\
							parser/utilities/ft_parse_read.c				\
							parser/utilities/ft_parse_reap.c				\
							parser/utilities/ft_parse_skip.c				\
							parser/process/ft_prs_process_clr.c				\
							parser/process/ft_prs_process_map.c				\
							parser/process/ft_prs_process_tex.c				\
							renderer/ft_render.c							\
							renderer/render_00/ft_render_00.c				\
							renderer/render_00/process/ft_r00_process_cel.c	\
							renderer/render_00/process/ft_r00_process_flr.c	\
							renderer/render_01/ft_render_01.c				\
							renderer/render_01/process/ft_r01_process_col.c	\
							renderer/render_01/process/ft_r01_process_spr.c	\
							renderer/render_01/process/ft_main_raycasting.c	\
							renderer/render_01/process/ft_horizontal_checks.c\
							renderer/render_01/process/ft_vertical_checks.c	\
							renderer/render_02/ft_render_02.c				\
							renderer/render_02/process/ft_r02_process_map.c	\
							renderer/render_02/process/ft_r02_process_ptr.c	\
							resources/t_err/ft_err_add.c					\
							resources/t_err/ft_err_get.c					\
							resources/t_err/ft_err_use.c					\
							resources/t_key/ft_key_add.c					\
							resources/t_key/ft_key_get.c					\
							resources/t_spr/ft_spr_add.c					\
							resources/t_spr/ft_spr_get.c					\
							resources/t_src/ft_src_add.c					\
							resources/t_src/ft_src_get.c					\
							resources/t_src/ft_src_rgb.c					\
							resources/t_src/ft_src_use.c					\
							resources/t_tkn/ft_tkn_add.c					\
							resources/t_tkn/ft_tkn_get.c					\
							resources/t_tkn/ft_tkn_use.c					\
							structures/s_app.c								\
							structures/s_arg.c								\
							structures/s_cfg.c								\
							structures/s_drw.c								\
							structures/s_dst.c								\
							structures/s_ext.c								\
							structures/s_gme.c								\
							structures/s_hok.c								\
							structures/s_hud.c								\
							structures/s_err.c								\
							structures/s_key.c								\
							structures/s_lne.c								\
							structures/s_map.c								\
							structures/s_mlx.c								\
							structures/s_pos.c								\
							structures/s_prs.c								\
							structures/s_ptr.c								\
							structures/s_ray.c								\
							structures/s_rdr.c								\
							structures/s_rgb.c								\
							structures/s_spr.c								\
							structures/s_src.c								\
							structures/s_sts.c								\
							structures/s_tkn.c								\
							structures/s_win.c								\
							system/ft_exit.c								\
							textures/ft_texture_pixel_get.c					\
							updater/ft_update.c								\
							updater/process/ft_upd_process_hok.c			\
							updater/process/ft_upd_process_mlx.c			\
							updater/process/ft_upd_process_ptr.c			\
							updater/process/ft_upd_process_src.c			\
							updater/process/ft_upd_process_win.c			\
							window/ft_window_close.c						\
							window/ft_window_open.c							\
							)

#///// MAKEFILE : CONFIGURATION ///////////////////////////////////////////////#

# > REPORTS <<<<<<<<<<<<<<

REPORT_COMMON_TASK		:=	yes
REPORT_COMPILATION		:=	yes
REPORT_COMPILATION_LOGS	:=	no
REPORT_COMPILE_COUNTER	:=	yes
REPORT_ERRORS			:=	yes
REPORT_MAKE_CALL		:=	yes
REPORT_PRIMARY_TASK		:=	yes
REPORT_TIMESTAMPS		:=	no
REPORT_WARNINGS			:=	yes

# > MESSAGES SYMBOLS <<<<<

MSG_SYMBOL_FAILURE		:=	X
MSG_SYMBOL_REPORTS		:=	i
MSG_SYMBOL_SUCCESS		:=	✓
MSG_SYMBOL_WARNING		:=	!
MSG_SYMBOL_WORKING		:=	>

# > MESSAGES COLORS <<<<<<

MSG_BCOLOR_FAILURE		:=	\001\e[1;31m\002
MSG_BCOLOR_LOGGING		:=	\001\e[1;37m\002
MSG_BCOLOR_PRIMARY		:=	\001\e[1;36m\002
MSG_BCOLOR_REPORTS		:=	\001\e[1;35m\002
MSG_BCOLOR_SUCCESS		:=	\001\e[1;32m\002
MSG_BCOLOR_WARNING		:=	\001\e[1;33m\002
MSG_NCOLOR_FAILURE		:=	\001\e[0;31m\002
MSG_NCOLOR_LOGGING		:=	\001\e[0;37m\002
MSG_NCOLOR_PRIMARY		:=	\001\e[0;36m\002
MSG_NCOLOR_REPORTS		:=	\001\e[0;35m\002
MSG_NCOLOR_SUCCESS		:=	\001\e[0;32m\002
MSG_NCOLOR_WARNING		:=	\001\e[0;33m\002

# > TERMINAL <<<<<<<<<<<<<

TERM_CONTROL_CLEAR		:=	\001\e[1;1H\e[2J\002
TERM_CONTROL_RESET		:=	\001\e[0m\002

# > VARIABLES <<<<<<<<<<<<

V_ARGUMENTS				:=	$(MAKECMDGOALS)
V_COUNTER				:=	1
V_DISPLAY_NAME			:=	$(shell printf "[%-16s]" "$(PROJECT_NAME)")
V_INCLUDE_ARCHIVES		:=	$(PROJECT_ARCHIVES)
V_INCLUDE_HEADERS		:=	$(addprefix -I, $(PROJECT_HEADERS))
V_INCLUDES_LIBRARIES	:=	$(addprefix -L, $(PROJECT_LIBRARIES))
V_OBJECTS				:=	$(PROJECT_SOURCES:%$(EXTENSION_SOURCE)=%$(EXTENSION_OBJECT))
V_OBJECTS_TOTAL			:=	$(words $(V_OBJECTS))
V_OS					:=	$(shell uname)

ifeq ($(filter-out $@,$(V_ARGUMENTS)), debug)
COMPILER_PROGRAM_FLAGS	:=	$(addprefix $(COMPILER_PROGRAM_DEBUG) , $(COMPILER_PROGRAM_FLAGS))
endif

# > OBJECTS <<<<<<<<<<<<<<

O_COUNTER				=	$(shell printf "%02d/%02d" "$(V_COUNTER)" "$(V_OBJECTS_TOTAL)")
O_CURRENT_TIME			=	$(shell date +"%H:%M:%S")

#///// MAKEFILE : COMMANDS ////////////////////////////////////////////////////#

$(PROJECT_NAME)			:	$(V_OBJECTS)
							@for dependency in $(PROJECT_DEPENDENCIES) ; do\
								if [ $(REPORT_MAKE_CALL) = "yes" ]; then\
									printf "$(MSG_BCOLOR_REPORTS)[ $(MSG_SYMBOL_REPORTS) ]";\
									printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
									if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
										printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
									fi;\
									printf "$(MSG_NCOLOR_LOGGING) @make \"$${dependency}\"...\n";\
									printf "$(TERM_CONTROL_RESET)";\
								fi;\
								if [ -d $${dependency}/ ]; then\
									if [ -f $${dependency}/Makefile ]; then\
										$(MAKE) -C $${dependency} --no-print-directory ;\
									else\
										if [ $(REPORT_ERRORS) = "yes" ]; then\
											printf "$(MSG_BCOLOR_FAILURE)[ $(MSG_SYMBOL_FAILURE) ]";\
											printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
											if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
												printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
											fi;\
											printf "$(MSG_BCOLOR_FAILURE) Dependency \"$${dependency}\" does not contain Makefile !\n";\
											printf "$(TERM_CONTROL_RESET)";\
										fi;\
										exit 1;\
									fi;\
								else\
									if [ $(REPORT_ERRORS) = "yes" ]; then\
										printf "$(MSG_BCOLOR_FAILURE)[ $(MSG_SYMBOL_FAILURE) ]";\
										printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
										if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
											printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
										fi;\
										printf "$(MSG_BCOLOR_FAILURE) Directory \"$${dependency}\" does not exists !\n";\
										printf "$(TERM_CONTROL_RESET)";\
									fi;\
									exit 1;\
								fi;\
							done
							@for library in $(PROJECT_LIBRARIES) ; do\
								if [ ! -e $${library} ]; then\
									if [ $(REPORT_ERRORS) = "yes" ]; then\
										printf "$(MSG_BCOLOR_FAILURE)[ $(MSG_SYMBOL_FAILURE) ]";\
										printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
										if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
											printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
										fi;\
										printf "$(MSG_BCOLOR_FAILURE) Library \"$${library}\" does not exists !\n";\
										printf "$(TERM_CONTROL_RESET)";\
									fi;\
									exit 1;\
								fi;\
							done
							@cmake -B libraries/MLX42/build -S libraries/MLX42
							@cmake --build libraries/MLX42/build -j$(nproc)
							@for archive in $(PROJECT_ARCHIVES) ; do\
								if [ ! -e $${archive} ]; then\
									if [ $(REPORT_ERRORS) = "yes" ]; then\
										printf "$(MSG_BCOLOR_FAILURE)[ $(MSG_SYMBOL_FAILURE) ]";\
										printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
										if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
											printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
										fi;\
										printf "$(MSG_BCOLOR_FAILURE) Archive \"$${archive}\" does not exists !\n";\
										printf "$(TERM_CONTROL_RESET)";\
									fi;\
									exit 1;\
								fi;\
							done
							@if [ $(REPORT_COMMON_TASK) = "yes" ]; then\
								printf "$(MSG_BCOLOR_REPORTS)[ $(MSG_SYMBOL_REPORTS) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								printf "$(MSG_NCOLOR_LOGGING) Creating program...\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi
							@$(COMPILER_PROGRAM) $(COMPILER_PROGRAM_FLAGS) $(PROJECT_NAME) $(V_OBJECTS) $(V_INCLUDES_LIBRARIES) $(V_INCLUDE_ARCHIVES) $(COMPILER_PROGRAM_OTHER)
							@chmod 755 $(PROJECT_NAME)
							@if [ $(REPORT_PRIMARY_TASK) = "yes" ]; then\
								printf "$(MSG_BCOLOR_SUCCESS)[ $(MSG_SYMBOL_SUCCESS) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								printf "$(MSG_BCOLOR_SUCCESS) Program successfuly created !\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi

%$(EXTENSION_OBJECT)	:	%$(EXTENSION_SOURCE)
							@if [ $(REPORT_COMPILATION_LOGS) = "yes" ]; then\
								printf "$(MSG_BCOLOR_REPORTS)[ $(MSG_SYMBOL_REPORTS) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								if [ $(REPORT_COMPILE_COUNTER) = "yes" ]; then\
									printf "$(MSG_BCOLOR_LOGGING) $(O_COUNTER) >";\
								fi;\
								printf "$(MSG_NCOLOR_LOGGING) Compiling...    <";\
								printf "$(MSG_NCOLOR_LOGGING) $<\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi
							@$(COMPILER_OBJECTS) $(COMPILER_OBJECTS_FLAGS) $(V_INCLUDE_HEADERS) -c $< -o $@
							@if [ $(REPORT_COMPILATION) = "yes" ]; then\
								printf "$(MSG_BCOLOR_PRIMARY)[ $(MSG_SYMBOL_WORKING) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								if [ $(REPORT_COMPILE_COUNTER) = "yes" ]; then\
									printf "$(MSG_BCOLOR_PRIMARY) $(O_COUNTER) >";\
								fi;\
								printf "$(MSG_BCOLOR_PRIMARY) File compiled ! >";\
								printf "$(MSG_NCOLOR_LOGGING) $@\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi
							$(eval V_COUNTER=$(shell echo $$(($(V_COUNTER)+1))))

all						:	$(PROJECT_NAME)

clean					:	lclean
							@if [ $(REPORT_COMMON_TASK) = "yes" ]; then\
								printf "$(MSG_BCOLOR_REPORTS)[ $(MSG_SYMBOL_REPORTS) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								printf "$(MSG_NCOLOR_LOGGING) Deleting objects...\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi
							@rm -f $(V_OBJECTS);
							@if [ $(REPORT_PRIMARY_TASK) = "yes" ]; then\
								printf "$(MSG_BCOLOR_SUCCESS)[ $(MSG_SYMBOL_SUCCESS) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								printf "$(MSG_BCOLOR_SUCCESS) Objects deleted successfully !\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi

debug					:	re
							@if [ $(REPORT_WARNINGS) = "yes" ]; then\
								printf "$(MSG_BCOLOR_WARNING)[ $(MSG_SYMBOL_WARNING) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								printf "$(MSG_BCOLOR_WARNING) Program compiled in debugging mode.\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi


lclean					:	
							@for dependency in $(PROJECT_DEPENDENCIES); do\
								if [ -d $${dependency} ] && [ -f $${dependency}/Makefile ]; then\
									$(MAKE) fclean -C $${dependency} --no-print-directory ;\
								fi;\
							done

fclean					:	clean lclean
							@rm -rf $(PROJECT_NAME) libraries/MLX42/build;
							@if [ $(REPORT_PRIMARY_TASK) = "yes" ]; then\
								printf "$(MSG_BCOLOR_SUCCESS)[ $(MSG_SYMBOL_SUCCESS) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								printf "$(MSG_BCOLOR_SUCCESS) Program deleted successfully !\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi

re						:	fclean all

.PHONY					:	all clean debug lclean fclean re
