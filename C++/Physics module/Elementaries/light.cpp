class light{
    public:
        __uint128_t speed_of_light = 0;
        __uint128_t coordinates_array[3], coordinates_array_copy[3], focused_array[3], diverged_array[2][3];

        bool calculate_speed_of_light ()
        {   
            __uint128_t base = 10;
            for (int i = 0; i < 8; i++)
                base = base * 10;
            speed_of_light = 3 * base;
            return true;
        }

        bool focus_light (double rate_of_convergence)
        {
            
            coordinates_array_copy[0] = coordinates_array[0];
            coordinates_array_copy[1] = coordinates_array[1];
            coordinates_array_copy[2] = coordinates_array[2];

            while (coordinates_array[0] != 0 && coordinates_array[1] != 0 && coordinates_array[2] != 0)
            {
                if (coordinates_array[0] <= 0 && coordinates_array[1] <= 0 && coordinates_array[2] <= 0)
                    break;
                else if (focused_array[0] > 0 && focused_array[1] > 0 && focused_array[2] > 0)
                {
                    focused_array[0] = coordinates_array_copy[0] - (coordinates_array_copy[0] *rate_of_convergence);
                    coordinates_array_copy[0] = coordinates_array_copy[0] - (coordinates_array_copy[0] * rate_of_convergence);
                    focused_array[1] = coordinates_array_copy[0] - (coordinates_array_copy[1] * rate_of_convergence);
                    coordinates_array_copy[1] = coordinates_array_copy[1] - (coordinates_array_copy[1] * rate_of_convergence);
                    focused_array[2] = coordinates_array_copy[2] - (coordinates_array_copy[2] * rate_of_convergence);
                    coordinates_array_copy[2] = coordinates_array_copy[2] - (coordinates_array_copy[2] * rate_of_convergence);
                }
            }

            return true;
        }

        bool diverge_light (double rate_of_divergence, long long int number_of_divergences)
        {

            coordinates_array_copy[0] = coordinates_array[0];
            coordinates_array_copy[1] = coordinates_array[1];
            coordinates_array_copy[2] = coordinates_array[2];

            for (int i = 0; i < number_of_divergences; i++)
            {
                diverged_array[0][0] = coordinates_array[0] + (coordinates_array[0] * rate_of_divergence);
                diverged_array[0][1] = coordinates_array[1] + (coordinates_array[1] * rate_of_divergence);
                diverged_array[0][2] = coordinates_array[2] + (coordinates_array[2] * rate_of_divergence);
                coordinates_array_copy[0] = coordinates_array[0] + (coordinates_array[0] * rate_of_divergence);
                coordinates_array_copy[1] = coordinates_array[1] + (coordinates_array[1] * rate_of_divergence);
                coordinates_array_copy[2] = coordinates_array[2] + (coordinates_array[2] * rate_of_divergence);
            }

            for (int i = 0; i < number_of_divergences; i++)
            {
                diverged_array[1][0] = coordinates_array[0] - (coordinates_array[0] * rate_of_divergence);
                diverged_array[1][1] = coordinates_array[1] - (coordinates_array[1] * rate_of_divergence);
                diverged_array[1][2] = coordinates_array[2] - (coordinates_array[2] * rate_of_divergence);
                coordinates_array_copy[0] = coordinates_array[0] - (coordinates_array[0] * rate_of_divergence);
                coordinates_array_copy[1] = coordinates_array[1] - (coordinates_array[1] * rate_of_divergence);
                coordinates_array_copy[2] = coordinates_array[2] - (coordinates_array[2] * rate_of_divergence);
            }

            return true;
        }
};