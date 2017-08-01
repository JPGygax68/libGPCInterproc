#include <gpcinterproc/lock_free_ringbuffer.hpp>


int main(int argc, char *argv[])
{
    using namespace gpc::interprocess;

    auto rb = Lock_free_ringbuffer::create("ringbuffer_test4", 10000);

    // TODO ...

    return 1;
}