#pragma once
#define USE_LOCKFREE_FIFO
#ifdef USE_LOCKFREE_FIFO
#include "nu/lfmpscq.h"
#else
#include "nu/PtrDeque.h"
#include "nu/AutoLock.h"
#endif
#include <semaphore.h>
#include "foundation/types.h"

#ifdef USE_LOCKFREE_FIFO
typedef queue_node_t fifo_node_t;
#else
typedef nu::PtrDequeNode fifo_node_t;
#endif
struct threadloop_node_t : public fifo_node_t
{
	void (*func)(void *param1, void *param2, double real_value);

	void *param1;
	void *param2;
	double real_value;
};

class ThreadLoop
{
public:
	ThreadLoop();
	~ThreadLoop();
	threadloop_node_t *GetAPC(); // returns a node for you to fill out
	void Schedule(threadloop_node_t *apc);
	void Run();
	void Step();
	void Try();
	void Step(unsigned int milliseconds);
	void uStep(unsigned int microseconds);
	void Kill();
private:
	void RefillCache();

	sem_t procedure_notification;
	volatile size_t kill_switch;
#ifdef USE_LOCKFREE_FIFO
	mpscq_t procedure_queue;
#else
	nu::PtrDeque<threadloop_node_t> procedure_queue;
	nu::LockGuard queue_guard;
#endif
};