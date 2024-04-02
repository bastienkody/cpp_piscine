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

# exec name
p=scalar

# print intro
echo "------------------------------------"
echo "------------------------------------"
echo -e "${BOLD}CPP module 06 exo 00 (scalar) ${END}"
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
# 					------- ACCEPTED CHAR -------
# ------------------------------------------------------------------------------

echo -e "${YEL_BG}Accepted char${END}"

echo -e "${BLU_BG}./${p} \"a\"${END}\t"
./${p} "a"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"A\"${END}\t"
./${p} "A"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \" \" (a space)${END}\t"
./${p} " "
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"*\"${END}\t"
./${p} "*"
echo "----------------------------------------------------------------"

# ------------------------------------------------------------------------------
# 					------- BAD CHAR -------
# ------------------------------------------------------------------------------

echo -e "${YEL_BG}Bad char${END}"

echo -e "${BLU_BG}./${p} \"aa\"${END}\t"
./${p} "aa"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"AA\"${END}\t"
./${p} "AA"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \" * \" (space - star - space)${END}\t"
./${p} " * "
echo "----------------------------------------------------------------"

# ------------------------------------------------------------------------------
# 					------- ACCEPTED INT -------
# ------------------------------------------------------------------------------

echo -e "${YEL_BG}Accepted int${END}"

echo -e "${BLU_BG}./${p} \"0\"${END}\t"
./${p} "0"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"1\"${END}\t"
./${p} "1"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"-1\"${END}\t"
./${p} "-1"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"2147483647\"${END}\t"
./${p} "2147483647"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"-2147483648\"${END}\t"
./${p} "-2147483648"
echo "----------------------------------------------------------------"

# ------------------------------------------------------------------------------
# 					------- BAD INT -------
# ------------------------------------------------------------------------------

echo -e "${YEL_BG}Bad int${END}"

echo -e "${BLU_BG}./${p} \"\" (empty string)${END}\t"
./${p} ""
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"2147483648\"${END}\t"
./${p} "2147483648"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"-2147483649\"${END}\t"
./${p} "-2147483649"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"++1\"${END}\t"
./${p} "++1"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"--1\"${END}\t"
./${p} "--1"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"1A\"${END}\t"
./${p} "1A"
echo "----------------------------------------------------------------"

# ------------------------------------------------------------------------------
# 					------- ACCEPTED FLOAT -------
# ------------------------------------------------------------------------------

echo -e "${YEL_BG}Accepted float${END}"

echo -e "${BLU_BG}./${p} \"1.f\"${END}\t"
./${p} "1.f"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \".1f\"${END}\t"
./${p} ".1f"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"0.1f\"${END}\t"
./${p} "0.1f"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"0000.001f\"${END}\t"
./${p} "0000.001f"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"+inff\"${END}\t"
./${p} "+inff"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"-inff\"${END}\t"
./${p} "-inff"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"nanf\"${END}\t"
./${p} "nanf"
echo "----------------------------------------------------------------"

# ------------------------------------------------------------------------------
# 					------- BAD FLOAT -------
# ------------------------------------------------------------------------------

echo -e "${YEL_BG}Bad float${END}"

echo -e "${BLU_BG}./${p} \".f\"${END}\t"
./${p} ".f"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"..f\"${END}\t"
./${p} "..f"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"1..0f\"${END}\t"
./${p} "1..0f"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"1ff\"${END}\t"
./${p} "1ff"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"f1f\"${END}\t"
./${p} "f1f"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"10f\"${END}\t"
./${p} "10f"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"inff\"${END}\t"
./${p} "inff"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"+nanf\"${END}\t"
./${p} "+nanf"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"-nanf\"${END}\t"
./${p} "-nanf"
echo "----------------------------------------------------------------"

# ------------------------------------------------------------------------------
# 					------- ACCEPTED DOUBLE -------
# ------------------------------------------------------------------------------

echo -e "${YEL_BG}Accepted double${END}"

echo -e "${BLU_BG}./${p} \"1.\"${END}\t"
./${p} "1."
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \".1\"${END}\t"
./${p} ".1"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"0.1\"${END}\t"
./${p} "0.1"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"0000.001\"${END}\t"
./${p} "0000.001"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"+inf\"${END}\t"
./${p} "+inf"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"-inf\"${END}\t"
./${p} "-inf"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"nan\"${END}\t"
./${p} "nan"
echo "----------------------------------------------------------------"

# ------------------------------------------------------------------------------
# 					------- BAD DOUBLE -------
# ------------------------------------------------------------------------------

echo -e "${YEL_BG}Bad double${END}"

echo -e "${BLU_BG}./${p} \".0.\"${END}\t"
./${p} ".0."
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"..10\"${END}\t"
./${p} "..10"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"1..0\"${END}\t"
./${p} "1..0"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \".\"${END}\t"
./${p} "."
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"...\"${END}\t"
./${p} "..."
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"inf\"${END}\t"
./${p} "inf"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"+nan\"${END}\t"
./${p} "+nan"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./${p} \"-nan\"${END}\t"
./${p} "-nan"
echo "----------------------------------------------------------------"


# ------------------------------------------------------------------------------
#				-----		OUTRO		-----
# ------------------------------------------------------------------------------
make fclean &>/dev/null
