/**
 * rp.c -- удаляет строку перед текущей.
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

static void rp_line(int index, char *contents, int cursor, void *data);

static int mark = 1;

void rp(text txt)
{
    mark = 1;
    process_forward(txt, rp_line, txt);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void rp_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    if (cursor > 0 && mark) {

	delete_line(data, index);
	
	mwcrsr(data, index, cursor+1);

	mark = 0;
    }
}
    
