class oceanogrpahy{
    public:
        __uint128_t ocean_block[256][256][256]; 
        bool has_risen[256][256][256], has_fallen[256][256][256];

        void denote_fallen (double threshold)
        {
            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    for (int k = 0; k < 256; k++)
                    {
                        if (ocean_block[i][j][k] > threshold)
                            has_fallen[i][j][k] = true;
                    }
                }
            }
        }

        void denote_risen (double threshold)
        {
            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    for (int k = 0; k < 256; k++)
                    {
                        if (ocean_block[i][j][k] < threshold)
                            has_fallen[i][j][k] = true;
                    }
                }
            }
        }
};