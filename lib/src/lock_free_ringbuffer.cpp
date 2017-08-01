#include <gpcinterproc/lock_free_ringbuffer.hpp>

namespace gpc
{
    namespace interprocess 
    {
        auto Lock_free_ringbuffer::create(String_cref name, size_t) -> Lock_free_ringbuffer
        {
            auto mem_obj = bi::shared_memory_object{bi::create_only, name.c_str(), bi::read_write};
            
            Lock_free_ringbuffer rb{std::move(mem_obj), std::move(std::string{name})};
            
            return std::move(rb);
        }

        Lock_free_ringbuffer::~Lock_free_ringbuffer()
        {
            _mem_obj.remove(_name.c_str());
        }

        Lock_free_ringbuffer::Lock_free_ringbuffer(bi::shared_memory_object &&shmem, std::string &&name):
            _name{std::move(name)},
            _mem_obj{std::move(shmem)}
        {
        }

    }
}
