##		SOURCE FILES	###
HEADERS		=	Bureaucrat.hpp
BUILD_DIR	=	./build
SRC_DIR 	= 	./
SUB_DIR		=	sub_form_classes
vpath %.cpp ${SRCS_DIR} ${SUB_DIR}

SRCS		=	Bureaucrat.cpp AForm.cpp main.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				ShrubberyCreationForm.cpp

OBJS		=	${SRCS:%.cpp=$(BUILD_DIR)/%.o}

###		DEFINITIONS		###
NAME		=	form_ex02
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

###		RULES		###
$(BUILD_DIR)/%.o: %.cpp ${HEADERS}
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
