#include "ports/port_atomic.h"
#include "staros/so_init.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <stddef.h>
#include <stdint.h>
#include <windows.h>
#include <intrin.h>
#endif
void atomic_barrier()
{
	MemoryBarrier();
}
void atomic_set_int(u_int* P, u_int V)
{
	InterlockedAnd((LONG*)P, (LONG)V);
}
void atomic_clear_int(u_int* P, u_int V)
{
	InterlockedOr((LONG*)P, (LONG)(~V));
}

void atomic_add_int(u_int* P, u_int V) {
	InterlockedExchangeAdd(P, V);
}
void atomic_subtract_int(u_int* P, u_int V)
{
	InterlockedExchangeAdd((LONG *)P, -((LONG)V));
}
void atomic_add_long(unsigned long long* P, unsigned long long V) {
	InterlockedExchangeAdd(P, V);
}
void atomic_subtract_long(unsigned long long* P, unsigned long long V)
{
	InterlockedExchangeAdd64((LONG64 *)P, -((LONG64)V));
}
u_int atomic_fetchsub_int(volatile u_int* p, u_int v)
{
	return InterlockedExchangeAdd((LONG *)p, -(LONG)v);
}
unsigned long long	atomic_fetchsub_long(volatile unsigned long long* p, unsigned long long v)
{
	return InterlockedExchangeAdd64((LONG64*)p, -((LONG64)v));
}
u_int atomic_fetchadd_int(volatile u_int* p, u_int v)
{
	return InterlockedExchangeAdd(p, v);
}
unsigned long long	atomic_fetchadd_long(volatile unsigned long long* p, unsigned long long v)
{
	return InterlockedExchangeAdd(p, v);
}

int	atomic_cmpset_char(volatile u_char* object, u_char expect, u_char desired)
{
	u_char oldvalue = _InterlockedCompareExchange8((char *)object, desired, expect);

	if (expect == oldvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int	atomic_cmpset_short(volatile u_short* dst, u_short expect, u_short desired)
{
	u_short oldvalue = _InterlockedCompareExchange16((SHORT*)dst, desired, expect);

	if (expect == oldvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int	atomic_cmpset_int(volatile u_int* dst, u_int expect, u_int desired)
{
	u_int oldvalue = InterlockedCompareExchange(dst, desired, expect);

	if (expect == oldvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int	atomic_cmpset_long(volatile unsigned long long* dst, unsigned long long expect, unsigned long long desired)
{
	LONG64 oldvalue = InterlockedCompareExchange64((LONG64 *)dst, desired, expect);

	if (expect == oldvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int	atomic_fcmpset_char(volatile u_char* object, u_char* expected, u_char desired)
{
	u_char old = *expected;
	u_char oldvalue = _InterlockedCompareExchange8((char *)object, desired, old);

	if (old == oldvalue)
	{
		return 1;
	}
	else
	{
		_InterlockedExchange8((CHAR *)expected, old);
		return 0;
	}
}
int	atomic_fcmpset_short(volatile u_short* object, u_short* expected, u_short desired)
{
	SHORT old = *expected;
	SHORT oldvalue = _InterlockedCompareExchange16((SHORT*)object, desired, old);

	if (old == oldvalue)
	{
		return 1;
	}
	else
	{
		_InterlockedExchange16((SHORT*)expected, old);
		return 0;
	}
}
int	atomic_fcmpset_int(volatile u_int* object, u_int* expected, u_int desired)
{
	u_int old = *expected;
	u_int oldvalue = InterlockedCompareExchange((u_int*)object, desired, old);

	if (old == oldvalue)
	{
		return 1;
	}
	else
	{
		InterlockedExchange((u_int*)expected, old);
		return 0;
	}
}
int	atomic_fcmpset_long(volatile unsigned long long* object, unsigned long long* expected, unsigned long long desired)
{
	LONG64 old = *expected;
	LONG64 oldvalue = InterlockedCompareExchange64((LONG64*)object, desired, old);

	if (old == oldvalue)
	{
		return 1;
	}
	else
	{
		InterlockedExchange64((LONG64*)expected, old);
		return 0;
	}
}
int	atomic_fcmpset_pointer(volatile unsigned long long* object, unsigned long long* expected, unsigned long long desired)
{
	LONG64 old = *expected;
	LONG64 oldvalue = InterlockedCompareExchange64((LONG64*)object, desired, old);

	if (old == oldvalue)
	{
		return 1;
	}
	else
	{
		InterlockedExchange64((LONG64*)expected, old);
		return 0;
	}
}

void
atomic_thread_fence_acq(void)
{
	std::atomic_thread_fence(std::memory_order_acquire);
}

void
atomic_thread_fence_rel(void)
{
	std::atomic_thread_fence(std::memory_order_release);

}

void
atomic_thread_fence_acq_rel(void)
{

	std::atomic_thread_fence(std::memory_order_acq_rel);
}

void
atomic_thread_fence_seq_cst(void)
{
	std::atomic_thread_fence(std::memory_order_seq_cst);

}
void atomic_add_barr_long(unsigned long long* P, unsigned long long V)
{
	InterlockedExchangeAddAcquire(P, V);
}
void atomic_add_barr_int(u_int* P, u_int V) {
	InterlockedExchangeAddAcquire(P, V);
}
void
atomic_store_rel_int(volatile u_int* p, u_int v)
{
	*(u_int*)(p) = v;
	MemoryBarrier();
}
void
atomic_store_rel_long(volatile unsigned long long* p, unsigned long long v)
{
	*(unsigned long long*)(p) = v;
	MemoryBarrier();
}
unsigned long long
atomic_load_acq_long(volatile unsigned long long* p)
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

u_int atomic_swap_int(volatile u_int* p, u_int v)
{
	return InterlockedExchange(p, v);
}
unsigned long long atomic_swap_long(volatile unsigned long long* p, unsigned long long v)
{
	return InterlockedExchange(p, v);
}
void atomic_set_long(volatile unsigned long long* p, unsigned long long v)
{
	InterlockedOr(p, v);
}
void atomic_clear_long(unsigned long long* p, unsigned long long v)
{
	InterlockedAnd(p, ~(v));
}
void atomic_set_char(u_char* P, u_char V)
{
	std::atomic<u_char> value(*P);
	value |= V;
	*P = value.load();
}
void atomic_clear_char(u_char* P, u_char V)
{
	std::atomic<u_char> value(*P);
	value &= ~(V);
	*P = value.load();
}
void atomic_subtract_barr_long(volatile unsigned long long* p, unsigned long long val)
{
	InterlockedExchangeAddAcquire64((LONG64*)p, -((LONG64)val));
}


char sync_atomic_fetchadd_char(volatile char* p, char v)
{
	return _InterlockedExchangeAdd8(p,v);
}
int sync_atomic_fetchadd_int(volatile int* p, int v) {
	return InterlockedExchangeAdd((u_int*)p, (u_int)v);
}
u_int sync_atomic_fetchadd_uint(volatile u_int* p, u_int v) {
	return InterlockedExchangeAdd((u_int*)p, (u_int)v);
}
unsigned long long sync_atomic_fetchadd_long(volatile unsigned long long* p, unsigned long long v) {
	return InterlockedExchangeAdd(p, v);
}
uint8_t sync_atomic_fetchadd_8(volatile uint8_t* p, uint8_t v) {
	return _InterlockedExchangeAdd8((char *)p, (char)v);
}
uint16_t sync_atomic_fetchadd_16(volatile uint16_t* p, uint16_t v) {
	return _InterlockedExchangeAdd16((short *)p, (short)v);
}
uint32_t sync_atomic_fetchadd_32_pfn(volatile uint32_t* p, uint32_t v) {
	return InterlockedExchangeAdd(p, v);
}
uint64_t sync_atomic_fetchadd_64_pfn(volatile uint64_t* p, uint64_t v) {
	return InterlockedExchangeAdd(p, v);
}
void* sync_atomic_fetchadd_ptr(volatile void* p, void* v) {
	return (void *)InterlockedExchangeAdd64((LONG64*)p, (uint64_t)v);
}

char sync_atomic_fetchsub_char(volatile char* p, char v) {
	return _InterlockedExchangeAdd8((char*)p, (char)(-1 * v));
}
int sync_atomic_fetchsub_int(volatile int* p, int v) {
	return InterlockedExchangeAdd((LONG*)p, (LONG)(-1 * v));
}
u_int sync_atomic_fetchsub_uint(volatile u_int* p, u_int v) {
	return InterlockedExchangeAdd((LONG*)p, (LONG)(-1 * v));
}
unsigned long long sync_atomic_fetchsub_long(volatile unsigned long long* p, unsigned long long v) {
	return InterlockedExchangeAdd64((LONG64*)p, (LONG64)(-1 * v));
}
uint8_t sync_atomic_fetchsub_8(volatile uint8_t* p, uint8_t v) {
	return _InterlockedExchangeAdd8((char*)p, (char)(-1 * v));
}
uint16_t sync_atomic_fetchsub_16(volatile uint16_t* p, uint16_t v) {
	return _InterlockedExchangeAdd16((SHORT*)p, (SHORT)(-1 * v));
}
uint32_t sync_atomic_fetchsub_32_pfn(volatile uint32_t* p, uint32_t v) {
	return InterlockedExchangeAdd((LONG*)p, (LONG)(-1 * v));
}
uint64_t sync_atomic_fetchsub_64_pfn(volatile uint64_t* p, uint64_t v) {
	return InterlockedExchangeAdd64((LONG64 *)p, (LONG64)(-1 * v));
}
void* sync_atomic_fetchsub_ptr(volatile void* p, void* v) {
	std::atomic<uint64_t> value((uint64_t)&p);
	uint64_t nret = value.fetch_sub((uint64_t)v);

	*(uint64_t*)p = value.load();
	return (void*)nret;
}


char sync_atomic_fetchand_char(volatile char* p, char v) {
	return InterlockedAnd8((char*)p, v);
}
int sync_atomic_fetchand_int(volatile int* p, int v) {
	return InterlockedAnd((LONG*)p, v);
}
u_int sync_atomic_fetchand_uint(volatile u_int* p, u_int v) {
	return InterlockedAnd((LONG *)p, v);
}
unsigned long long sync_atomic_fetchand_long(volatile unsigned long long* p, unsigned long long v) {
	return InterlockedAnd(p, v);
}
uint8_t sync_atomic_fetchand_8(volatile uint8_t* p, uint8_t v) {
	return InterlockedAnd8((char*)p, v);
}
uint16_t sync_atomic_fetchand_16(volatile uint16_t* p, uint16_t v) {
	return InterlockedAnd16((SHORT*)p, v);
}
uint32_t sync_atomic_fetchand_32_pfn(volatile uint32_t* p, uint32_t v) {
	return InterlockedAnd((LONG*)p, v);
}
uint64_t sync_atomic_fetchand_64_pfn(volatile uint64_t* p, uint64_t v) {
	return InterlockedAnd((uint64_t*)p, v);
}
void* sync_atomic_fetchand_ptr(volatile void* p, void* v) {
	std::atomic<uint64_t> value((uint64_t)&p);
	uint64_t nret = value.fetch_and((uint64_t)v);

	*(uint64_t*)p = value.load();
	return (void*)nret;
}

char sync_atomic_fetchor_char(volatile char* p, char v) {
	return InterlockedOr8((char*)p, v);
}
int sync_atomic_fetchor_int(volatile int* p, int v) {
	return InterlockedOr((LONG*)p, v);
}
u_int sync_atomic_fetchor_uint(volatile u_int* p, u_int v) {
	return InterlockedOr((LONG *)p, v);
}
unsigned long long sync_atomic_fetchor_long(volatile unsigned long long* p, unsigned long long v) {
	return InterlockedOr(p, v);
}
uint8_t sync_atomic_fetchor_8(volatile uint8_t* p, uint8_t v) {
	return InterlockedOr8((char*)p, v);
}
uint16_t sync_atomic_fetchor_16(volatile uint16_t* p, uint16_t v) {
	return InterlockedOr16((SHORT*)p, v);
}
uint32_t sync_atomic_fetchor_32_pfn(volatile uint32_t* p, uint32_t v) {
	return InterlockedOr((LONG *)p, v);
}
uint64_t sync_atomic_fetchor_64_pfn(volatile uint64_t* p, uint64_t v) {
	return InterlockedOr((uint64_t*)p, v);
}
void* sync_atomic_fetchor_ptr(volatile void* p, void* v) {
	std::atomic<uint64_t> value((uint64_t)&p);
	uint64_t nret = value.fetch_or((uint64_t)v);

	*(uint64_t*)p = value.load();
	return (void*)nret;
}

char sync_atomic_fetchxor_char(volatile char* p, char v) {
	return _InterlockedXor8((char*)p, v);
}
int sync_atomic_fetchxor_int(volatile int* p, int v) {
	return InterlockedXor((LONG*)p, v);
}
u_int sync_atomic_fetchxor_uint(volatile u_int* p, u_int v) {
	return InterlockedXor((LONG *)p, v);
}
unsigned long long sync_atomic_fetchxor_long(volatile unsigned long long* p, unsigned long long v) {
	return InterlockedXor(p, v);
}
uint8_t sync_atomic_fetchxor_8(volatile uint8_t* p, uint8_t v) {
	return _InterlockedXor8((char*)p, v);
}
uint16_t sync_atomic_fetchxor_16(volatile uint16_t* p, uint16_t v) {
	return _InterlockedXor16((SHORT *)p, v);
}
uint32_t sync_atomic_fetchxor_32_pfn(volatile uint32_t* p, uint32_t v) {
	return InterlockedXor((LONG *)p, v);
}
uint64_t sync_atomic_fetchxor_64_pfn(volatile uint64_t* p, uint64_t v) {
	return InterlockedXor(p, v);
}
void* sync_atomic_fetchxor_ptr(volatile void* p, void* v) {
	return NULL;
}

int sync_bool_compare_and_swap_char(char* ptr, char compare, char set) {
	uint8_t oldvalue = _InterlockedCompareExchange8((char*)ptr, set, compare);

	if (compare == oldvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
char sync_val_compare_and_swap_char(char* ptr, char compare, char set) {
	return _InterlockedCompareExchange8((char*)ptr, set, compare);;
}
int sync_bool_compare_and_swap_int(int* ptr, int compare, int set) {
	unsigned int oldvalue = InterlockedCompareExchange((unsigned int*)ptr, set, compare);

	if (compare == oldvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int sync_val_compare_and_swap_int(int* ptr, int compare, int set) {
	return InterlockedCompareExchange((unsigned int *)ptr, set, compare);
}
unsigned int sync_bool_compare_and_swap_uint(unsigned int* ptr, unsigned int compare, unsigned int set) {
	unsigned int oldvalue = InterlockedCompareExchange(ptr, set, compare);

	if (compare == oldvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
unsigned int sync_val_compare_and_swap_uint(unsigned int* ptr, unsigned int compare, unsigned int set) {
	return InterlockedCompareExchange(ptr, set, compare);
}
int sync_bool_compare_and_swap_8(uint8_t* ptr, uint8_t compare, uint8_t set) {
	uint8_t oldvalue = _InterlockedCompareExchange8((char*)ptr, set, compare);

	if (compare == oldvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
uint8_t sync_val_compare_and_swap_8(uint8_t* ptr, uint8_t compare, uint8_t set) {
	return _InterlockedCompareExchange8((char*)ptr, set, compare);
}
int sync_bool_compare_and_swap_16(uint16_t* ptr, uint16_t compare, uint16_t set) {
	uint16_t oldvalue = InterlockedCompareExchange16((SHORT*)ptr, set, compare);

	if (compare == oldvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
uint16_t sync_val_compare_and_swap_16(uint16_t* ptr, uint16_t compare, uint16_t set) {
	return InterlockedCompareExchange16((SHORT*)ptr, set, compare);
}
int sync_bool_compare_and_swap_32(uint32_t* ptr, uint32_t compare, uint32_t set) {
	uint32_t oldvalue = InterlockedCompareExchange(ptr, set, compare);

	if (compare == oldvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
uint32_t sync_val_compare_and_swap_32(uint32_t* ptr, uint32_t compare, uint32_t set) {
	return InterlockedCompareExchange(ptr, set, compare);
}
int sync_bool_compare_and_swap_64(uint64_t* ptr, uint64_t compare, uint64_t set) {

	uint64_t oldvalue = InterlockedCompareExchange(ptr, set, compare);

	if (compare == oldvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
uint64_t sync_val_compare_and_swap_64(uint64_t* ptr, uint64_t compare, uint64_t set) {
	return InterlockedCompareExchange(ptr, set, compare);
}
int  sync_bool_compare_and_swap_ptr(void* ptr, void* compare, void* set) {
	PVOID oldvalue = InterlockedCompareExchangePointer((PVOID*)&ptr, set, compare);

	if (compare == oldvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void* sync_val_compare_and_swap_ptr(void* ptr, void* compare, void* set) {
	return InterlockedCompareExchangePointer((PVOID*)&ptr, set, compare);
}

int	atomic_testandset_int(volatile u_int* p, u_int v)
{
	return InterlockedBitTestAndSet((LONG *)p, (LONG)v);
}
int	atomic_testandset_long(volatile u_long* p, u_int v)
{
	return InterlockedBitTestAndSet64((LONG64*)p, (LONG64)v);
}
int	atomic_testandclear_int(volatile u_int* p, u_int v)
{
	return InterlockedBitTestAndReset((LONG*)p, (LONG)v);
}
int	atomic_testandclear_long(volatile u_long* p, u_int v)
{
	return InterlockedBitTestAndReset64((LONG64*)p, (LONG64)v);
}