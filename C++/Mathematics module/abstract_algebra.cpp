class abstract_algebra{
    public:
        
        bool status[2]; //[Identity, Inverses]
        std::__uint64_t identity_count, inverses_count;
        
        bool is_additive_group(double *set)
        {
            status[0] = false;
            status[1] = false;

            for (int i = 0; i < sizeof(set); i++)
            {
                if (set [i] == 0)
                    status[0] = true;
            }

            __uint128_t inverse_count = 0;

            for (int i = 0; i < sizeof(set); i++)
            {
                if (i++ < sizeof(set))
                {
                    if ((set[i] - set[i++]) == (set[i++] - set[i]))
                        inverse_count++;
                }
            }

            if (inverse_count == sizeof(set) - 1)
            {
                status[1] = true;
                return true;
            }

            else
                return false;
        }

        bool is_multiplicative_group(double *set)
        {
            bool status[2]; //[Identity, Inverses]

            for (int i = 0; i < sizeof(set); i++)
            {
                if (set [i] == 1)
                    status[0] = true;
            }

            __uint128_t inverse_count = 0;

            for (int i = 0; i < sizeof(set); i++)
            {
                if (i++ < sizeof(set))
                {
                    if ((set[i] / set[i++]) == (set[i++] / set[i]))
                        inverse_count++;
                }
            }

            if (inverse_count == sizeof(set) - 1)
            {
                status[1] = true;
                return true;
            }

            else
                return false;
        }

        bool is_group_under_modulo (double *set, char operators[2])
        {
            int modulo_matrix[sizeof(set)][sizeof(set)];
            identity_count = 0x0;
            inverses_count = 0x0;

            if (operators[1] == '+')
            {
                for (int i = 0; i < sizeof(set); i++)
                {
                    for (int j = 0; j < sizeof(set); j++)
                        modulo_matrix[i][j] = (set[j] % set[i]);
                }

                for (int i = 0; i < sizeof(set); i++)
                {
                    for (int j = 0; j < sizeof(set); j++)
                    {
                        if(modulo_matrix[i][j] == 0)
                            identity_count++;
                    }
                }

                for (int i = 0; i < sizeof(set); i++)
                {
                    for (int j = 0; j < sizeof(set); j++)
                    {
                        if (j++ < sizeof(modulo_matrix[0]))
                        {
                            if ((modulo_matrix[i][j++] - modulo_matrix[i][j]) == (modulo_matrix[i][j] - modulo_matrix[i][j++]))
                                inverses_count++;
                        }
                    }
                }

                if (inverses_count == sizeof(modulo_matrix))
                    return true;
                else
                    return false;
            }

            if (operators[1] == '*')
            {
                for (int i = 0; i < sizeof(set); i++)
                {
                    for (int j = 0; j < sizeof(set); j++)
                        modulo_matrix[i][j] = (set[j] % set[i]);
                }

                for (int i = 0; i < sizeof(set); i++)
                {
                    for (int j = 0; j < sizeof(set); j++)
                    {
                        if(modulo_matrix[i][j] == 1)
                            identity_count++;
                    }
                }

                for (int i = 0; i < sizeof(set); i++)
                {
                    for (int j = 0; j < sizeof(set); j++)
                    {
                        if (j++ < sizeof(modulo_matrix[0]))
                        {
                            if ((modulo_matrix[i][j++] / modulo_matrix[i][j]) == (modulo_matrix[i][j] / modulo_matrix[i][j++]))
                                inverses_count++;
                        }
                    }
                }

                if (inverses_count == sizeof(modulo_matrix))
                    return true;
                else
                    return false;
            }
        }
};