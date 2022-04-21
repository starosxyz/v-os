/*-
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 1982, 1986, 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)errno.h	8.5 (Berkeley) 1/21/94
 * $FreeBSD$
 */

#ifndef _SYS_ERRNO_H_
#define _SYS_ERRNO_H_

#if !defined(_KERNEL) && !defined(_STANDALONE)
#include <sys/cdefs.h>
__BEGIN_DECLS
int *	__error(void);
__END_DECLS
#define	errno		(* __error())
#endif

#define	VOS_EPERM		1		/* Operation not permitted */
#define	VOS_ENOENT		2		/* No such file or directory */
#define	VOS_ESRCH		3		/* No such process */
#define	VOS_EINTR		4		/* Interrupted system call */
#define	VOS_EIO		5		/* Input/output error */
#define	VOS_ENXIO		6		/* Device not configured */
#define	VOS_E2BIG		7		/* Argument list too long */
#define	VOS_ENOEXEC		8		/* Exec format error */
#define	VOS_EBADF		9		/* Bad file descriptor */
#define	VOS_ECHILD		10		/* No child processes */
#define	VOS_EDEADLK		11		/* Resource deadlock avoided */
					/* 11 was EAGAIN */
#define	VOS_ENOMEM		12		/* Cannot allocate memory */
#define	VOS_EACCES		13		/* Permission denied */
#define	VOS_EFAULT		14		/* Bad address */
#ifndef _POSIX_SOURCE
#define	VOS_ENOTBLK		15		/* Block device required */
#endif
#define	VOS_EBUSY		16		/* Device busy */
#define	VOS_EEXIST		17		/* File exists */
#define	VOS_EXDEV		18		/* Cross-device link */
#define	VOS_ENODEV		19		/* Operation not supported by device */
#define	VOS_ENOTDIR		20		/* Not a directory */
#define	VOS_EISDIR		21		/* Is a directory */
#define	VOS_EINVAL		22		/* Invalid argument */
#define	VOS_ENFILE		23		/* Too many open files in system */
#define	VOS_EMFILE		24		/* Too many open files */
#define	VOS_ENOTTY		25		/* Inappropriate ioctl for device */
#ifndef _POSIX_SOURCE
#define	VOS_ETXTBSY		26		/* Text file busy */
#endif
#define	VOS_EFBIG		27		/* File too large */
#define	VOS_ENOSPC		28		/* No space left on device */
#define	VOS_ESPIPE		29		/* Illegal seek */
#define	VOS_EROFS		30		/* Read-only filesystem */
#define	VOS_EMLINK		31		/* Too many links */
#define	VOS_EPIPE		32		/* Broken pipe */

/* math software */
#define	VOS_EDOM		33		/* Numerical argument out of domain */
#define	VOS_ERANGE		34		/* Result too large */

/* non-blocking and interrupt i/o */
#define	VOS_EAGAIN		35		/* Resource temporarily unavailable */
#ifndef _POSIX_SOURCE
#define	VOS_EWOULDBLOCK	VOS_EAGAIN		/* Operation would block */
#define	VOS_EINPROGRESS	36		/* Operation now in progress */
#define	VOS_EALREADY	37		/* Operation already in progress */

/* ipc/network software -- argument errors */
#define	VOS_ENOTSOCK	38		/* Socket operation on non-socket */
#define	VOS_EDESTADDRREQ	39		/* Destination address required */
#define	VOS_EMSGSIZE	40		/* Message too long */
#define	VOS_EPROTOTYPE	41		/* Protocol wrong type for socket */
#define	VOS_ENOPROTOOPT	42		/* Protocol not available */
#define	VOS_EPROTONOSUPPORT	43		/* Protocol not supported */
#define	VOS_ESOCKTNOSUPPORT	44		/* Socket type not supported */
#define	VOS_EOPNOTSUPP	45		/* Operation not supported */
#define	VOS_ENOTSUP		VOS_EOPNOTSUPP	/* Operation not supported */
#define	VOS_EPFNOSUPPORT	46		/* Protocol family not supported */
#define	VOS_EAFNOSUPPORT	47		/* Address family not supported by protocol family */
#define	VOS_EADDRINUSE	48		/* Address already in use */
#define	VOS_EADDRNOTAVAIL	49		/* Can't assign requested address */

/* ipc/network software -- operational errors */
#define	VOS_ENETDOWN	50		/* Network is down */
#define	VOS_ENETUNREACH	51		/* Network is unreachable */
#define	VOS_ENETRESET	52		/* Network dropped connection on reset */
#define	VOS_ECONNABORTED	53		/* Software caused connection abort */
#define	VOS_ECONNRESET	54		/* Connection reset by peer */
#define	VOS_ENOBUFS		55		/* No buffer space available */
#define	VOS_EISCONN		56		/* Socket is already connected */
#define	VOS_ENOTCONN	57		/* Socket is not connected */
#define	VOS_ESHUTDOWN	58		/* Can't send after socket shutdown */
#define	VOS_ETOOMANYREFS	59		/* Too many references: can't splice */
#define	VOS_ETIMEDOUT	60		/* Operation timed out */
#define	VOS_ECONNREFUSED	61		/* Connection refused */

#define	VOS_ELOOP		62		/* Too many levels of symbolic links */
#endif /* _POSIX_SOURCE */
#define	VOS_ENAMETOOLONG	63		/* File name too long */

/* should be rearranged */
#ifndef _POSIX_SOURCE
#define	VOS_EHOSTDOWN	64		/* Host is down */
#define	VOS_EHOSTUNREACH	65		/* No route to host */
#endif /* _POSIX_SOURCE */
#define	VOS_ENOTEMPTY	66		/* Directory not empty */

/* quotas & mush */
#ifndef _POSIX_SOURCE
#define	VOS_EPROCLIM	67		/* Too many processes */
#define	VOS_EUSERS		68		/* Too many users */
#define	VOS_EDQUOT		69		/* Disc quota exceeded */

/* Network File System */
#define	VOS_ESTALE		70		/* Stale NFS file handle */
#define	VOS_EREMOTE		71		/* Too many levels of remote in path */
#define	VOS_EBADRPC		72		/* RPC struct is bad */
#define	VOS_ERPCMISMATCH	73		/* RPC version wrong */
#define	VOS_EPROGUNAVAIL	74		/* RPC prog. not avail */
#define	VOS_EPROGMISMATCH	75		/* Program version wrong */
#define	VOS_EPROCUNAVAIL	76		/* Bad procedure for program */
#endif /* _POSIX_SOURCE */

#define	VOS_ENOLCK		77		/* No locks available */
#define	VOS_ENOSYS		78		/* Function not implemented */

#ifndef _POSIX_SOURCE
#define	VOS_EFTYPE		79		/* Inappropriate file type or format */
#define	VOS_EAUTH		80		/* Authentication error */
#define	VOS_ENEEDAUTH	81		/* Need authenticator */
#define	VOS_EIDRM		82		/* Identifier removed */
#define	VOS_ENOMSG		83		/* No message of desired type */
#define	VOS_EOVERFLOW	84		/* Value too large to be stored in data type */
#define	VOS_ECANCELED	85		/* Operation canceled */
#define	VOS_EILSEQ		86		/* Illegal byte sequence */
#define	VOS_ENOATTR		87		/* Attribute not found */

#define	VOS_EDOOFUS		88		/* Programming error */
#endif /* _POSIX_SOURCE */

#define	VOS_EBADMSG		89		/* Bad message */
#define	VOS_EMULTIHOP	90		/* Multihop attempted */
#define	VOS_ENOLINK		91		/* Link has been severed */
#define	VOS_EPROTO		92		/* Protocol error */

#ifndef _POSIX_SOURCE
#define	VOS_ENOTCAPABLE	93		/* Capabilities insufficient */
#define	VOS_ECAPMODE	94		/* Not permitted in capability mode */
#define	VOS_ENOTRECOVERABLE	95		/* State not recoverable */
#define	VOS_EOWNERDEAD	96		/* Previous owner died */
#define	VOS_EINTEGRITY	97		/* Integrity check failed */
#endif /* _POSIX_SOURCE */

#ifndef _POSIX_SOURCE
#define	VOS_ELAST		97		/* Must be equal largest errno */
#endif /* _POSIX_SOURCE */

#if defined(_KERNEL) || defined(_WANT_KERNEL_ERRNO) || defined(_STANDALONE)
/* pseudo-errors returned inside kernel to modify return to process */
#define	VOS_ERESTART	(-1)		/* restart syscall */
#define	VOS_EJUSTRETURN	(-2)		/* don't modify regs, just return */
#define	VOS_ENOIOCTL	(-3)		/* ioctl not handled by this layer */
#define	VOS_EDIRIOCTL	(-4)		/* do direct ioctl in GEOM */
#define	VOS_ERELOOKUP	(-5)		/* retry the directory lookup */
#endif

#ifndef _KERNEL
#if __EXT1_VISIBLE
/* ISO/IEC 9899:2011 K.3.2.2 */
#ifndef _ERRNO_T_DEFINED
#define _ERRNO_T_DEFINED
typedef int errno_t;
#endif
#endif /* __EXT1_VISIBLE */
#endif

#endif
