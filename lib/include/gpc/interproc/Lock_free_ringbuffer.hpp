#pragma once

#include <cstdint>
#include <utility>
#include <string>
//#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/windows_shared_memory.hpp>


namespace gpc
{
    namespace interprocess
    {
        enum Queue_user_type { producer = 1, consumer };

        namespace bi = boost::interprocess;


        class Lock_free_ringbuffer
        {
        public:
            using String_cref = const std::string &;
            
            static auto create(String_cref name, size_t) -> Lock_free_ringbuffer;
            static auto open  (String_cref name) -> Lock_free_ringbuffer;

            Lock_free_ringbuffer(Lock_free_ringbuffer &&) = default;
            Lock_free_ringbuffer(const Lock_free_ringbuffer &) = delete;
            ~Lock_free_ringbuffer();

            // Producer
            auto start_enqueuing(uint64_t max_size) -> uint8_t *;
            void commit_enqueued(uint64_t real_size);

            // Consumer
            auto start_dequeuing() -> std::pair<uint8_t *, uint64_t>;
            void free_dequeued();

        private:

            explicit Lock_free_ringbuffer(bi::windows_shared_memory &&shmem, std::string &&name);

            std::string                 _name;
            bi::windows_shared_memory   _mem_obj;

            uint64_t                    _enqueued_blocks = 0;
            uint64_t                    _dequeued_blocks = 0;
        };
    }
}

