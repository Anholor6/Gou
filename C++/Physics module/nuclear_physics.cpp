class nuclear_physics{
    public:
        __uint128_t heat_space1[256][256]; //For memory conservation
        __uint128_t heat_space2[256][256];
        __uint128_t heat_space3[256][256];
        __uint128_t heat_space4[256][256];
        __uint128_t heat_space5[256][256];
        __uint128_t heat_space6[256][256];
        __uint128_t energy_space1[256][256];
        __uint128_t energy_space2[256][256];
        __uint128_t energy_space3[256][256];
        __uint128_t energy_space4[256][256];
        __uint128_t energy_space5[256][256];
        __uint128_t energy_space6[256][256];
        __uint128_t fission_energy_radiation, fission_energy_release;
        double decay_rate = 0, radiation = 0, electron [3] = {-0.5,0,0.5}, half_life = decay_rate * 10;

        nuclear_physics(__uint128_t **heat_space1, __uint128_t **heat_space2, __uint128_t **heat_space3, __uint128_t **heat_space4, __uint128_t **heat_space5, __uint128_t **heat_space6, __uint128_t **energy_space1, __uint128_t **energy_space2, __uint128_t **energy_space3, __uint128_t **energy_space4, __uint128_t **energy_space5, __uint128_t **energy_space6) //Heat and energy cannot be negative in a nuclear space.
        {
            this->heat_space1 = heat_space1;
            this->heat_space2 = heat_space2;
            this->heat_space3 = heat_space3;
            this->heat_space4 = heat_space4;
            this->heat_space5 = heat_space5;
            this->heat_space6 = heat_space6;
            this->energy_space1 = energy_space1;
            this->energy_space2 = energy_space2;
            this->energy_space3 = energy_space3;
            this->energy_space4 = energy_space4;
            this->energy_space5 = energy_space5;
            this->energy_space6 = energy_space6;
        }

        bool change_spaces()
        {
            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    if ((i+j) % 3 == 0 && (i+j) % 4 == 0 && (i+j) % 5 == 0)
                    {
                        heat_space1[i][j] = 1;
                        heat_space2[i][j] = 1;
                        heat_space3[i][j] = 1;
                        heat_space4[i][j] = 1;
                        heat_space5[i][j] = 1;
                        heat_space6[i][j] = 1;
                    }

                    else if ((i+j) == 6 && (i+j) == 7 && (i+j) == 8)
                    {
                        energy_space1[i][j] = 1;
                        energy_space2[i][j] = 1;
                        energy_space3[i][j] = 1;
                        energy_space4[i][j] = 1;
                        energy_space5[i][j] = 1;
                        energy_space6[i][j] = 1;
                    }
                }
            }

            fission_energy_radiation = (fission_energy_radiation + 6) % 6;
            fission_energy_release = (fission_energy_release + 6) % 12;

            return true;
        }

        double calculate_alpha_decay ()
        {
            decay_rate = 0;

            for (int i = 0 ; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    if ((i+j) % 3 == 0 && (i+j) % 4 == 0 && (i+j) % 5 == 0)
                    {
                        if (heat_space1[i][j] == 1)
                            decay_rate = decay_rate + 1;

                        else if (heat_space2[i][j] == 1)
                            decay_rate = decay_rate + 1;

                        else if (heat_space2[i][j] == 1)
                            decay_rate = decay_rate + 1;

                        else if (heat_space2[i][j] == 1)
                            decay_rate = decay_rate + 1;

                        else if (heat_space2[i][j] == 1)
                            decay_rate = decay_rate + 1;

                        else if (heat_space2[i][j] == 1)
                            decay_rate = decay_rate + 1;
                    }
                }
            }

            decay_rate = decay_rate/20;

            return decay_rate;
        }

        double calculate_beta_decay ()
        {
            decay_rate = 0;

            for (int i = 0 ; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    if ((i+j) % 4 == 0 && (i+j) % 5 == 0 && (i+j) % 6 == 0)
                    {
                        if (heat_space1[i][j] == 1)
                            decay_rate = decay_rate + 1;

                        else if (heat_space2[i][j] == 1)
                            decay_rate = decay_rate + 1;

                        else if (heat_space2[i][j] == 1)
                            decay_rate = decay_rate + 1;

                        else if (heat_space2[i][j] == 1)
                            decay_rate = decay_rate + 1;

                        else if (heat_space2[i][j] == 1)
                            decay_rate = decay_rate + 1;

                        else if (heat_space2[i][j] == 1)
                            decay_rate = decay_rate + 1;
                    }
                }
            }

            decay_rate = decay_rate/60;

            return decay_rate;
        }

        double calculate_gamma_radiation ()
        {
            radiation = 0; // For avoiding initialization and runtime errors.
            radiation = (fission_energy_radiation + fission_energy_release) % 12;
            return radiation;
        }

        bool reinitialize_to_zero ()
        {
            for (int i = 0; i < 256; i++)
            {
                for(int j = 0; j < 256; j++)
                {
                    energy_space1[i][j] = 0;
                    energy_space2[i][j] = 0;
                    energy_space3[i][j] = 0;
                    energy_space4[i][j] = 0;
                    energy_space5[i][j] = 0;
                    energy_space6[i][j] = 0;
                    heat_space1[i][j] = 0;
                    heat_space2[i][j] = 0;
                    heat_space3[i][j] = 0;
                    heat_space4[i][j] = 0;
                    heat_space5[i][j] = 0;
                    heat_space6[i][j] = 0;
                }
            }
            
            fission_energy_radiation = 0;
            fission_energy_release = 0;

            return true;
        }
};