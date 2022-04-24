#include <sys/cdefs.h>
#include <sys/types.h>
#include <machine/atomic.h>
#include "context.h"
#include <windows.h>

HMODULE  g_hDll;
typedef void (WINAPI* MY_FUNVOID)(void);
typedef int (WINAPI* MY_FUNINT)(volatile u_int*);
typedef int (WINAPI* MY_FUNLONG)(volatile u_long*);
typedef int (WINAPI* MY_FUNINTINT)(volatile u_int*, u_int);
typedef void (WINAPI* MY_FUNVOIDCHAR)(volatile u_char*, u_char);
typedef u_int(WINAPI* MY_FUNUINTINT)(volatile u_int*, u_int);
typedef int (WINAPI* MY_FUNINTLONG)(volatile u_long*, u_int);
typedef void (WINAPI* MY_FUNVOIDINT)(volatile u_int*, u_int);
typedef void (WINAPI* MY_FUNVOIDLONG)(volatile u_long*, u_int);
typedef void (WINAPI* MY_FUNVOIDLONGLONG)(volatile u_long*, u_long);
typedef u_long(WINAPI* MY_FUNLONGINT)(volatile u_int*, u_int);
typedef u_long(WINAPI* MY_FUNLONGLONG)(volatile u_long*, u_int);
typedef u_long(WINAPI* MY_FUNLONGLONGLONG)(volatile u_long*, u_long);
typedef int	(WINAPI* MY_FUNINTTHRECHAR)(volatile u_char* , u_char , u_char );
typedef int	(WINAPI* MY_FUNINTTHRECHARCHAR)(volatile u_char*, u_char*, u_char);
typedef int	(WINAPI* MY_FUNINTTHRESHORT)(volatile u_short* , u_short , u_short );
typedef int	(WINAPI* MY_FUNINTTHRESHORTSHORT)(volatile u_short*, u_short*, u_short);
typedef int	(WINAPI* MY_FUNINTTHREINT)(volatile u_int*, u_int, u_int);
typedef int	(WINAPI* MY_FUNINTTHREINTINT)(volatile u_int*, u_int*, u_int);
typedef int	(WINAPI* MY_FUNINTTHRELONG)(volatile u_long*, u_long, u_long);
typedef int	(WINAPI* MY_FUNINTTHRELONGLONG)(volatile u_long*, u_long*, u_long);


void SetLoadLibrary()
{
	g_hDll = LoadLibrary("freebsdports.dll");
}

int	atomic_testandset_int(volatile u_int* p, u_int v)
{
	MY_FUNINTINT func;
	if (g_hDll)
		func = (MY_FUNINTINT)GetProcAddress(g_hDll, "atomic_testandset_int");
	if (func == NULL)
	{
		return -1;
	}
	return func(p,v);
}
int	atomic_testandclear_int(volatile u_int* p, u_int v)
{
	MY_FUNINTINT func;
	if (g_hDll)
		func = (MY_FUNINTINT)GetProcAddress(g_hDll, "atomic_testandclear_int");
	if (func == NULL)
	{
		return -1;
	}
	return func(p, v);
}
int atomic_testandset_long(volatile u_long *p, u_int v)
{
	MY_FUNINTLONG func;
	if (g_hDll)
		func = (MY_FUNINTLONG)GetProcAddress(g_hDll, "atomic_testandset_long");
	if (func == NULL)
	{
		return -1;
	}
	return func(p, v);
}


int atomic_testandclear_long(volatile u_long *p, u_int v)
{
	MY_FUNINTLONG func;
	if (g_hDll)
		func = (MY_FUNINTLONG)GetProcAddress(g_hDll, "atomic_testandclear_long");
	if (func == NULL)
	{
		return -1;
	}
	return func(p, v);
}
void atomic_add_barr_int(volatile u_int* P, u_int V)
{
	MY_FUNVOIDINT func;
	if (g_hDll)
		func = (MY_FUNVOIDINT)GetProcAddress(g_hDll, "atomic_add_barr_int");
	if (func == NULL)
	{
		return;
	}
	return func(P,V);
}
void atomic_add_barr_long(volatile u_long* P, u_long V)
{
	MY_FUNVOIDLONGLONG func;
	if (g_hDll)
		func = (MY_FUNVOIDLONGLONG)GetProcAddress(g_hDll, "atomic_add_barr_long");
	if (func == NULL)
	{
		return;
	}
	return func(P, V);
}
void atomic_set_int(volatile u_int* P, u_int V)
{
	MY_FUNVOIDINT func;
	if (g_hDll)
		func = (MY_FUNVOIDINT)GetProcAddress(g_hDll, "atomic_set_int");
	if (func == NULL)
	{
		return;
	}
	return func(P, V);
}
void atomic_clear_int(volatile u_int* P, u_int V)
{
	MY_FUNVOIDINT func;
	if (g_hDll)
		func = (MY_FUNVOIDINT)GetProcAddress(g_hDll, "atomic_clear_int");
	if (func == NULL)
	{
		return;
	}
	return func(P, V);
}

void atomic_add_int(volatile u_int* P, u_int V) {
	MY_FUNVOIDINT func;
	if (g_hDll)
		func = (MY_FUNVOIDINT)GetProcAddress(g_hDll, "atomic_add_int");
	if (func == NULL)
	{
		return;
	}
	return func(P, V);
}
void atomic_subtract_int(volatile u_int* P, u_int V)
{
	MY_FUNVOIDINT func;
	if (g_hDll)
		func = (MY_FUNVOIDINT)GetProcAddress(g_hDll, "atomic_subtract_int");
	if (func == NULL)
	{
		return;
	}
	return func(P, V);
}
void atomic_add_long(volatile u_long* P, u_long V) {
	MY_FUNVOIDLONGLONG func;
	if (g_hDll)
		func = (MY_FUNVOIDLONGLONG)GetProcAddress(g_hDll, "atomic_add_long");
	if (func == NULL)
	{
		return;
	}
	return func(P, V);
}
void atomic_subtract_long(volatile u_long* P, u_long V)
{
	MY_FUNVOIDLONGLONG func;
	if (g_hDll)
		func = (MY_FUNVOIDLONGLONG)GetProcAddress(g_hDll, "atomic_subtract_long");
	if (func == NULL)
	{
		return;
	}
	return func(P, V);
}

u_int atomic_fetchadd_int(volatile u_int* p, u_int v)
{
	MY_FUNUINTINT func;
	if (g_hDll)
		func = (MY_FUNUINTINT)GetProcAddress(g_hDll, "atomic_fetchadd_int");
	if (func == NULL)
	{
		return -1;
	}
	return func(p,v);
}
u_long	atomic_fetchadd_long(volatile u_long* p, u_long v)
{
	MY_FUNLONGLONGLONG func;
	if (g_hDll)
		func = (MY_FUNLONGLONGLONG)GetProcAddress(g_hDll, "atomic_fetchadd_long");
	if (func == NULL)
	{
		return -1;
	}
	return func(p, v);
}

u_int atomic_fetchsub_int(volatile u_int* p, u_int v)
{
	MY_FUNUINTINT func;
	if (g_hDll)
		func = (MY_FUNUINTINT)GetProcAddress(g_hDll, "atomic_fetchsub_int");
	if (func == NULL)
	{
		return -1;
	}
	return func(p, v);
}
u_long	atomic_fetchsub_long(volatile u_long* p, u_long v)
{
	MY_FUNLONGLONGLONG func;
	if (g_hDll)
		func = (MY_FUNLONGLONGLONG)GetProcAddress(g_hDll, "atomic_fetchsub_int");
	if (func == NULL)
	{
		return -1;
	}
	return func(p, v);
}

int	atomic_cmpset_char(volatile u_char* object, u_char expect, u_char desired)
{
	MY_FUNINTTHRECHAR func;
	if (g_hDll)
		func = (MY_FUNINTTHRECHAR)GetProcAddress(g_hDll, "atomic_cmpset_char");
	if (func == NULL)
	{
		return -1;
	}
	return func(object, expect, desired);
}
int	atomic_cmpset_short(volatile u_short* dst, u_short expect, u_short desired)
{
	MY_FUNINTTHRESHORT func;
	if (g_hDll)
		func = (MY_FUNINTTHRESHORT)GetProcAddress(g_hDll, "atomic_cmpset_short");
	if (func == NULL)
	{
		return -1;
	}
	return func(dst, expect, desired);
}
int	atomic_cmpset_int(volatile u_int* dst, u_int expect, u_int desired)
{
	MY_FUNINTTHREINT func;
	if (g_hDll)
		func = (MY_FUNINTTHREINT)GetProcAddress(g_hDll, "atomic_cmpset_int");
	if (func == NULL)
	{
		return -1;
	}
	return func(dst, expect, desired);
}
int	atomic_cmpset_long(volatile u_long* dst, u_long expect, u_long desired)
{
	MY_FUNINTTHRELONG func;
	if (g_hDll)
		func = (MY_FUNINTTHRELONG)GetProcAddress(g_hDll, "atomic_cmpset_long");
	if (func == NULL)
	{
		return -1;
	}
	return func(dst, expect, desired);
}
int	atomic_fcmpset_char(volatile u_char* object, u_char* expected, u_char desired)
{
	MY_FUNINTTHRECHARCHAR func;
	if (g_hDll)
		func = (MY_FUNINTTHRECHARCHAR)GetProcAddress(g_hDll, "atomic_fcmpset_char");
	if (func == NULL)
	{
		return -1;
	}
	return func(object, expected, desired);
}
int	atomic_fcmpset_short(volatile u_short* object, u_short* expected, u_short desired)
{
	MY_FUNINTTHRESHORTSHORT func;
	if (g_hDll)
		func = (MY_FUNINTTHRESHORTSHORT)GetProcAddress(g_hDll, "atomic_fcmpset_short");
	if (func == NULL)
	{
		return -1;
	}
	return func(object, expected, desired);
}
int	atomic_fcmpset_int(volatile u_int* object, u_int* expected, u_int desired)
{
	MY_FUNINTTHREINTINT func;
	if (g_hDll)
		func = (MY_FUNINTTHREINTINT)GetProcAddress(g_hDll, "atomic_fcmpset_int");
	if (func == NULL)
	{
		return -1;
	}
	return func(object, expected, desired);
}
int	atomic_fcmpset_long(volatile u_long* object, u_long* expected, u_long desired)
{
	MY_FUNINTTHRELONGLONG func;
	if (g_hDll)
		func = (MY_FUNINTTHRELONGLONG)GetProcAddress(g_hDll, "atomic_fcmpset_long");
	if (func == NULL)
	{
		return -1;
	}
	return func(object, expected, desired);
}

void atomic_thread_fence_acq(void)
{
	MY_FUNVOID func;
	if (g_hDll)
		func = (MY_FUNVOID)GetProcAddress(g_hDll, "atomic_thread_fence_acq");
	if (func == NULL)
	{
		return;
	}
	return func();
}

void atomic_thread_fence_rel(void)
{
	MY_FUNVOID func;
	if (g_hDll)
		func = (MY_FUNVOID)GetProcAddress(g_hDll, "atomic_thread_fence_acq");
	if (func == NULL)
	{
		return;
	}
	return func();
}

void atomic_thread_fence_acq_rel(void)
{
	MY_FUNVOID func;
	if (g_hDll)
		func = (MY_FUNVOID)GetProcAddress(g_hDll, "atomic_thread_fence_acq_rel");
	if (func == NULL)
	{
		return;
	}
	return func();
}

void atomic_thread_fence_seq_cst(void)
{
	MY_FUNVOID func;
	if (g_hDll)
		func = (MY_FUNVOID)GetProcAddress(g_hDll, "atomic_thread_fence_seq_cst");
	if (func == NULL)
	{
		return;
	}
	return func();
}

void atomic_store_rel_int(volatile u_int* p, u_int v)
{
	MY_FUNVOIDINT func;
	if (g_hDll)
		func = (MY_FUNVOIDINT)GetProcAddress(g_hDll, "atomic_store_rel_int");
	if (func == NULL)
	{
		return;
	}
	return func(p,v);
}
void atomic_store_rel_long(volatile u_long* p, u_long v)
{
	MY_FUNVOIDLONGLONG func;
	if (g_hDll)
		func = (MY_FUNVOIDLONGLONG)GetProcAddress(g_hDll, "atomic_store_rel_long");
	if (func == NULL)
	{
		return;
	}
	return func(p, v);
}
u_long atomic_load_acq_long(volatile u_long* p)
{
	MY_FUNLONG func;
	if (g_hDll)
		func = (MY_FUNLONG)GetProcAddress(g_hDll, "atomic_load_acq_long");
	if (func == NULL)
	{
		return -1;
	}
	return func(p);
}
u_int atomic_load_acq_int(volatile u_int* p)
{
	MY_FUNINT func;
	if (g_hDll)
		func = (MY_FUNINT)GetProcAddress(g_hDll, "atomic_load_acq_int");
	if (func == NULL)
	{
		return -1;
	}
	return func(p);
}
void atomic_subtract_barr_int(volatile u_int* p, u_int val)
{
	MY_FUNVOIDINT func;
	if (g_hDll)
		func = (MY_FUNVOIDINT)GetProcAddress(g_hDll, "atomic_subtract_barr_int");
	if (func == NULL)
	{
		return;
	}
	return func(p,val);
}

u_int atomic_swap_int(volatile u_int* p, u_int v)
{
	MY_FUNINTINT func;
	if (g_hDll)
		func = (MY_FUNINTINT)GetProcAddress(g_hDll, "atomic_swap_int");
	if (func == NULL)
	{
		return -1;
	}
	return func(p, v);
}
u_long	atomic_swap_long(volatile u_long* p, u_long v)
{
	MY_FUNLONGLONGLONG func;
	if (g_hDll)
		func = (MY_FUNLONGLONGLONG)GetProcAddress(g_hDll, "atomic_swap_long");
	if (func == NULL)
	{
		return -1;
	}
	return func(p, v);
}
void atomic_set_long(volatile u_long* p, u_long v)
{
	MY_FUNVOIDLONGLONG func;
	if (g_hDll)
		func = (MY_FUNVOIDLONGLONG)GetProcAddress(g_hDll, "atomic_set_long");
	if (func == NULL)
	{
		return;
	}
	return func(p, v);
}
void atomic_clear_long(volatile u_long* p, u_long v)
{
	MY_FUNVOIDLONGLONG func;
	if (g_hDll)
		func = (MY_FUNVOIDLONGLONG)GetProcAddress(g_hDll, "atomic_clear_long");
	if (func == NULL)
	{
		return;
	}
	return func(p, v);
}

void atomic_set_char(volatile u_char* P, u_char V)
{
	MY_FUNVOIDCHAR func;
	if (g_hDll)
		func = (MY_FUNVOIDCHAR)GetProcAddress(g_hDll, "atomic_set_char");
	if (func == NULL)
	{
		return;
	}
	return func(P,V);
}

void atomic_clear_char(volatile u_char* P, u_char V)
{
	MY_FUNVOIDCHAR func;
	if (g_hDll)
		func = (MY_FUNVOIDCHAR)GetProcAddress(g_hDll, "atomic_clear_char");
	if (func == NULL)
	{
		return;
	}
	return func(P,V);
}
void atomic_subtract_barr_long(volatile u_long* p, u_long val)
{
	MY_FUNVOIDLONGLONG func;
	if (g_hDll)
		func = (MY_FUNVOIDLONGLONG)GetProcAddress(g_hDll, "atomic_subtract_barr_long");
	if (func == NULL)
	{
		return;
	}
	return func(p,val);
}
