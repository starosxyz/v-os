#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>


void atomic_set_int(u_int* P, u_int V)
{
	std::atomic<u_int> value(*P);
	value |= V;
	*P = value.load();
	/*(*(u_int*)(P) |= (V));*/
}