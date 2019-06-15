/**********************************
          INCLUDE
***********************************/
#include<iostream>
#include<cstdio>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <arpa/inet.h>
#include"stdio.h"
using namespace std;
/**********************************/
/**********************************
         MAIN FUNCTION
***********************************/
int main(int argc,char* argv[])
{   
    //SOCKET CREATION:
    int sockfd,newfd,n,m;
    socklen_t len;
    int i=0;
    struct sockaddr_in servaddr, cliaddr;
    char buff[1024];
    char str[1000];
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
     perror("CANNOT CREATE A SOCKET");
    }
    bzero(&servaddr,sizeof(servaddr));

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr(argv[1]);
    servaddr.sin_port=htons(9960);

    //CONNECTING THE CLIENT TO THE SOCKET:
    connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    
    //COMMUNICATION BETWEEN CLIENT AND SERVER:
    while(1)
    {
    cout<<"\nclient:";
    cin.getline(buff,100);
    n=write(sockfd,buff,sizeof(buff));
    m=read(sockfd,buff,sizeof(buff));
    cout<<"server:"<<buff;
    if((strcmp(buff,"end"))==0)
    {
     break;
    }
   
    //cout<<buff;
   }
   close(sockfd);
   return 0;
  }



    

    
