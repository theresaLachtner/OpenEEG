#include "buffermanager.h"
#include <iostream>
#include "fft.h"
#include <fftw3.h>
#include <time.h>
#include <fstream>


void worker_thread()
{
    BufferManager* bufferManager = BufferManager::Instance();
    const int bufferSize = BufferManager::BufferSize;
    SampleBuffer processingBuffer[bufferSize];

    double in[256];
	fftw_complex out[256];
    double alpha;
    double beta;
    double delta;
    double theta;
    long long filecounter = 0;

    std::ofstream myFile("data.csv", std::ios::app);

    myFile << "x_value,total_1\n";

    myFile.close();


    // will becomce some kind of endless loop
    while(true)
    {
        time_t start, end;

        start = clock();
        bufferManager->CopyBuffer(processingBuffer);

        for (int i = 0; i < 256; i++)
        {
            in[i]= processingBuffer[i].data_y;
        }
        fft(in, out);

        for (int i = 1; i < 8; i++)
        {
            delta += out[i][0];
        }
        for (int i = 8; i < 15; i++)
        {
            theta += out[i][0];
        }
        for (int i = 15; i < 26; i++)
        {
            alpha += out[i][0];
        }
        for (int i = 26; i < 90; i++)
        {
            
            alpha += out[i][0];
        }

        //removes 50Hz noise
        for (int i = 45; i < 55; i++)
        {
            out[i][0]=0;
            out[i][1]=0;
        }

        ifft(out, in);
        for (int i = 0; i < 128; i++)
        {
            std::cout << out[i][0] << std::endl;
        }
        std::cout << alpha <<"  " <<beta <<"  "<< delta <<"  "<< theta << "\n\n";
        std::ofstream myFile("data.csv", std::ios::app);
        for(int i = 0; i < 256 ; i++)
        {
            myFile << (double)filecounter/256 << ',' << in[i] << std::endl;
            filecounter++;
        }
        myFile.close();
    }
}