// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

void
SimpleThread(_int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
	printf("*** thread %d looped %d times  priority: %d\n", (int) which, num,currentThread->getPriority());
        currentThread->Yield();
    }
}

//----------------------------------------------------------------------
// ThreadTest
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest()
{
    DEBUG('t', "Entering SimpleTest");

    // Thread *t = new Thread("forked thread");
    Thread *t = new Thread("1");      //根据重新定义的thread函数，规定线程1优先级默认为6
    Thread *t2 = new Thread("2",1);     //线程2的优先级为1
    Thread *t3 = new Thread("3",3);     //thread3 priority is 3


    t->Fork(SimpleThread, 1);
    t2->Fork(SimpleThread, 2);
    t3->Fork(SimpleThread, 3);

    // SimpleThread(0);
}

