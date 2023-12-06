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
echo -e "${BOLD}CPP module 01 exo 04 (sed) Tester${END}"
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
rm -rf testfiles && mkdir testfiles && dir=testfiles/

echo -e "${YEL_BG}Arg error tests${END}"

echo -e "${BLU_BG}./sed_ifl${END}\t"
./sed_ifl
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl filename${END}\t"
./sed_ifl filename
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl filename s1${END}\t"
./sed_ifl filename s1
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl filename s1 s2 s3${END}\t"
./sed_ifl filename s1 s2 s3
echo "----------------------------------------------------------------"


echo -e "${YEL_BG}Filename error tests${END}"

echo -e "${BLU_BG}./sed_ifl filename (unexisting) s1 s2${END}\t"
rm -rf filename
./sed_ifl filename s1 s2
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl filename (chmod u-r) s1 s2${END}\t"
echo hello > filename ; chmod u-r filename
./sed_ifl filename s1 s2
rm -f filename
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl filename s1 s2 (outfile no w right)${END}\t"
echo hello > filename ; touch filename.replace ; chmod u-w filename.replace
./sed_ifl filename s1 s2
echo "----------------------------------------------------------------"


echo -e "${YEL_BG}Normal tests${END}"

echo -e "${BLU_BG}./sed_ifl file1 s1 s2${END}\t"
echo s1 > ${dir}file1
./sed_ifl ${dir}file1 s1 s2
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl file2 (no linefeed) s1 s2${END}\t"
echo -n s1 > ${dir}file2
./sed_ifl ${dir}file2 s1 s2
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl file3 s1 s2${END}\t"
echo s2s1s2 > ${dir}file3
./sed_ifl ${dir}file3 s1 s2
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl Makefile '\$' one_million_dollar ${END}\t"
./sed_ifl Makefile \$ one_million_dollar
echo "----------------------------------------------------------------"


echo -e "${YEL_BG}Special tests${END}"

echo -e "${BLU_BG}./sed_ifl emptyfile yo yi${END}\t"
touch ${dir}emptyfile
./sed_ifl ${dir}emptyfile yo yi
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl empty_everything \"\" \"\"${END}\t"
touch ${dir}empty_everything
./sed_ifl ${dir}empty_everything yo yi
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl f yo yi (outfile to be trunc)${END}\t"
echo yoyoYOyi > ${dir}f ; echo "this has to be truncated" > ${dir}f.replace
./sed_ifl ${dir}f yo yi
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl file4 s1 s2${END}\t"
echo -e "s2s\n1s2" > ${dir}file4
./sed_ifl ${dir}file4 s1 s2
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl file5 \"\" s2${END}\t"
echo -e "   \n\n salut s2, ca va?" > ${dir}file5
./sed_ifl ${dir}file5 \"\" s2
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl file6 salut \"\"${END}\t"
echo -e "   \n\n salut salut sal ut SALUT sAlUt, ca va?" > ${dir}file6
./sed_ifl ${dir}file6 salut ""
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl largefile Gutenberg Galileo${END}\t"
curl -s "https://www.gutenberg.org/cache/epub/41815/pg41815-images.html" >${dir}largefile
oc_nb=$(cat ${dir}largefile | grep Gutenberg -c)
if [[ ${oc_nb} -lt 90 ]]; then
	curl -s "https://www.gutenberg.org/cache/epub/41815/pg41815-images.html" >${dir}largefile
	oc_nb=$(cat ${dir}largefile | grep Gutenberg -c)
	[[ $oc_nb -lt 90 ]] && { echo "Pb curling Gutenberg file ; tester exiting"; exit 3; }
fi
echo -e "${ITA}Note that Gutenberg has ${oc_nb} occurences in largefile${END}"
./sed_ifl ${dir}largefile Gutenberg Galileo
oc_nb_replace=$(cat ${dir}largefile.replace | grep Galileo -c)
echo -e "${ITA}Found ${oc_nb_replace} occurences of Galileo in largefile.replace${END}"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}./sed_ifl largefile.replace Galileo \"Kany West ft. Sunday Service\"${END}\t"
echo -e "${ITA}It should be ${oc_nb} occurences in largefile.replace.replace${END}"
./sed_ifl ${dir}largefile.replace Galileo "Kany West ft. Sunday Service"
oc_nb_replace=$(cat ${dir}largefile.replace.replace | grep "Kany West ft. Sunday Service" -c)
echo -e "${ITA}Found ${oc_nb_replace} occurences of \"Kany West ft. Sunday Service\" in largefile.replace${END}"
echo "----------------------------------------------------------------"


# ------------------------------------------------------------------------------
#				-----		OUTRO		-----
# ------------------------------------------------------------------------------
make fclean &>/dev/null
rm -f filename filename.replace