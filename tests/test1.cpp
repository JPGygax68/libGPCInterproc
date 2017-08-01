//#include <cstdlib>
#include <boost/process.hpp>
#include <gpc/interproc/lock_free_ringbuffer.hpp>


int main(int argc, char *argv[])
{
    using namespace boost::process;
    using namespace gpc::interprocess;

    // Run the test server

    //system(argv[1]);
    spawn(argv[1]);

    // Connect to ringbuffer
    auto rb = Lock_free_ringbuffer::open("ringbuffer_test");

    // TODO: perform various tasks

    // TODO: terminate server and verify that it has terminated

    return 1;
}