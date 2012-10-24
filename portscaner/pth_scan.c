#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

void error(const char *err_str, int line)
{
    if (err_str == NULL)
    {
        return ;
    }

    fprintf(stderr,"line:%d\n",__LINE__);
    perror(err_str);
    exit(-1);
}

void err_quit(const char *err_str,int line)
{
    if (err_str == NULL)
    {
        return ;
    }
    else
    {
        printf("Error in line %d\n",line);
        printf("%s\n",err_str);
        exit(-1);
    }
}

typedef struct _Port{
    struct in_addr des_ip;
    unsigned short int max_port;
    unsigned short int mini_port;
}Port;

int do_scan(struct sockaddr_in  serv_addr)
{
    int connfd;
    int ret;

    if ((connfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
    {
        error("creating socket.",__LINE__);
    }

    ret = connect(connfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

    if (ret < 0)
    {
        if (errno == ECONNREFUSED)
        {
            close(connfd);
            return 0;
        }
        else
        {
            close(connfd);
            return -1;
        }

    }
    else if (ret == 0)
    {
        close(connfd);
        return 1;
    }

    return -1;
}
/*
*扫描进程主函数
*FUNC：扫描指定范围的端口   
*参数：port.mini_port,起始端口
*    结束端口：port.max_port
*/
void *scaner(void *arg)
{
    int ret;
    unsigned short int i; 
    Port port;
    struct sockaddr_in serv_addr;
    bzero(&serv_addr,sizeof(serv_addr));

    memcpy(&port,arg,sizeof(Port));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = port.des_ip.s_addr;

    for (i = port.mini_port; i <= port.max_port; i++) 
    {
        serv_addr.sin_port = htons(i);
        ret = do_scan(serv_addr);
        if (ret == 1)
        {
            fprintf(stdout,"port %d is open.\n",i);
        }
        else
        {
            continue;
        }

    }
}

int main(int argc, char **argv)
{

    pthread_t *thread;
    int max_port;
    int thread_num;
    struct in_addr des_ip;
    int port_len;
    int i;
    
    if (argc != 7)
    {
        printf("usage:%s -m [max_port] -a [ip_address] -n [thread_num]\n",argv[0]);
        exit (-1);
    }
	//检测参数的正确性
    for (i = 0; i < argc; i++)
    {
		//max port
        if (strcmp("-m",argv[i]) == 0)
        {
            max_port = atoi(argv[i+1]);
            if (max_port <= 0 || max_port > 65535)
            {
                err_quit("invaild port.",__LINE__);
            }
            continue;
        }
		//IP地址
        if (strcmp("-a",argv[i]) == 0)
        {
            if(inet_aton(argv[i+1],&des_ip) == 0) 
            {
                err_quit("invaild ip address.",__LINE__);
            }
            continue;
        }
        //开启的线程数量
        if (strcmp("-n",argv[i]) == 0)
        {
            thread_num = atoi(argv[i+1]);
            if (thread_num < 0)
            {
                err_quit("invaild thread_num.",__LINE__);
            }
            continue;
        }
    }
	//为了不浪费资源，设置线程数量最小
    if (max_port < thread_num)
    {
        thread_num = max_port;
    }
    //每个线程处理的端口数量
    port_len = max_port / thread_num;
    if (max_port % thread_num)
        port_len += 1;
    //为线程控制结构分配空间
    thread = (pthread_t *)malloc(sizeof(pthread_t) * thread_num);
	//
    if (thread == NULL)
    {
        err_quit("malloc failed,no more space for pthread.",
                 __LINE__);
    }

    for (i = 0; i < thread_num; i++)
    {
        Port port;
        port.des_ip = des_ip;
        port.mini_port = i * port_len + 1;//########奇数、偶数？
        if ( i == thread_num -1)
        {
            port.max_port = max_port;
        }
        else
        {
            port.max_port = port.mini_port + port_len - 1;
        }

        if (pthread_create(&thread[i],NULL,scaner,(void *)&port))
        {
            err_quit("pthread create error.",__LINE__);
        }

        pthread_join(thread[i],NULL);
    }

    if (thread)
    {
        free(thread);
    }

    return 0;

}
