##		SOURCE FILES	###
BUILD_DIR	=	./build
SRC_DIR 	= 	./
vpath %.cpp ${SRCS_NAME}

SRCS		=	main.cpp
OBJS		=	${SRCS:%.cpp=$(BUILD_DIR)/%.o}

###		DEFINITIONS		###
NAME		=	dateTest
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

###		RULES		###
$(BUILD_DIR)/%.o: %.cpp
			@mkdir -p $(dir $@)
			@echo "\033[32m\c"
			${CXX} ${CXXFLAGS} -c $< -o $@
			@echo "\033[0m\c"

all:		${NAME}

${NAME}:	${OBJS}
			@echo "\033[32m\c"
			${CXX} -o ${NAME} ${OBJS}
			@echo "Link complete for exec --> \033[4;36;1m${NAME}\033[0m"

clean:
			@rm -rf ${BUILD_DIR}
			@echo "\033[32m${NAME} obj cleaned\033[0m"

fclean:		clean
			@rm -rf ${NAME}
			@echo "\033[32m${NAME} fcleaned\033[0m"

re:			fclean all

.PHONY:		all clean fclean re
