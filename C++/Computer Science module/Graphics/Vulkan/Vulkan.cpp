class vulkan{
    public:
        __uint128_t register_space [2056];
        __uint128_t vram[5000];

        bool allocate_shader_cache (__uint128_t shader_cache [5000])
        {
            for (int i = 0; i < 5000; i++)
                vram[i] = shader_cache[i];
            return true;
        }

        bool allocate_graphic_data (__uint128_t graphic_data [5000])
        {
            for (int i = 0; i < 5000; i++)
                vram[i] = graphic_data[i];
            return true;
        }
};