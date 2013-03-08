#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "word_manage_p.h"

/*
 * 将index后面的元素往后移动一位  （包括index本身）
 */
static void shift_array(int index){
    int src;
    for (src = num_of_word - 1; src > index; src--)
    {
	word_array[src + 1] = word_array[src];
    }

    num_of_word++;
}

/*
 * 复制字符串
 */
static char *my_strdup(char *src)     //  深度复制
{
    char *dest;

    dest = malloc(sizeof(char) * (strlen(src) + 1));
    strcpy(dest, src);

    return dest;
}

/*
 *  追加单词
 */
void add_word(char *word)
{
    int i;
    int result;

    for (i = 0; i < num_of_word; i++){
	result = strcmp(word_array[i].name, word);
	if (result >= 0)
	    break;
    }

    if (num_of_word != 0 && result == 0)  // 发现相同单词
	word_array[i].count++;
    else                                 // i 处元素比word 大 则右移
    {
	shift_array(i);
	word_array[i].name = my_strdup(word);
	word_array[i].count = 1;
    }
}
