#! /bin/bash

#turn bool_ to 0 to skip specific tests
bool_makefile=0

# const
ITA="\033[3m"
BOLD="\033[1m"
UNDERL="\033[4m"
GREEN="\033[32m"
RED="\033[31m"
YEL="\033[33m"
END="\033[m"
BLU_BG="\033[44m"
YEL_BG="\033[1m"
RED_BG="\033[41;1m"

# exec name
p=scalar

# print intro
echo "#########################################################################"
echo "BEGIN"
echo "#########################################################################"
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
# 					------- CHAR -------
# ------------------------------------------------------------------------------
echo -e "${YEL_BG}Accepted char${END}"
ok_char=('a' 'A' ' ' '*')
for arg in "${ok_char[@]}"; do
	echo -ne "${BLU_BG}./${p} \"${arg}\"${END}\t"
	./${p} "${arg}"
	echo "----------------------------------------------------------------"
done


echo -e "${YEL_BG}Bad char${END}"
bad_char=('aa' 'AA' ' * ')
for arg in "${bad_char[@]}"; do
	echo -ne "${BLU_BG}./${p} \"${arg}\"${END}\t"
	./${p} "${arg}"
	echo "----------------------------------------------------------------"
done

# ------------------------------------------------------------------------------
# 					------- INT -------
# ------------------------------------------------------------------------------

echo -e "${YEL_BG}Accepted int${END}"
ok_int=('0' '1' '-1' '   128' '2147483647' '-2147483648')
for arg in "${ok_int[@]}"; do
	echo -ne "${BLU_BG}./${p} \"${arg}\"${END}\t"
	./${p} "${arg}"
	echo "----------------------------------------------------------------"
done


echo -e "${YEL_BG}Bad int${END}"
bad_int=('' '++1' '--1' '1+1' '1A' '23 45' '2147483648' '-2147483649')
for arg in "${bad_int[@]}"; do
	echo -ne "${BLU_BG}./${p} \"${arg}\"${END}\t"
	./${p} "${arg}"
	echo "----------------------------------------------------------------"
done

# ------------------------------------------------------------------------------
# 					------- FLOAT -------
# ------------------------------------------------------------------------------

echo -e "${YEL_BG}Accepted float${END}"
ok_float=('1.f' '.1f' '0.f' '0000.001f' '-129.f' '  -128.f' '134217729.f' '2147483647.f' '2147483648.f' '-2147483648.f' '-2147483649.f' '+inff' '-inff' 'nanf')
for arg in "${ok_float[@]}"; do
	echo -ne "${BLU_BG}./${p} \"${arg}\"${END}\t"
	./${p} "${arg}"
	echo "----------------------------------------------------------------"
done

echo -e "${YEL_BG}Bad float${END}"
bad_float=('.f' '..f' '1..0f' '1ff' 'f1f' '10f' '1  0f' 'inff' '-nan')
for arg in "${bad_float[@]}"; do
	echo -ne "${BLU_BG}./${p} \"${arg}\"${END}\t"
	./${p} "${arg}"
	echo "----------------------------------------------------------------"
done

# ------------------------------------------------------------------------------
# 					------- ACCEPTED DOUBLE -------
# ------------------------------------------------------------------------------

echo -e "${YEL_BG}Accepted double${END}"
ok_double=('1.' '.1' '0.1' '0000.001' ' -129.' '134217729.' '2147483647.' '2147483648.' '-2147483648.' '-2147483649.' '+inf' '-inf' 'nan')
for arg in "${ok_double[@]}"; do
	echo -ne "${BLU_BG}./${p} \"${arg}\"${END}\t"
	./${p} "${arg}"
	echo "----------------------------------------------------------------"
done

echo -e "${YEL_BG}Bad double${END}"
bad_double=('.0.' '..10' '0..1' '1. 0' 'inf' '+nan')
for arg in "${bad_double[@]}"; do
	echo -ne "${BLU_BG}./${p} \"${arg}\"${END}\t"
	./${p} "${arg}"
	echo "----------------------------------------------------------------"
done

# ------------------------------------------------------------------------------
#				-----		OUTRO		-----
# ------------------------------------------------------------------------------
make fclean &>/dev/null


echo "#########################################################################"
echo "END"
echo "#########################################################################"