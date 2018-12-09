/**
 * mnwbf.c -- передвигает курсор в начало следующего слова, если это возможно.
 *
 * Copyright (c) 2018, Dmitriy Kustov <kustov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "common.h"
#include "text/text.h"

static void mnwbf_line(int index, char *contents, int cursor, void *data);


void mnwbf(text txt)
{
    
    process_forward(txt, mnwbf_line, NULL);
}

static void mnwbf_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(data);
    
    
    if (cursor > 0) {
	int length = strlen(contents) - 1;
	while(cursor < length && !isspace(contents[cursor])){
	    cursor++;
	}
	cursor++;
	/* Переставляем курсор на новую позицию */
	mwcrsr(data, index + 1, cursor + 1);
	
    }
}
