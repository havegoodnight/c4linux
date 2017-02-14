#!/bin/bash

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
echo '' >> ./README.md
echo '```' >> ./README.md

touch ./foo.c
echo '#include "foo.h"' >> ./foo.c
echo '' >> ./foo.c
echo 'int main(int argc, char *argv[]){' >> ./foo.c
echo '' >> ./foo.c
echo '	return 0;' >> ./foo.c
echo '}' >> ./foo.c

touch ./foo.h
echo '#ifndef __FOO_H__' >> ./foo.h
echo '#define __FOO_H__' >> ./foo.h
echo '' >> ./foo.h
echo '#include <stdio.h>' >> ./foo.h
echo '' >> ./foo.h
echo 'int main(int argc, char *argv[]);' >> ./foo.h
echo '' >> ./foo.h
echo '#endif' >> ./foo.h

touch ./Makefile
echo 'foo:foo.o' >> ./Makefile
echo '	gcc -o foo foo.o' >> ./Makefile
echo 'foo.o:foo.c' >> ./Makefile
echo '	gcc -c foo.c' >> ./Makefile
echo 'clean:' >> ./Makefile
echo '	rm ./foo.o' >> ./Makefile
echo '	rm ./foo' >> ./Makefile
