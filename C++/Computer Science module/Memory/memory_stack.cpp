class memory_stack{
    public:
        __uint128_t memory_stack [1000000000];

        bool allocate_memory(__uint128_t memory_stack_to_allocate[1000000000])
        {
            for (int i = 0; i < 1000000000; i++)
                this->memory_stack[i] = memory_stack_to_allocate[i];

            return true;
        }
};