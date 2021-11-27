#include "files.h"

char *read_from_file(const char *file)
{
    const char* text = LoadFileText(file);
    const char* _tmp = malloc(sizeof(char)*strlen(text)+1);
    strcpy(_tmp,text);
    UnloadFileText(text);
    return _tmp;
}

