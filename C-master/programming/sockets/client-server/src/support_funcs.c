/***************************************************
 * Name    : support_funcs.c
 * 
 * DESC    : support functions for server app
 * 
 * Author  : pavanbobba206@gmail.com
*****************************************************/
#include "comm_header.h"

static DIR *dir = NULL;

int get_pwd(char * buf)
{
    int ret = SUCCESS;
   
    if(!getcwd(buf, BUF_SIZE))
	{	
		perror("getcwd:");
        ret = ERROR;
	}
    return ret;
}

int list_contents(char * buf)
{
    int ret = SUCCESS, pos;
    struct dirent * content = NULL;
	struct stat details;

    memset(&details, 0, sizeof(details));
    memset(&content, 0, sizeof(content));

    if(!dir)
    {
        dir = opendir(".");
	    if(!dir)
	    {
		    perror("opendir:");
		    ret = ERROR;
	    }
    }
    if(!ret)
    {
        pos = 0;
        rewinddir(dir);
        while((content = readdir(dir)) != NULL)
		{
		    if(stat(content->d_name, &details) != ERROR)
			{
                if((pos + (content->d_reclen)) >= BUF_SIZE)
                {
                    printf("buffer overflown.");
                    ret = ERROR;
                    break;
                }
			    pos += snprintf(&buf[pos], (strlen(content->d_name) + 1), "%s", content->d_name);
				buf[pos++] = ' ';
				if(content->d_type == DT_DIR)
				{
				    pos += snprintf(&buf[pos], 4, "dir");
				}
				else
				{
				    pos += snprintf(&buf[pos], 5, "file");
				}
				buf[pos++] = ' ';
				pos += strftime(&buf[pos], 50, "%H:%M:%S %Y-%m-%d", localtime((const time_t *)&details.st_atim));
				buf[pos++] = '\n';
			}
			else
			{
			    perror("stat:");
                ret = ERROR;
				break;
			}
		}
    }
   
    return ret;
}

int change_dir(char * name, char * buf)
{
    int ret = SUCCESS;
    
    if(!chdir(name))
    {
		snprintf(buf, 8, "changed");
        //resetting dir pointer to help list_contents() function above
        if(dir)
        {
            if(closedir(dir))
            {
                perror("closedir:");
                ret = ERROR;
            }
            dir = NULL;
        }
    }
	else
	{
	    perror("chdir:");
		ret = ERROR;
	}
    return ret;
}

void clean_up(char * buf)
{
    snprintf(buf, 17, "please leave...");
	if(dir)
    {
        if(closedir(dir))
            perror("closedir:");
        dir = NULL;
    }
}

