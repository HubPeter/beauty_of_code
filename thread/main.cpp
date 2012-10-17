#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

void *thread_function(void *arg);

pthread_mutex_t work_mutex; //全局互斥锁对象，首先应该定义一个这样的互斥锁

#define WORK_SIZE 1024      //全局共享数据去
char work_area[WORK_SIZE];
int time_to_exit = 0;

int main(int argc,char *argv[])
{
    int res;
    pthread_t a_thread;
    void *thread_result;
    res = pthread_mutex_init(&work_mutex, NULL); //init mutex 初始化互斥锁
    if (res != 0)
    {
        perror("Mutex initialization failed");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&a_thread, NULL, thread_function, NULL);//create new thread创建新线程
    if (res != 0)
    {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_lock(&work_mutex);            //lock the mutex 互斥锁上锁
    printf("Input some text. Enter 'end' to finish\n");
    while(!time_to_exit) //标志
    {
        fgets(work_area, WORK_SIZE, stdin);        //get a string from stdin读取一行信息
        pthread_mutex_unlock(&work_mutex);        //unlock the mutex解锁
        while(1)
        {
                 	pthread_mutex_lock(&work_mutex);    //lock the mutex
                    if (work_area[0] != '\0')           //检查读入的内容输出没有
               		{
                           pthread_mutex_unlock(&work_mutex);    //unlock the mutex如果没有输出，解锁
                           sleep(1);
                    }
                    else
            		{
                    	break;
                    }
        }
    }
    pthread_mutex_unlock(&work_mutex);//解锁
    printf("\nWaiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);//等待另一个线程结束
    if (res != 0)
    {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined\n");
    pthread_mutex_destroy(&work_mutex);//销毁互斥锁
    exit(EXIT_SUCCESS);
}
void *thread_function(void *arg)
{
    sleep(1);
    pthread_mutex_lock(&work_mutex);//上锁，抢占资源
    while(strncmp("end", work_area, 3) != 0) //判断是不是结束信息end
    {
        printf("You input %d characters\n", strlen(work_area) -1);//时结束信心的话，就输出输入的字符个数
        printf("the characters is %s",work_area);//输出输入的字符内容
        work_area[0] = '\0';//设置最后以为为“\0”
        pthread_mutex_unlock(&work_mutex);// 输出完成以后就解锁
        sleep(1);
        pthread_mutex_lock(&work_mutex);//上锁
        while (work_area[0] == '\0' ) //判断第一位是不是为\0
        {
            pthread_mutex_unlock(&work_mutex);//解锁等待
            sleep(1);
            pthread_mutex_lock(&work_mutex);//上锁再次循环
        }
    }
    time_to_exit = 1;//设置结束标志
    work_area[0] = '\0';
    pthread_mutex_unlock(&work_mutex);
    pthread_exit(0);
}
