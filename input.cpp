#include "input.h"

#define DEBUG

//******************************************************************************
//sets up wiringPi and mcp3008
//******************************************************************************
int mcpSetup ()
{
	if(wiringPiSetup() == -1)
	{
		return -1;
	}

    //mcp3004 can be regarded as equal to mcp3004
    if(mcp3004Setup(BASE, SPI_CHAN) == -1)
    {
        return -1;
    } 
	return 0;
}

//******************************************************************************
//reads value from channel given mcp3008 channel
//******************************************************************************
float readValue(int channel)
{
	int channelInput = analogRead(BASE + channel);
	float voltageValue = (float)channelInput/1023.0*5.0;
#ifdef DEBUG
    //printf("DEBUG INPUT.CPP: Channel input = %d\n",channelInput);
    printf("DEBUG INPUT.CPP: Voltage value = %f\n",voltageValue);
#endif
    return voltageValue;
}
