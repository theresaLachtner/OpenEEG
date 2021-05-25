#include <wiringPi.h>
#include <mcp3004.h>
#include <iostream>

//values for mcp3004setup
#define BASE 200
#define SPI_CHAN 0

int mcpSetup();
float readValue(int channel);
