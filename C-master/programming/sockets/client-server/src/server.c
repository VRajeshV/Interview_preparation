/***************************************************
 * Name    : server.c
 * 
 * DESC    : server app
 * 
 * Author  : pavanbobba206@gmail.com
*****************************************************/
#include "comm_header.h"

int handler(int client_fd)
{
	char buf[BUF_SIZE], name[100];
	int pos;
	
	while(1)
	{
		memset(buf, '\0', sizeof(buf));
		if(read(client_fd, buf, sizeof(buf)) != ERROR)
		{
			if(!strncmp(buf, "pwd", 3))
			{
				memset(buf, '\0', sizeof(buf));
				if(get_pwd(buf))
					break;
			}
			else if(!strncmp(buf, "ls", 2))
			{
				memset(buf, '\0', sizeof(buf));
				if(list_contents(buf))
					break;
			}
			else if(!strncmp(buf, "cd ", 3))
			{
				pos = 3;
				memset(name, '\0', sizeof(name));
				while(buf[pos] != '\n')
				{
					name[pos - 3] = buf[pos++];
				}
				name[pos] = '\0';
				if(change_dir(name, buf))
					break;
			}
			else if(!strncmp(buf, "bye", 3))
			{
				memset(buf, '\0', sizeof(buf));
				clean_up(buf);
				if(write(client_fd, buf, (strlen(buf) + 1)) == ERROR)
				{
					perror("write:");
 				}
				break;
			}
			else
			{
				memset(buf, '\0', sizeof(buf));
				snprintf(buf, 15, "invalid input");
				continue;
			}
			if(write(client_fd, buf, (strlen(buf) + 1)) == ERROR)
			{
				perror("write:");
				break;
			}
		}
		else
		{
			perror("read:");
			break;
		}
	}
	if(close(client_fd))
		perror("close:");

	return 0;
}

int main()
{
	int serv_fd = 0, cli_fd, len;
	pid_t child_id;
	pthread_t tid = 0;
    struct sockaddr_in serv_addr, cli_addr;
	serv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(serv_fd != ERROR)
	{
		bzero(&serv_addr, sizeof(serv_addr));

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(PORT);
		serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

		if(!bind(serv_fd, (const struct sockaddr *)&serv_addr, sizeof(serv_addr)))
		{
			if(!listen(serv_fd, 10))
			{
				bzero(&cli_addr, sizeof(cli_addr));
				len = sizeof(cli_addr);
				while(1)
				{
					cli_fd = accept(serv_fd, (struct sockaddr *)&cli_addr, (socklen_t *)&len);
					if(cli_fd != ERROR)
					{
						if((child_id = fork()) != ERROR)
						{
							if(!child_id)
								handler(cli_fd);
						}
						else
						{
							if(close(cli_fd))
								perror("close on cli_fd:");
							perror("fork:");
							break;
						}
				 	}
					else
					{
						perror("accept:");
						break;
					}
				}
			}
			else
			{
				perror("listen:");
			}
		}
		else
		{
			perror("bind:");
		}
	}
	else
	{
		perror("socket:");
	}
	if(serv_fd)
	{
		if(close(serv_fd))
			perror("close on serv_fd:");
	}

	return 0;
}
