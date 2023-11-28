##		SOURCE FILES	###
BUILD_DIR	=	./build
SRC_DIR 	= 	./

HEADERS		=	
SRCS_NAME 	=	truc.cpp

SRCS		= 	$(addprefix ${SRC_DIR}, ${SRCS_NAME})
OBJS		=	${SRCS:%.cpp=$(BUILD_DIR)/%.o}

###		DEFINITIONS		###
NAME		=	truc
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

###		RULES		###
$(BUILD_DIR)/%.o: %.cpp ${HEADERS}
			@mkdir -p $(dir $@)
			@echo "\033[32m\c"
			${CC} ${CFLAGS} -c $< -o $@
			@echo "\033[0m\c"

all:		${NAME}

${NAME}:	${OBJS}
			@echo "\033[32m\c"
			${CC} -o ${NAME} ${OBJS}
			@echo "Link complete for exec --> \033[4;36;1m${NAME}\033[0m"

clean:
			@rm -rf ${BUILD_DIR}
			@echo "\033[32m${NAME} obj cleaned\033[0m"

fclean:		clean
			@rm -rf ${NAME}
			@echo "\033[32m${NAME} fcleaned\033[0m"

re:			fclean all

.PHONY:		all clean re
