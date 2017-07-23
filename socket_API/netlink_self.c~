#include <stdio.h>			/*标准输入输出*/
#include <sys/types.h>		/*基本系统数据类型*/
#include <sys/stat.h>		/*文件状态*/
#include <fcntl.h>			/**/
#include <libelf.h>
#include <gelf.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <linux/bpf.h>
#include <linux/filter.h>
#include <linux/perf_event.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <linux/types.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <poll.h>
#include <ctype.h>
#include <assert.h>

#define NETLINK_TEST 25	/*定义自己的netlink套接字协议*/

static void sig_init(int signo){
	struct sockaddr_nl kpeer;
	struct nlmsghdr message;
	memset(&kpeer,0,sizeof(kpeer));
	kpeer.nl_family = AF_NETLINK;
	kpeer.nk_pid = 0;	/*for linux kernel*/
	kpeer.nl_groups = 0;
	
	memset(&message,0,sizeof(message));
	message.nlmsg_len = NLMSG_LENGTH(0);
	message.nlmsg_flags = 0;
	message.nlmsg_type = IMP2_CLOSE;
}




int main(int argc,char *argv[])
{
	struct sockaddr_nl src_addr,dest_addr;	/*定义netlink套接字结构体*/
	struct nlmsghdr	*nlh = NULL;	/*netlink消息报头结构体*/
	struct iovec iov;	/*为readv和writev用，the iovec结构体表述一个buffer保存两个文件，一个buffer地址，一个buffer长度*/
	int sock_fd;
	struct msghdr msg;
	char *magic = "shutdown";
	if((sock_fd = socket(AF_NETLINK,SOCK_RAW,NETLINK_USER)) == -1){
		printf("creat socket error:%s(error:%d)\n",strerror(errno),errno);
		exit(0);
	
	}
	memset(&src_add,0,sizeof(src_addr));
	src_addr.nl_family = AF_NETLINK;
	src_addr.nl_pad	= 0;
	src_addr.nl_groups = 0;
	src_addr.nl_pid = getpid();
	if((bind(sock_fd,(struct sockaddr*)&src_addr,sizeof(src_addr))) == -1){
		fprintf(stderr,"%s:%d-%d:%s\n",__FILE__,__LINE__,errno,strerror(errno));/*输出文件名、行号、错误号、错误字符串*/
		goto(Errp);
	
	}
	
	Errp:
		close(sock_fd);
		return 0;
}



