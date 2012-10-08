//@Linux公社http://www.linuxidc.com/Linux/2011-06/36860.htm
#include <sys/types.h>
#include <string.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>   
#define MAX_LINE 80   
#define MY_MQ_ID 1233   
/*消息结构体的一般形式如下：  
  typedef struct  
  {  
    long type;   //用于存放消息代码，必须位于首位  
    char message[ LENGHT+1 ];  
  }MSG_TYPE_T;  
 */  
typedef struct  
{   
    long type;     
    float fval;   
    unsigned int uival;   
    char strval[ MAX_LINE+1 ];   
}MY_TYPE_T;   
int main(  )   
    {   
        int msgid,ret;   
        //create the message queue with the id MY_MQ_ID   
        msgid=msgget( MY_MQ_ID,0666|IPC_CREAT );   
        if( msgid>=0 )   
             printf( "Created a Message Queue,message queue identifier is %d\n",msgid );   
        //modify the size of message queue   
        struct msqid_ds buf;   
        ret=msgctl( msgid,IPC_STAT,&buf );   
        printf( "The origianl size of queue is %d\n",buf.msg_qbytes );   
           
        buf.msg_qbytes=4096;   
        ret=msgctl( msgid,IPC_SET,&buf );   
        if( ret==0 )   
            printf( "Size sucessfully changed for queue,message queue identifier is %d\n",msgid );   
        //send a message   
        MY_TYPE_T myMessage;   
        myMessage.type=1L;   //消息的类型,msgrcv会用到   
        myMessage.fval=128.256;   
        myMessage.uival=512;   
        strncpy( myMessage.strval,"This is a test.\n",MAX_LINE );   
        ret=msgsnd( msgid,( struct msgbuf* )&myMessage,sizeof( MY_TYPE_T ),0 ); //0是消息旗标   
        if( ret!=-1 )   
            printf( "Message send successfully.\n" );   
        //read a message   
        MY_TYPE_T recMessage;   
        ret=msgrcv( msgid,( struct msgbuf* )&recMessage,sizeof(MY_TYPE_T),1,0 );//这个地方Message Type要和欲接受的消息类型相同   
        if( ret!=-1 )   
            {   
                printf( "\nRead a message from the queue\n" );   
                printf( "Message Type:%ld\n",recMessage.type );   
                printf( "Float value:%f\n",recMessage.fval );   
                printf( "Uint value:%d\n",recMessage.uival );   
                printf( "String value:%s\n",recMessage.strval );   
            }   
        //destroy a message queue   
        ret=msgctl( msgid,IPC_RMID,NULL );   
        if( ret!=-1 )   
            printf( "Message queue %d sucessfully removed.\n",msgid );   
           
        return 0;   
    }   
/*还有很多实际创建时的细节，可以通过man进行查找  
  使用命令来查看IPC队列：  
  ipcs -q  
  ipcs -q -i $msgid  
  ipcrm -q $msgid  
 */  
