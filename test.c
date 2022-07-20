#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void find_last_tag(const char *buffer)
{
    char *ptr = strchr(buffer, '<');

    if(!ptr)
    {
        return;
    }

    while(ptr)
    {
        char *tmp = strchr(ptr+1, '<');

        if(tmp && *(tmp + 1) != '/')
        {
            ptr = tmp;
        }
        else
        {
            break;
        }
    }

    char *closing_tag = strstr(ptr+1, "</");

    if(closing_tag)
    {
        char *end = strchr(closing_tag+1, '>');

        if(end)
        {
            char *tmp = ptr;

            while(tmp && tmp != end+1)
            {
                fputc(*tmp, stdout);
                tmp++;
            }
        }
    }


}

int main()
{
    const char *buffer = "<body>\n  <p>Hello</p>\n</body>";

    find_last_tag(buffer);

    return 0;
}