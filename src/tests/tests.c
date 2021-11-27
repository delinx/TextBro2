#include "../files.h"

void main(int argc, char *argv[])
{

    read_from_file_leak_test();

}

void read_from_file_leak_test()
{
    const char* file_buffer = read_from_file("/home/del/projects/TextBro2.0/Samples/4.txt");
    free(file_buffer);
}