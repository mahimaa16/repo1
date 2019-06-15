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
using namespace std;
/**********************************/
/**********************************
         MAIN FUNCTION
***********************************/
int main()
{   
    //SOCKET CREATION:
    int sockfd,newfd,n,m;
    socklen_t len;
    struct sockaddr_in servaddr, cliaddr;
    char buff[1024];
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
     perror("CANNOT CREATE A SOCKET");
    }
    bzero(&servaddr,sizeof(servaddr));

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=INADDR_ANY;
    servaddr.sin_port=htons(9956);
    
    //BINDING THE SOCKET:
    if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
    perror("BIND ERROR");
    listen(sockfd,2);
    len=sizeof(cliaddr);
    newfd=accept(sockfd,(struct sockaddr*)&cliaddr,&len);

    //COMMUNICATION BETWEEN CLIENT AND SERVER:
    while(1)
    {
     n=read(newfd,buff,sizeof(buff));
     
     cout<<"\nclient:"<<buff;
     cout<<"\nserver:";
     cin.getline(buff,100);
     m=write(newfd,buff,sizeof(buff));
     if((strcmp(buff,"end"))==0)
     {
      break;
     }
    }
   close(sockfd);
   close(newfd);
   return 0;
}


    

    

