
#include <sys/cdefs.h>
#include <sys/types.h>
#include <ck_atomic.h>
#include <machine/atomic.h>
#include "context.h"
#define WIN32_LEAN_AND_MEAN
#include <stddef.h>
#include <stdint.h>
#include <windows.h>
#include <intrin.h>

int
atomic_testandset_long(volatile u_long* p, u_long v)
{
	return _interlockedbittestandset64(p, (LONG64)v);
}


int
atomic_testandclear_long(volatile u_long* p, u_long v)
{
	return _interlockedbittestandreset64(p, (LONG64)v);
}
void atomic_add_barr_int(volatile u_int* P, u_int V)
{
	InterlockedExchangeAddAcquire(P, V);
}
void atomic_add_barr_long(volatile u_long* P, u_long V)
{
	InterlockedExchangeAddAcquire64(P, V);
}
void atomic_set_int(volatile u_int* P, u_int V)
{
	InterlockedAnd(P, V);
}
void atomic_clear_int(volatile u_int* P, u_int V)
{
	InterlockedOr(P, ~V);
}

void atomic_add_int(volatile u_int* P, u_int V) {
	InterlockedExchangeAdd(P, V);
}
void atomic_subtract_int(volatile u_int* P, u_int V)
{
	InterlockedExchangeAdd(P, -((LONG)V));
}
void atomic_add_long(volatile u_long* P, u_long V) {
	InterlockedExchangeAdd64(P, V);
}
void atomic_subtract_long(volatile u_long* P, u_long V)
{
	InterlockedExchangeAdd64(P, -((LONG64)V));
}

u_int atomic_fetchadd_int(volatile u_int* p, u_int v)
{
	return InterlockedExchangeAdd(p, v);
}
u_long	atomic_fetchadd_long(volatile u_long* p, u_long v)
{
	return InterlockedExchangeAdd64(p, v);
}

u_int	atomic_fetchsub_int(volatile u_int* p, u_int v)
{
	return InterlockedExchangeAdd(p, -((LONG)v));
}
u_long	atomic_fetchsub_long(volatile u_long* p, u_long v)
{
	return InterlockedExchangeAdd64(p, -((LONG64)v));
}

int	atomic_cmpset_char(volatile u_char* object, u_char expect, u_char desired)
{
	u_char oldvalue = _InterlockedCompareExchange8(object, desired, expect);

	if (desired == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int	atomic_cmpset_short(volatile u_short* dst, u_short expect, u_short desired)
{
	u_short oldvalue = InterlockedCompareExchange16(dst, desired, expect);

	if (desired == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int	atomic_cmpset_int(volatile u_int* dst, u_int expect, u_int desired)
{
	u_int oldvalue = InterlockedCompareExchange(dst, desired, expect);

	if (desired == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int	atomic_cmpset_long(volatile u_long* dst, u_long expect, u_long desired)
{
	u_long oldvalue = InterlockedCompareExchange64(dst, desired, expect);

	if (desired == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int	atomic_fcmpset_char(volatile u_char* object, u_char* expected, u_char desired)
{
	u_char old = *expected;
	u_char oldvalue = _InterlockedCompareExchange8(object, desired, old);

	if (desired == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int	atomic_fcmpset_short(volatile u_short* object, u_short* expected, u_short desired)
{
	u_short old = *expected;

	u_short oldvalue = InterlockedCompareExchange16(object, desired, old);

	if (desired == oldvalue)
	{
		*expected = *object;
		return 0;
	}
	else
	{
		return 1;
	}
}
int	atomic_fcmpset_int(volatile u_int* object, u_int* expected, u_int desired)
{
	u_int old = *expected;

	u_int oldvalue = InterlockedCompareExchange(object, desired, old);

	if (desired == oldvalue)
	{
		*expected = *object;
		return 0;
	}
	else
	{
		return 1;
	}
}
int	atomic_fcmpset_long(volatile u_long* object, u_long* expected, u_long desired)
{
	u_long old = *expected;

	u_long oldvalue=InterlockedCompareExchange64(object, desired, old);

	if (desired == oldvalue)
	{
		*expected = *object;
		return 0;
	}
	else
	{
		return 1;
	}

}

void
atomic_thread_fence_acq(void)
{

	MemoryBarrier();
}

void
atomic_thread_fence_rel(void)
{

	MemoryBarrier();
}

void
atomic_thread_fence_acq_rel(void)
{
	MemoryBarrier();

}

void
atomic_thread_fence_seq_cst(void)
{

	MemoryBarrier();
}

void
atomic_store_rel_int(volatile u_int* p, u_int v)
{
	*(u_int*)(p) = v;
	MemoryBarrier();
}
void
atomic_store_rel_long(volatile u_long* p, u_long v)
{
	*(u_long*)(p) = v;
	MemoryBarrier();
}
u_long
atomic_load_acq_long(volatile u_long* p)
{
	MemoryBarrier();
	return *(p);
}
u_int
atomic_load_acq_int(volatile u_int* p)
{
	MemoryBarrier();
	return *(p);
}
void atomic_subtract_barr_int(volatile u_int* p, u_int val)
{
	InterlockedExchangeAddAcquire((LONG*)p, -((LONG)val));
}

u_int	atomic_swap_int(volatile u_int* p, u_int v)
{
	return InterlockedExchange(p, v);
}
u_long	atomic_swap_long(volatile u_long* p, u_long v)
{
	return InterlockedExchange64(p, v);
}
void
atomic_set_long(volatile u_long* p, u_long v)
{
	InterlockedOr64(p,v);
}
void atomic_clear_long(volatile u_long* p, u_long v)
{
	InterlockedAnd64(p, ~(v));
}
void atomic_set_char(volatile u_char* P, u_char V)
{
	(*(u_char*)(P) |= (V));
	MemoryBarrier();
}
void atomic_clear_char(volatile u_char* P, u_char V)
{
	(*(u_char*)(P) &= ~(V));
	MemoryBarrier();
}
void atomic_subtract_barr_long(volatile u_long* p, u_long val)
{
	InterlockedExchangeAddAcquire64((LONG64*)p, -((LONG64)val));
}
#include <ck_atomic.h>
#include "compat/context.h"
#include "compat/win32_include.h"
extern so_atomic_hooks global_atomic_hooks;


char ck_atomi_sync_fetch_and_add_char(char* ptr, char value)
{
	return _InterlockedExchangeAdd8(ptr, value);
}
char ck_atomi_sync_fetch_and_sub_char(char* ptr, char value)
{
	return _InterlockedExchangeAdd8(ptr, -value);
}
char ck_atomi_sync_fetch_and_or_char(char* ptr, char value)
{
	return _InterlockedOr8(ptr, value);
}
char ck_atomi_sync_fetch_and_and_char(char* ptr, char value)
{
	return _InterlockedAnd8(ptr, value);
}
char ck_atomi_sync_fetch_and_xor_char(char* ptr, char value)
{
	return _InterlockedXor8(ptr, value);
}

bool ck_atomi_sync_bool_compare_and_swap_char(char* ptr, char compare, char set)
{
	u_char oldvalue = _InterlockedCompareExchange8(ptr, set, compare);

	if (set == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
char ck_atomi_sync_val_compare_and_swap_char(char* ptr, char compare, char set)
{
	return _InterlockedCompareExchange8(ptr, set, compare);
}

unsigned int ck_atomi_sync_fetch_and_add_uint(unsigned int* ptr, unsigned int value)
{
	return _InterlockedExchangeAdd(ptr, value);
}
unsigned int ck_atomi_sync_fetch_and_sub_uint(unsigned int* ptr, unsigned int value)
{
	return _InterlockedExchangeAdd(ptr, -((LONG)value));
}
unsigned int ck_atomi_sync_fetch_and_or_uint(unsigned int* ptr, unsigned int value)
{
	return _InterlockedOr(ptr, value);
}
unsigned int ck_atomi_sync_fetch_and_and_uint(unsigned int* ptr, unsigned int value)
{
	return _InterlockedAnd(ptr, value);
}
unsigned int ck_atomi_sync_fetch_and_xor_uint(unsigned int* ptr, unsigned int value)
{
	return _InterlockedXor(ptr, value);
}

bool ck_atomi_sync_bool_compare_and_swap_uint(unsigned int* ptr, unsigned int compare, unsigned int set)
{
	unsigned int oldvalue = (unsigned int)_InterlockedCompareExchange(ptr, set, compare);

	if (set == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
unsigned int ck_atomi_sync_val_compare_and_swap_uint(unsigned int* ptr, unsigned int compare, unsigned int set)
{
	return (unsigned int)_InterlockedCompareExchange(ptr, set, compare);
}


int ck_atomi_sync_fetch_and_add_int(int* ptr, int value)
{
	return _InterlockedExchangeAdd(ptr, value);
}
int ck_atomi_sync_fetch_and_sub_int(int* ptr, int value)
{
	return _InterlockedExchangeAdd(ptr, -((LONG)value));
}
int ck_atomi_sync_fetch_and_or_int(int* ptr, int value)
{
	return _InterlockedOr(ptr, value);
}
int ck_atomi_sync_fetch_and_and_int(int* ptr, int value)
{
	return _InterlockedAnd(ptr, value);
}
int ck_atomi_sync_fetch_and_xor_int(int* ptr, int value)
{
	return _InterlockedXor(ptr, value);
}
bool ck_atomi_sync_bool_compare_and_swap_int(int* ptr, int compare, int set)
{
	int oldvalue = (int)_InterlockedCompareExchange(ptr, set, compare);

	if (set == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int ck_atomi_sync_val_compare_and_swap_int(int* ptr, int compare, int set)
{
	return (int)_InterlockedCompareExchange(ptr, set, compare);
}

uint64_t ck_atomi_sync_fetch_and_add_64(uint64_t* ptr, uint64_t value)
{
	return (uint64_t)_InterlockedExchangeAdd64(ptr, value);
}
uint64_t ck_atomi_sync_fetch_and_sub_64(uint64_t* ptr, uint64_t value)
{
	return (uint64_t)_InterlockedExchangeAdd64(ptr, -((LONG64)value));
}
uint64_t ck_atomi_sync_fetch_and_or_64(uint64_t* ptr, uint64_t value)
{
	return _InterlockedOr64(ptr, value);
}
uint64_t ck_atomi_sync_fetch_and_and_64(uint64_t* ptr, uint64_t value)
{
	return _InterlockedAnd64(ptr, value);
}
uint64_t ck_atomi_sync_fetch_and_xor_64(uint64_t* ptr, uint64_t value)
{
	return _InterlockedXor64(ptr, value);
}

bool ck_atomi_sync_bool_compare_and_swap_64(uint64_t* ptr, uint64_t compare, uint64_t set)
{
	uint64_t oldvalue = (uint64_t)_InterlockedCompareExchange64(ptr, set, compare);

	if (set == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
uint64_t ck_atomi_sync_val_compare_and_swap_64(uint64_t* ptr, uint64_t compare, uint64_t set)
{
	return (uint64_t)_InterlockedCompareExchange64(ptr, set, compare);
}

uint32_t ck_atomi_sync_fetch_and_add_32(uint32_t* ptr, uint32_t value)
{
	return (uint32_t)_InterlockedExchangeAdd(ptr, value);
}
uint32_t ck_atomi_sync_fetch_and_sub_32(uint32_t* ptr, uint32_t value)
{
	return (uint32_t)_InterlockedExchangeAdd(ptr, value);
}
uint32_t ck_atomi_sync_fetch_and_or_32(uint32_t* ptr, uint32_t value)
{
	return (uint32_t)_InterlockedOr(ptr, value);
}
uint32_t ck_atomi_sync_fetch_and_and_32(uint32_t* ptr, uint32_t value)
{
	return (uint32_t)_InterlockedAnd(ptr, value);
}
uint32_t ck_atomi_sync_fetch_and_xor_32(uint32_t* ptr, uint32_t value)
{
	return (uint32_t)_InterlockedXor(ptr, value);
}

bool ck_atomi_sync_bool_compare_and_swap_32(uint32_t* ptr, uint32_t compare, uint32_t set)
{
	uint32_t oldvalue = (uint32_t)_InterlockedCompareExchange(ptr, set, compare);

	if (set == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
uint32_t ck_atomi_sync_val_compare_and_swap_32(uint32_t* ptr, uint32_t compare, uint32_t set)
{
	return (uint32_t)_InterlockedCompareExchange(ptr, set, compare);
}
uint16_t ck_atomi_sync_fetch_and_add_16(uint16_t* ptr, uint16_t value)
{
	return (uint16_t)_InterlockedExchangeAdd16(ptr, value);
}
uint16_t ck_atomi_sync_fetch_and_sub_16(uint16_t* ptr, uint16_t value)
{
	return (uint16_t)_InterlockedExchangeAdd16(ptr, -((short)value));
}
uint16_t ck_atomi_sync_fetch_and_or_16(uint16_t* ptr, uint16_t value)
{
	return (uint16_t)_InterlockedOr16(ptr, value);
}
uint16_t ck_atomi_sync_fetch_and_and_16(uint16_t* ptr, uint16_t value)
{
	return (uint16_t)_InterlockedAnd16(ptr, value);
}
uint16_t ck_atomi_sync_fetch_and_xor_16(uint16_t* ptr, uint16_t value)
{
	return (uint16_t)_InterlockedXor16(ptr, value);
}

bool ck_atomi_sync_bool_compare_and_swap_16(uint16_t* ptr, uint16_t compare, uint16_t set)
{
	uint16_t oldvalue = (uint16_t)_InterlockedCompareExchange16(ptr, set, compare);

	if (set == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
uint16_t ck_atomi_sync_val_compare_and_swap_16(uint16_t* ptr, uint16_t compare, uint16_t set)
{
	return (uint16_t)_InterlockedCompareExchange16(ptr, set, compare);
}


uint8_t ck_atomi_sync_fetch_and_add_8(uint8_t* ptr, uint8_t value)
{
	return (uint8_t)_InterlockedExchangeAdd8(ptr, value);
}
uint8_t ck_atomi_sync_fetch_and_sub_8(uint8_t* ptr, uint8_t value)
{
	return (uint8_t)_InterlockedExchangeAdd8(ptr, -((char)value));
}
uint8_t ck_atomi_sync_fetch_and_or_8(uint8_t* ptr, uint8_t value)
{
	return (uint8_t)_InterlockedOr8(ptr, value);
}
uint8_t ck_atomi_sync_fetch_and_and_8(uint8_t* ptr, uint8_t value)
{
	return (uint8_t)_InterlockedAnd8(ptr, value);
}
uint8_t ck_atomi_sync_fetch_and_xor_8(uint8_t* ptr, uint8_t value)
{
	return (uint8_t)_InterlockedXor8(ptr, value);
}

bool ck_atomi_sync_bool_compare_and_swap_8(uint8_t* ptr, uint8_t compare, uint8_t set)
{
	uint8_t oldvalue = (uint8_t)_InterlockedCompareExchange8(ptr, set, compare);

	if (set == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
uint8_t ck_atomi_sync_val_compare_and_swap_8(uint8_t* ptr, uint8_t compare, uint8_t set)
{
	return (uint8_t)_InterlockedCompareExchange8(ptr, set, compare);
}
void* ck_atomi_sync_fetch_and_add_ptr(void* ptr, void* value)
{
	return (void*)_InterlockedExchangeAdd64(ptr, (LONG64)value);
}
void* ck_atomi_sync_fetch_and_sub_ptr(void* ptr, void* value)
{
	return (void*)_InterlockedExchangeAdd64(ptr, -((LONG64)value));
}
void* ck_atomi_sync_fetch_and_or_ptr(void* ptr, void* value)
{
	return NULL;
}
void* ck_atomi_sync_fetch_and_and_ptr(void* ptr, void* value)
{
	return NULL;
}
void* ck_atomi_sync_fetch_and_xor_ptr(void* ptr, void* value)
{
	return NULL;
}
bool ck_atomi_sync_bool_compare_and_swap_ptr(void* ptr, void* compare, void* set)
{
	void* oldvalue = (void*)InterlockedCompareExchangePointer(ptr, set, compare);

	if (set == oldvalue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void* ck_atomi_sync_val_compare_and_swap_ptr(void* ptr, void* compare, void* set)
{
	return NULL;
}