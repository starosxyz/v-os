/*-
 * SPDX-License-Identifier: BSD-4-Clause
 *
 * Copyright (c) 2001, 2002 Mike Barcroft <mike@FreeBSD.org>
 * Copyright (c) 2001 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Klaus Klein.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *        This product includes software developed by the NetBSD
 *        Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef _MACHINE__STDINT_H_
#define	_MACHINE__STDINT_H_

#include <machine/_limits.h>

#if !defined(__cplusplus) || defined(__STDC_CONSTANT_MACROS)

#define	VOS_INT8_C(c)		(c)
#define	VOS_INT16_C(c)		(c)
#define	VOS_INT32_C(c)		(c)

#define	VOS_UINT8_C(c)		(c)
#define	VOS_UINT16_C(c)		(c)
#define	VOS_UINT32_C(c)		(c ## U)

#ifdef	__LP64__
#define	VOS_INT64_C(c)		(c ## L)
#define	VOS_UINT64_C(c)		(c ## UL)
#else
#define	VOS_INT64_C(c)		(c ## LL)
#define	VOS_UINT64_C(c)		(c ## ULL)
#endif

#define	VOS_INTMAX_C(c)		VOS_INT64_C(c)
#define	VOS_UINTMAX_C(c)		VOS_UINT64_C(c)

#endif /* !defined(__cplusplus) || defined(__STDC_CONSTANT_MACROS) */

#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS)

/*
 * ISO/IEC 9899:1999
 * 7.18.2.1 Limits of exact-width integer types
 */
#define	VOS_INT8_MIN	(-0x7f-1)
#define	VOS_INT16_MIN	(-0x7fff-1)
#define	VOS_INT32_MIN	(-0x7fffffff-1)

#define	VOS_INT8_MAX	0x7f
#define	VOS_INT16_MAX	0x7fff
#define	VOS_INT32_MAX	0x7fffffff

#define	VOS_UINT8_MAX	0xff
#define	VOS_UINT16_MAX	0xffff
#define	VOS_UINT32_MAX	0xffffffffU

#ifdef __LP64__
#define	VOS_INT64_MIN	(-0x7fffffffffffffff-1)
#define	VOS_INT64_MAX	0x7fffffffffffffff
#define	VOS_UINT64_MAX	0xffffffffffffffff
#else
#define	VOS_INT64_MIN	(-0x7fffffffffffffffLL-1)
#define	VOS_INT64_MAX	0x7fffffffffffffffLL
#define	VOS_UINT64_MAX	0xffffffffffffffffULL
#endif

/*
 * ISO/IEC 9899:1999
 * 7.18.2.2  Limits of minimum-width integer types
 */
/* Minimum values of minimum-width signed integer types. */
#define	VOS_INT_LEAST8_MIN	VOS_INT8_MIN
#define	VOS_INT_LEAST16_MIN	VOS_INT16_MIN
#define	VOS_INT_LEAST32_MIN	VOS_INT32_MIN
#define	VOS_INT_LEAST64_MIN	VOS_INT64_MIN

/* Maximum values of minimum-width signed integer types. */
#define	VOS_INT_LEAST8_MAX	VOS_INT8_MAX
#define	VOS_INT_LEAST16_MAX	VOS_INT16_MAX
#define	VOS_INT_LEAST32_MAX	VOS_INT32_MAX
#define	VOS_INT_LEAST64_MAX	VOS_INT64_MAX

/* Maximum values of minimum-width unsigned integer types. */
#define	VOS_UINT_LEAST8_MAX	 VOS_UINT8_MAX
#define	VOS_UINT_LEAST16_MAX VOS_UINT16_MAX
#define	VOS_UINT_LEAST32_MAX VOS_UINT32_MAX
#define	VOS_UINT_LEAST64_MAX VOS_UINT64_MAX

/*
 * ISO/IEC 9899:1999
 * 7.18.2.3  Limits of fastest minimum-width integer types
 */
/* Minimum values of fastest minimum-width signed integer types. */
#define	VOS_INT_FAST8_MIN	VOS_INT32_MIN
#define	VOS_INT_FAST16_MIN	VOS_INT32_MIN
#define	VOS_INT_FAST32_MIN	VOS_INT32_MIN
#define	VOS_INT_FAST64_MIN	VOS_INT64_MIN

/* Maximum values of fastest minimum-width signed integer types. */
#define	VOS_INT_FAST8_MAX	VOS_INT32_MAX
#define	VOS_INT_FAST16_MAX	VOS_INT32_MAX
#define	VOS_INT_FAST32_MAX	VOS_INT32_MAX
#define	VOS_INT_FAST64_MAX	VOS_INT64_MAX

/* Maximum values of fastest minimum-width unsigned integer types. */
#define	VOS_UINT_FAST8_MAX	VOS_UINT32_MAX
#define	VOS_UINT_FAST16_MAX	VOS_UINT32_MAX
#define	VOS_UINT_FAST32_MAX	VOS_UINT32_MAX
#define	VOS_UINT_FAST64_MAX	VOS_UINT64_MAX

/*
 * ISO/IEC 9899:1999
 * 7.18.2.4  Limits of integer types capable of holding object pointers
 */
#define	VOS_INTPTR_MIN	VOS_INT64_MIN
#define	VOS_INTPTR_MAX	VOS_INT64_MAX
#define	VOS_UINTPTR_MAX	VOS_UINT64_MAX

/*
 * ISO/IEC 9899:1999
 * 7.18.2.5  Limits of greatest-width integer types
 */
#define	VOS_INTMAX_MIN	VOS_INT64_MIN
#define	VOS_INTMAX_MAX	VOS_INT64_MAX
#define	VOS_UINTMAX_MAX	VOS_UINT64_MAX

/*
 * ISO/IEC 9899:1999
 * 7.18.3  Limits of other integer types
 */
 /* Limits of ptrdiff_t. */
#define	VOS_PTRDIFF_MIN	VOS_INT64_MIN	
#define	VOS_PTRDIFF_MAX	VOS_INT64_MAX

/* Limits of sig_atomic_t. */
#define	VOS_SIG_ATOMIC_MIN	__LONG_MIN
#define	VOS_SIG_ATOMIC_MAX	__LONG_MAX

/* Limit of size_t. */
#define	VOS_SIZE_MAX	VOS_UINT64_MAX

/* Limits of wint_t. */
#define	VOS_WINT_MIN	VOS_INT32_MIN
#define	VOS_WINT_MAX	VOS_INT32_MAX

#endif /* !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) */

#endif /* !_MACHINE__STDINT_H_ */
