/***************************************************
 * Name    : client.c
 * 
 * DESC    : client app
 * 
 * Author  : pavanbobba206@gmail.com
*****************************************************/
#include "comm_header.h"

void handler(int client_fd)
{
	char buf[BUF_SIZE];
	
	while(1)
	{
		memset(buf, '\0', sizeof(buf));
		printf("message to server:\n\n");
		fgets(buf, sizeof(buf), stdin);
		if(buf != NULL)
		{
			if(write(client_fd, buf, sizeof(buf)) != ERROR)
			{
				printf("\n\nmessage from server:\n\n");
				if(read(client_fd, buf, sizeof(buf)) != ERROR)
				{
					printf("%s\n\n", buf);
					if(!strncmp(buf, "please", 6))
						break;
				}
				else
				{
					perror("read:");
					break;
				}
			}
			else
			{
				perror("write:");
				break;
			}
		}
		else
		{
			perror("fgets:");
			break;
		}
	}
}

int main()
{
	int cli_fd;
    struct sockaddr_in cli_addr;
	cli_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(cli_fd != ERROR)
	{
		bzero(&cli_addr, sizeof(cli_addr));

		cli_addr.sin_family = AF_INET;
		cli_addr.sin_port = htons(PORT);
		cli_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        if(!connect(cli_fd, (const struct sockaddr *)&cli_addr, sizeof(cli_addr)))
		{
			handler(cli_fd);
			close(cli_fd);
		}
		else
		{
			perror("connect:");
		}
	}
	else
	{
		perror("socket:");
	}
		
	return 0;
}
