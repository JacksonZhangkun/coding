#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "read_line.h"

#define ALLOC_SIZE (256)

static char *st_line_buffer = NULL;      // 行的缓冲

static int st_current_buffer_size = 0;   // 在st_line_buffer 前方分配的内存区域大小

static int st_current_used_size = 0;     // 在st_line_buffer中现在被保存的字符大小

static ReadLineStatus
add_character(int ch)
{
    assert(st_current_buffer_size >= st_current_used_size);
    //assert宏的原型定义在<assert.h>中，其作用是如果它的条件返回错误，则终止程序执行

    if (st_current_buffer_size == st_current_used_size) 
	// 现有的缓冲区全部用完 需要再额外索取
    {
	char *temp;
	temp = realloc(st_line_buffer, (st_current_buffer_size + ALLOC_SIZE) * sizeof(char));
	if (temp == NULL)
	{
	    return READ_LINE_OUT_OF_MEMORY;
	}

	st_line_buffer = temp;
	st_current_buffer_size += ALLOC_SIZE;
    }

    st_line_buffer[st_current_used_size] = ch;
    st_current_used_size++;
    return READ_LINE_SUCCESS;
}

void free_buffer(void)
{
    free(st_line_buffer);
    st_line_buffer = NULL;
    st_current_buffer_size = 0;
    st_current_used_size = 0;
}

ReadLineStatus read_line(FILE *fp, char **line)
{
    int 	ch;
    ReadLineStatus status = READ_LINE_SUCCESS;

    st_current_used_size = 0;
    while ((ch = getc(fp)) != EOF)
    {
	if (ch == '\n'){
	    status = add_character('\0');
	    if (status != READ_LINE_SUCCESS)
		goto FUNC_END;
	    break;
	}

	status = add_character(ch);
        if (status != READ_LINE_SUCCESS)
	    goto FUNC_END;
    }
    if (ch == EOF){
	if (st_current_used_size > 0
		&& st_line_buffer[st_current_used_size] == '\0'){      // 如果最终行后面没有换行
	    status = add_character('\0');
	    if (status != READ_LINE_SUCCESS)
	    	goto FUNC_END;
	} else {
	    status = READ_LINE_EOF;   
	    goto FUNC_END;
	}
    }

    *line = malloc(sizeof(char) * st_current_used_size);
    if (*line == NULL)
    {
	status = READ_LINE_OUT_OF_MEMORY;
	goto FUNC_END;
    }
    strcpy(*line, st_line_buffer);

FUNC_END:
    if (status != READ_LINE_SUCCESS && status != READ_LINE_EOF)
	free_buffer();

    return status;

}
