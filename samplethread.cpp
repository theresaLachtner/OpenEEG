#include "buffermanager.h"
#include "input.h"
#include <math.h>

//for sleep timer (frequency of 156)
#define SECS 0
#define NANOSECS 3875968

void sample_thread()
{
    if (mcpSetup() == -1)
	{
		double data_y;
		perror("Error occured during MCP3008 setup");
	}

    BufferManager* bufferManager = BufferManager::Instance();
    const int bufferSize = BufferManager::BufferSize;
    SampleBuffer sampleBuffer[bufferSize];

    while (true)
    {
        for (int i = 0; i < bufferSize; i++)
        {
            
            sampleBuffer[i].data_x = (float)i;
            sampleBuffer[i].data_y = readValue(0); //sin(2*3.1415*50*((float)i/256))+sin(2*3.1415*3*((float)i/256));//for testing

            // sleep
            timespec req = {SECS, NANOSECS};
            timespec rem = {0, 0};
            if (nanosleep(&req, &rem) == -1)
            {
                nanosleep(&rem, NULL);
                rem = {0,0};
            }
        }
        bufferManager->WriteBuffer(sampleBuffer);
    }   
}