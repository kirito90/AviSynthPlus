#pragma once

#include <avisynth.h>
#include <vector>
#include <atomic>
#include <memory>

class InternalEnvironment;

struct DeviceCompleteCallbackData {
  void(*cb)(void*);
  void* user_data;
};

class Device {
protected:
    InternalEnvironment* env;

public:
    const int device_type;
    const int device_id;
    const int device_index;

    unsigned __int64 memory_max;
    std::atomic<unsigned __int64> memory_used;

    Device(int type, int id, int index, InternalEnvironment* env) :
		  env(env),
      device_type(type),
      device_id(id),
      device_index(index),
		  memory_max(0),
		  memory_used(0)
    { }

    virtual ~Device() { }

    virtual int SetMemoryMax(int mem) = 0;
    virtual BYTE* Allocate(size_t sz) = 0;
    virtual void Free(BYTE* ptr) = 0;
    virtual const char* GetName() const = 0;
    virtual void AddCompleteCallback(DeviceCompleteCallbackData cbdata) = 0;
    virtual std::unique_ptr<std::vector<DeviceCompleteCallbackData>> GetAndClearCallbacks() = 0;
    virtual void SetActiveToCurrentThread(InternalEnvironment* env) = 0;
    virtual void* GetComputeStream() = 0;
};

class DeviceManager {
private:
  InternalEnvironment *env;
  std::unique_ptr<Device> cpuDevice;
  std::vector<std::unique_ptr<Device>> cudaDevices;
  int numDevices;

public:
    DeviceManager(InternalEnvironment* env);
    ~DeviceManager() { }

    Device* GetDevice(int device_type, int device_index);

    Device* GetCPUDevice() { return GetDevice(DEV_TYPE_CPU, 0); }

    int GetNumDevices() const { return numDevices; }
};

void CheckChildDeviceTypes(const PClip& child, const char* name,
  const AVSValue& args, const char* const* argnames, IScriptEnvironment2* env);