#! /bin/bash

#turn bool_ to 0 to skip specific tests
bool_makefile=1

# const
ITA="\033[3m"
BOLD="\033[1m"
UNDERL="\033[4m"
GREEN="\033[32m"
RED="\033[31m"
YEL="\033[33m"
END="\033[m"
BLU_BG="\033[44m"
YEL_BG="\033[43;1m"
RED_BG="\033[41;1m"

# print intro
echo "------------------------------------"
echo "------------------------------------"
echo -e "${BOLD}CPP module 01 ex06 harlfilter Tester${END}"
echo -e "Started at $(date +%R) - $(date +"%d %B %Y")"
echo -e "by $USER on $(uname) os"
echo -e "made by bguillau (@bastienkody)"
echo "------------------------------------"
echo "------------------------------------"

# ------------------------------------------------------------------------------
#				-----		MAKEFILE		-----
# ------------------------------------------------------------------------------
if [[ $bool_makefile == 1 ]] ; then 
echo -e "${YEL_BG}Makefile${END}"

#---------------
# makefile relink
echo -ne "${BLU_BG}Test Makefile${END}\t\t"
make re 1>/dev/null 2> stderrmake.txt
make > stdoutmakebis.txt 2>&1
[[ -s stderrmake.txt ]] && echo -ne "${RED}make wrote on std err${END}" || echo -ne "${GREEN}no make error${END}" 
echo -n " -- "
cat stdoutmakebis.txt | egrep -viq "(nothin|already|date)" && echo -e "${RED}makefile relink?${END}" || echo -e "${GREEN}no relink${END}"
rm -rf stderrmake.txt stdoutmakebis.txt

#-------------------------
# makefile : flags and rule
echo -ne "${BLU_BG}Makefile flags${END}\t\t"
grep -sq -- "-Wall" Makefile && echo -ne "${GREEN}OK (-Wall)${END}" || echo -ne "${RED}-Wall not found${END}"
echo -n " -- "
grep -sq -- "-Wextra" Makefile && echo -ne "${GREEN}OK (-Wextra)${END}" || echo -ne "${RED}-Wextra not found${END}"
echo -n " -- "
grep -sq -- "-Werror" Makefile && echo -ne "${GREEN}OK (-Werror)${END}" || echo -ne "${RED}-Werror not found${END}"
echo -n " -- "
grep -sq -- "-std=c++98" Makefile && echo -ne "${GREEN}OK (std c++98)${END}" || echo -ne "${RED}Flag -std=c++98 not found${END}"
echo ""


else make >/dev/null ; fi

# ------------------------------------------------------------------------------
# 					------- EX 00 -------
# ------------------------------------------------------------------------------
echo -e "${YEL_BG}Arg error tests${END}"

echo -e "${BLU_BG}./harlFilter ${END}\t"
./harlFilter
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./harlFilter ERROR WARNING ${END}\t"
./harlFilter ERROR WARNING
echo "----------------------------------------------------------------"

echo -e "${YEL_BG}Bad level id tests${END}"

echo -e "${BLU_BG}./harlFilter \"BAD LEVEL\"${END}\t"
./harlFilter "BAD LEVEL"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./harlFilter \"WARNINGERROR\"${END}\t"
./harlFilter "WARNINGERROR"
echo "----------------------------------------------------------------"

echo -e "${YEL_BG}Normal tests${END}"

echo -e "${BLU_BG}./harlFilter DEBUG${END}\t"
./harlFilter DEBUG
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./harlFilter INFO${END}\t"
./harlFilter INFO
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./harlFilter WARNING${END}\t"
./harlFilter WARNING
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./harlFilter ERROR${END}\t"
./harlFilter ERROR
echo "----------------------------------------------------------------"

# ------------------------------------------------------------------------------
#				-----		OUTRO		-----
# ------------------------------------------------------------------------------
make fclean &>/dev/null