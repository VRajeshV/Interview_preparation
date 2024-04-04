#ifndef PAVAN_IOCTL_OPS_H
#define PAVAN_IOCTL_OPS_H

/*choose magic number and sequence of commands*/
#define PAVAN_MAGIC 6
#define ERASE_BUF_SEQ_NO 0x01
#define GET_FILE_POS_SEQ_NO 0x02

#define ERASE_BUF _IO(PAVAN_MAGIC, ERASE_BUF_SEQ_NO)
#define GET_FILE_POS _IOR(PAVAN_MAGIC, ERASE_BUF_SEQ_NO, int *)

#endif/*PAVAN_IOCTL_OPS_H*/
