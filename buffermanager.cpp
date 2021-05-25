#include "buffermanager.h"
#include <cstring>

BufferManager::BufferManager() :
    dataAvailable(false)
{}
bool BufferManager::instanceFlag = false;
BufferManager* BufferManager::instance = NULL;

BufferManager* BufferManager::Instance()
{
    if (instanceFlag == false)
    {
        instance = new BufferManager();
        instanceFlag = true;
        return instance;
    }
    else
    {
        return instance;   
    }
}

void BufferManager::WriteBuffer(SampleBuffer* sourceBuffer)
{
    std::lock_guard<std::mutex> lock(this->mutex);

    memcpy(this->buffer, sourceBuffer, sizeof(SampleBuffer) * BufferManager::BufferSize);
    this->dataAvailable = true;
    this->condition.notify_all();
}

void BufferManager::CopyBuffer(SampleBuffer* bufferToCopyTo)
{
    std::unique_lock<std::mutex> lock(this->mutex);
    if (!this->dataAvailable)
    {
        this->condition.wait(lock);
    }
    memcpy(bufferToCopyTo, this->buffer, sizeof(SampleBuffer) * BufferManager::BufferSize);
    this->dataAvailable = false;
}