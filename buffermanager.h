#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H

#include "samplebuffer.h"
#include <mutex>
#include <condition_variable>

class BufferManager
{
private:
    SampleBuffer buffer[256];
    static BufferManager* instance;
    std::mutex mutex;
    std::condition_variable condition;
    bool dataAvailable;
    BufferManager();
    static bool instanceFlag;

public:
    ~BufferManager()
    {
        instanceFlag = false;
    }
    void WriteBuffer(SampleBuffer* buffer);
    void CopyBuffer(SampleBuffer* bufferToCopyTo);

    static BufferManager* Instance();
    static const int BufferSize = 256;
};

#endif