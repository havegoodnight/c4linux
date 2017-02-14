#!/bin/bash

if [ "$#" != 1 ]; then
	echo -e "Usage : \r\n\t$0 \"Description\""
	exit 1
fi

get_max_number(){
	return `ls | sort -n | tail -n 1`
}

get_max_number
max_number=$?

echo "当前最大文件夹序号为 : $max_number"
((new_folder_name=$max_number+1))
echo "新文件夹名 : " $new_folder_name
mkdir $new_folder_name
get_max_number
max_number=$?
echo "新文件夹创建成功 , 当前最大序号为 : " $max_number
cd $max_number

touch ./README.md
echo '目标' >> ./README.md
echo '```' >> ./README.md
echo "$1" >> ./README.md
echo '```' >> ./README.md

touch ./main.c
echo '#include <stdio.h>' >> ./foo.c
echo '' >> ./foo.c
echo 'int main(int argc, char *argv[]){' >> ./foo.c
echo '' >> ./foo.c
echo '	return 0;' >> ./foo.c
echo '}' >> ./foo.c

touch ./Makefile
echo 'main:main.o' >> ./Makefile
echo '	gcc -o main main.o' >> ./Makefile
echo 'main.o:main.c' >> ./Makefile
echo '	gcc -c main.c' >> ./Makefile
echo 'clean:' >> ./Makefile
echo '	rm ./main.o' >> ./Makefile
echo '	rm ./main' >> ./Makefile
