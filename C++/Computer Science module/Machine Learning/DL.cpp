class DL{
    public:
        __uint128_t number_of_layers;
        __uint128_t number_of_features;
        long long int network[number_of_layers][number_of_features];

        bool dropout_nodes(__uint128_t *indices_to_drop)
        {
            __uint128_t index = 0;

            do{
                for (int i = 0; i < number_of_layers; i++)
                {
                    for (int j = 0; j < number_of_features; j++)
                    {
                        if (i+j == indices_to_drop[index])
                            network[i][j] = 0;
                    }
                }

                index ++;
            }while (index < sizeof(indices_to_drop));

            return true;
        }
};