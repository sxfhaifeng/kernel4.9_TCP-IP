#ifndef	__IMP2__H
#define __IMP2__H

#define IMP2_U_PID 0
#define IMP2_K_MSG 1
#define IMP2_CLOSE 2

#define NL_IMP2 31

struct packet_info
{
	__u32 src;
	__u32 dest;
};
#endif
