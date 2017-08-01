#include <gpc/interproc/lock_free_ringbuffer.hpp>


namespace gpc
{
    namespace interprocess 
    {
        auto Lock_free_ringbuffer::create(String_cref name, size_t size) -> Lock_free_ringbuffer
        {
            auto mem_obj = bi::windows_shared_memory{bi::create_only, name.c_str(), bi::read_write, size};
            
            return Lock_free_ringbuffer{std::move(mem_obj), std::move(std::string{name})};
        }

        auto Lock_free_ringbuffer::open(String_cref name) -> Lock_free_ringbuffer
        {
            auto mem_obj = bi::windows_shared_memory{bi::open_only, name.c_str(), bi::read_only};

            return Lock_free_ringbuffer{std::move(mem_obj), std::move(std::string{name})};
        }

        Lock_free_ringbuffer::~Lock_free_ringbuffer()
        {
            //_mem_obj.remove(_name.c_str());
        }

        Lock_free_ringbuffer::Lock_free_ringbuffer(bi::windows_shared_memory &&shmem, std::string &&name):
            _name{std::move(name)},
            _mem_obj{std::move(shmem)}
        {
        }

    }
}
