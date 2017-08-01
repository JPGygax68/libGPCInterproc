#include <chrono>
#include <thread>
#include <gpc/interproc/lock_free_ringbuffer.hpp>


int main(int argc, char *argv[])
{
    using namespace gpc::interprocess;

    auto rb = Lock_free_ringbuffer::create("ringbuffer_test", 10000);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    // TODO ...

    return 1;
}
