class ML{
    public:
        __uint128_t number_of_layers;
        __uint128_t number_of_features;
        __uint128_t network[number_of_layers][number_of_features];

        bool populate_network_matrix (__uint128_t *feedforward)
        {
            if (sizeof(feedforward) <= number_of_features)
            {
                for (int i = 0; i < sizeof(feedforward); i++)
                    network[0][i] = feedforward[i];
            }

            else if (sizeof(feedforward) > number_of_features)
            {
                std::cout << "Data size exceeds number of layers" << std::endl();
                return false;
            }

            return true;
        }
};