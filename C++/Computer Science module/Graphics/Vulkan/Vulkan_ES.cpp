class Vulkan_ES{
    public:
        bool render_is_finished[5000];
        __uint128_t render_cache[10000], frame_buffer[60000];

        bool allocate_cache (__uint128_t render_cache[10000])
        {
            for (int i = 0; i < 10000; i++)
                this->render_cache[i] = render_cache[10000];

            return true;
        }

        bool flush_to_render (__uint128_t finished_cache[60000], bool render_finished[60000])
        {
            for (int i = 0; i < 60000; i++)
            {
                this->frame_buffer[i] = finished_cache[i];
                render_is_finished[i] = render_finished[i];
            }

            return true;
        }
};