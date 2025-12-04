class OpenGL_ES{
    public:
        __uint128_t register_space [10000]; //Abstractions over registers. Part of the memory stack.
        __uint128_t vram[10000];//Performance reasons. Embedded GPU VRAM.

        bool allocate_vram_memory(__uint128_t data[10000])
        {
            for (int i = 0; i < 10000; i++)
                vram[i] = data[i];
            return true;
        }
};