#ifndef WORD_MANAGE_P_H_INCLUDE
#define WORD_MANAGE_P_H_INCLUDE
#include <stdio.h>

typedef struct{
    char *name;
    int count;
}Word;

#define WORD_NUM_MAX (10000)

extern Word word_array[];
extern int num_of_word;

void word_initialize(void); //初始化
void add_word(char *word);  //单词的追加
void dump_word(FILE *fp);   //输出单词的出现频率
void word_finalize(void);   //结束处理
int get_word_count(char *word); // 返回某单词出现的次数

#endif
