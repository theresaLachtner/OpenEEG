#include <iostream>
#include <pthread.h>
#include <time.h>
#include <complex>
#include <fftw3.h>
#include <thread>
#include <cstring>

#include "samplethread.h"
#include "workerthread.h"

//Seconds and Nanoseconds for nanosleep function (defines sampling frequency)

#define VALSPERSEC 258
//mcp3008 channel for sampling
#define CHANNEL 0


//******************************************************************************
//------------------------------------------------------------------------------
//MAIN METHOD
//------------------------------------------------------------------------------
//******************************************************************************

int main (int argc, char** argv)
{
	//two threads for sampling and processing
	std::thread sampleThread(sample_thread);
	std::thread workerThread(worker_thread);
	sampleThread.join();
	workerThread.join();



}
