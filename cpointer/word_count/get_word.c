#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "get_word.h"

int get_word(char *buf, int size, FILE *stream)
{
    int len;
    int ch;
    /*
     *  getc(stream)  此处的stream是文件指针；函数功能是从文件指针指向的文件读入一个字符，并把它     *  作为函数返回值给字符型变量ch。
     *  isalnum(ch) 判断字符变量c是否为字母或数字
     */
    while ((ch = getc(stream)) != EOF && !isalnum(ch))
	;
    if (ch == EOF)
	return EOF;
    /* 此时 ch中保存了单词的初始字符*/
    len = 0;
    do {
	buf[len] = ch;
	len++;
	if (len >= size){
	    fprintf(stderr, "word too long \n");
	    exit(1);
	}
    } while ((ch = getc(stream)) != EOF && isalnum(ch));

    buf[len] = '\0';
    
    return len;
}
