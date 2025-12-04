class light{
    public:
        __uint128_t speed_of_light = 0;
        __uint128_t coordinates_array[3], focused_array[3], diverged_array[3];

        bool calculate_speed_of_light ()
        {   
            __uint128_t base = 10;
            for (int i = 0; i < 8; i++)
                base = base * 10;
            speed_of_light = 3 * base;
            return true;
        }

        bool focus_light ()
        {
            focused_array[0] = coordinates_array[0];
            focused_array[1] = coordinates_array[1];
            focused_array[2] = coordinates_array[2];

            return true;
        }

        bool diverge_light ()
        {
            diverged_array[0] = coordinates_array[0];
            diverged_array[1] = coordinates_array[1];
            diverged_array[2] = coordinates_array[2];

            return true;
        }
};