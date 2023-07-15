#include <string.h>
namespace Myscope
{
    char *searchPat(const char *line, const char *pattern)
    {
        int len = strlen(pattern);
        for (; *line != '\0'; line++)
        {
            if(strncmp(line , pattern,len) == 0)
                return (char *)line;
        }
        return NULL;
    }
}