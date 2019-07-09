#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

 /*GLobal*/
const char *filename = NULL;
int fd;
struct stat *filestat;


int
f_stat(const char *filename, struct stat *buf){
   int res = 0;
     res = stat(filename,buf);
   return res;
}


/*
this system calls return a stat structure, which contains the
following fields:

    struct stat {
        dev_t     st_dev;          ID of device containing file
        ino_t     st_ino;          Inode number
        mode_t    st_mode;         File type and mode
        nlink_t   st_nlink;         Number of hard links
        uid_t     st_uid;           User ID of owner
        gid_t     st_gid;           Group ID of owner
        dev_t     st_rdev;          Device ID (if special file)
        off_t     st_size;          Total size, in bytes
        blksize_t st_blksize;      Block size for filesystem I/O
        blkcnt_t  st_blocks;       Number of 512B blocks allocated

         Since Linux 2.6, the kernel supports nanosecond
           precision for the following timestamp fields.
           For the details before Linux 2.6, see NOTES.

        struct timespec st_atim;    Time of last access
        struct timespec st_mtim;    Time of last modification
        struct timespec st_ctim;    Time of last status change

    #define st_atime st_atim.tv_sec       Backward compatibility
    #define st_mtime st_mtim.tv_sec
    #define st_ctime st_ctim.tv_sec
    };

Note: the order of fields in the stat structure varies somewhat
across architectures.  In addition, the definition above does not
show the padding bytes that may be present between some fields on
various architectures.  Consult the glibc and kernel source code if
you need to know the details.

Note: for performance and simplicity reasons, different fields in the
stat structure may contain state information from different moments
during the execution of the system call.  For example, if st_mode or
st_uid is changed by another process by calling chmod(2) or chown(2),
stat() might return the old st_mode together with the new st_uid, or
the old st_uid together with the new st_mode.

The fields in the stat structure are as follows:

st_dev This field describes the device on which this file resides.
       (The major(3) and minor(3) macros may be useful to decompose
       the device ID in this field.)

st_ino This field contains the file's inode number.

st_mode
       This field contains the file type and mode.  See inode(7) for
       further information.

st_nlink
       This field contains the number of hard links to the file.

st_uid This field contains the user ID of the owner of the file.

st_gid This field contains the ID of the group owner of the file.

st_rdev
       This field describes the device that this file (inode) repre‐
       sents.

st_size
       This field gives the size of the file (if it is a regular file
       or a symbolic link) in bytes.  The size of a symbolic link is
       the length of the pathname it contains, without a terminating
       null byte.

st_blksize
       This field gives the "preferred" block size for efficient
       filesystem I/O.

st_blocks
       This field indicates the number of blocks allocated to the
       file, in 512-byte units.  (This may be smaller than
       st_size/512 when the file has holes.)

st_atime
       This is the file's last access timestamp.

st_mtime
       This is the file's last modification timestamp.

st_ctime
       This is the file's last status change timestamp.
*/
