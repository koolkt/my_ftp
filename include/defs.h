/*
** defs.h for my_ftp in /srv/http
** 
** Made by Adolfo Flores
** Login   <flores_a@epitech.eu>
** 
** Started on  Sat Mar 21 15:01:32 2015 
** Last update Sun Mar 29 23:02:45 2015 
*/

#ifndef                         DEFS_H_
# define                        DEFS_H_

#include                        <stdio.h>
#include                        <strings.h>
#include                        <string.h>
#include                        <sys/types.h>
#include                        <sys/socket.h>
#include                        <netinet/in.h>
#include                        <arpa/inet.h>
#include                        <time.h>
#include                        <errno.h>
#include                        <sys/socket.h>
#include                        <stdlib.h>
#include                        <netdb.h>
#include                        <netinet/in.h>
#include                        <unistd.h>
#define                         OPEN_CONNECTION "150"
#define                         SUCCESS "200"
#define                         CON_ESTAB "220"
#define                         LOGGED_IN "230"
#define                         bad_pass "332"
#define                         action_completed "250"
#define                         NEED_PASS "331"
#define                         NOT_L_IN "530"
#define                         UNUSED(x) (void)(x)

typedef int (*t_aptr)(char **, FILE *, char*);
typedef int (*t_pt)(char **,FILE *);
typedef int (*t_action)(char *, int);

typedef struct                  s_vars
{
  struct sockaddr_in            s_in;
  struct protoent               *s_p;
  int                           port;
  int                           sockfd;
  struct sockaddr_in            s_in_client;
  socklen_t                     s_in_size;
  int                           client_fd;
  int                           server_fd;
  char                          **args;
  char                          *client_ip;
}                               t_vars;

int                             suser(char *user, int fd);
int                             pass(char *pass, int fd);
int                             send_data(t_vars *v);
int                             get_data(t_vars *v, char flg);
int                             send_port_cmd(FILE *f, char *b);
int                             listen_to_server(char, char**, int, FILE*);
int                             need_password(char**, FILE*);
int                             logged_in(char **, FILE*);
int                             not_logged_in(char **buffer,
                                              FILE* sock_stream);
int                             get_string(FILE *sock_stream,
                                           char **buff, size_t l,
                                           char s);
int                             quit(char **, FILE *, char*);
int                             user(char *, FILE *, char*);
int                             auth(char **tab, FILE *sock_stream, char *);
int                             ls(char **, FILE *, char*);
int                             cd(char **, FILE *, char*);
int                             get(char **, FILE *, char*);
int                             put(char **, FILE *, char*);
int                             pwd(char **, FILE *, char*);
char                            init_socket(int *fd);
void                            init_sin(struct sockaddr_in *s_in,
                                         int port, char *ip);
int                             connect_to_server(struct sockaddr *s_in,
                                                  int *sockfd, int port,
                                                  char *ip);
int                             readn(int sd,char *ptr,int size);
int                             writen(int sd,char *ptr,int size);
int                             process_clients(t_vars *v);
int                             handle_client(int fd);
char                            do_accept(int *c_fd,
                                  int fd,
                                  struct sockaddr* s_in_client,
                                  socklen_t *size);
int                             handle_commands(int fd);
#endif
