/***************************************************
 * Name    : comm_headers.h
 * 
 * DESC    : headers for server and client apps
 * 
 * Author  : pavanbobba206@gmail.com
*****************************************************/
#ifndef __COMM_HEADER_H__
#define __COMM_HEADER_H__

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<time.h>
#include <fcntl.h>
#include<pthread.h>

#define ERROR -1
#define SUCCESS 0
#define PORT 54321
#define BUF_SIZE 10000

int get_pwd(char *);
int list_contents(char *);
int change_dir(char *, char *);
void clean_up(char *);

#endif /*__COM_HEADER_H__*/
