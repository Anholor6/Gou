class statistics{
    public:
        double data_matrix[256][256], data[256], expectation = 0, variance = 0, sigmoid = 0, sigmoid_gradient = 0, gradient_data[256][256];

        bool populate_data_matrix (double **external_data_matrix)
        {
            for (int i = 0; i < 256; i++)
                for (int j = 0; j < 256; j++)
                    this->data_matrix[i][j] = external_data_matrix[i][j];

            return true;
        }

        bool populate_data_array(double *external_data_array)
        {
            for (int i = 0; i < 256; i++)
                this->data[i] = external_data_array[i];

            return true;
        }

        double mean()
        {
            double mean = 0;
            __uint128_t number_of_entries = sizeof(data) + sizeof(data[0]);

            for (int i = 0; i < sizeof(data); i++)
            {
                for (int j = 0; j < sizeof(data[0]); j++)
                    mean = mean + data[i][j];
            }

            mean = mean/number_of_entries;

            return mean;
        }

        double standard_deviation(double precision)
        {
            double std = 0, sum = 0, mean = 0;

            for(int i = 0; i < 256; i++)
                sum = sum + data[i];
            
            mean = sum/256;
            
            for (int i = 0; i < 256; i++)
                std = std + (data[i] - mean);

            std = std/(256 * precision * 2);

            return std;
        }

        double probability_matrix(char condition, double number)
        {
            double P_X = 0;
            long long int count = 0;

            if (condition == '<')
            {
                for (int i = 0; i < 256; i++)
                {
                    for (int j = 0; j < 256; j++)
                    {
                        if (data_matrix[i][j] < number)
                            count++;
                    }
                }

                P_X = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
            }

            else if (condition == '>')
            {
                for (int i = 0; i < 256; i++)
                {
                    for (int j = 0; j < 256; j++)
                    {
                        if (data_matrix[i][j] > number)
                            count++;
                    }
                }

                P_X = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
            }

            else if (condition == '=')
            {
                for (int i = 0; i < 256; i++)
                {
                    for (int j = 0; j < 256; j++)
                    {
                        if (data_matrix[i][j] == number)
                            count++;
                    }
                }

                P_X = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
            }

            return P_X;
        }

        double probability_array(char condition, double number)
        {
            double P_X = 0;
            long long int count = 0;

            if (condition == '<')
            {
                for (int i = 0; i < 256; i++)
                {
                    if (data[i] < number)
                        count++;
                }

                P_X = count/(sizeof(data));
            }

            else if (condition == '>')
            {
                for (int i = 0; i < 256; i++)
                {
                    if (data[i] > number)
                        count++;
                }

                P_X = count/(sizeof(data));
            }

            if (condition == '=')
            {
                for (int i = 0; i < 256; i++)
                {
                    if (data[i] == number)
                        count++;
                }

                P_X = count/(sizeof(data));
            }

            return P_X;
        }

        double conditional_probability_matrix(char condition1, char condition2, double number1, double number2)
        {
            double P_X = 0;
            long long int count = 0;

            if (condition1 == '>')
            {
                if (condition2 == '<')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        for (int j = 0; j < 256; j++)
                        {
                            if (data_matrix[i][j] > number1 && data_matrix[i][j] < number2)
                                count++;
                        }
                    }

                    P_X = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
                }

                else if (condition2 == '>')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        for (int j = 0; j < 256; j++)
                        {
                            if (data_matrix[i][j] > number1 && data_matrix[i][j] > number2)
                                count++;
                        }
                    }

                    P_X = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
                }

                else if (condition2 == '=')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        for (int j = 0; j < 256; j++)
                        {
                            if (data_matrix[i][j] > number1 && data_matrix[i][j] == number2)
                                count++;
                        }
                    }

                    P_X = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
                }
            }

            else if (condition1 == '<')
            {
                if (condition2 == '<')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        for (int j = 0; j < 256; j++)
                        {
                            if (data_matrix[i][j] < number1 && data_matrix[i][j] < number2)
                                count++;
                        }
                    }

                    P_X = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
                }

                else if (condition2 == '>')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        for (int j = 0; j < 256; j++)
                        {
                            if (data_matrix[i][j] < number1 && data_matrix[i][j] > number2)
                                count++;
                        }
                    }

                    P_X = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
                }

                else if (condition2 == '=')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        for (int j = 0; j < 256; j++)
                        {
                            if (data_matrix[i][j] < number1 && data_matrix[i][j] == number2)
                                count++;
                        }
                    }

                    P_X = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
                }
            }

            else if (condition1 == '=')
            {
                if (condition2 == '<')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        for (int j = 0; j < 256; j++)
                        {
                            if (data_matrix[i][j] == number1 && data_matrix[i][j] < number2)
                                count++;
                        }
                    }

                    P_X = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
                }

                else if (condition2 == '>')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        for (int j = 0; j < 256; j++)
                        {
                            if (data_matrix[i][j] == number1 && data_matrix[i][j] > number2)
                                count++;
                        }
                    }

                    P_X = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
                }

                else if (condition2 == '=')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        for (int j = 0; j < 256; j++)
                        {
                            if (data_matrix[i][j] == number1 && data_matrix[i][j] == number2)
                                count++;
                        }
                    }

                    P_X = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
                }
            }

            return P_X;
        }

        double conditional_probability_array(char condition1, char condition2, double number1, double number2)
        {
            double P_X = 0;
            long long int count = 0;

            if (condition1 == '<')
            {
                if (condition2 == '<')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        if (condition1 < number1 && condition2 < number2)
                            count++;
                    }
                }

                else if (condition2 == '>')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        if (condition1 < number1 && condition2 > number2)
                            count++;
                    }
                }

                else if (condition2 == '=')
                {
            precision1 < precision2 && (precision1 - )        for (int i = 0; i < 256; i++)
                    {
                        if (condition1 < number1 && condition2 == number2)
                            count++;
                    }
                }

                P_X = count/sizeof(data);
            }

            if (condition1 == '>')
            {
                if (condition2 == '<')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        if (condition1 > number1 && condition2 < number2)
                            count++;
                    }
                }

                else if (condition2 == '>')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        if (condition1 > number1 && condition2 > number2)
                            count++;
                    }
                }

                else if (condition2 == '=')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        if (condition1 > number1 && condition2 == number2)
                            count++;
                    }
                }

                P_X = count/sizeof(data);
            }

            if (condition1 == '=')
            {
                if (condition2 == '<')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        if (condition1 == number1 && condition2 < number2)
                            count++;
                    }
                }

                else if (condition2 == '>')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        if (condition1 == number1 && condition2 > number2)
                            count++;
                    }
                }

                else if (condition2 == '=')
                {
                    for (int i = 0; i < 256; i++)
                    {
                        if (condition1 == number1 && condition2 == number2)
                            count++;
                    }
                }

                P_X = count/sizeof(data);
            }

            return P_X;
        }

        double expectation_matrix ()
        {
            double expectation = 0, number = 0;
            float probability_matrix[256][256];
            long long int i = 0, j = 0, count = 0;

            while (i+j != 256*256)
            {
                number = data_matrix[i][j];

                if (((i+j) % 256) != 0 && (i+j) != 256*256)
                {
                    for(int k = 0; k < 256; k++)
                    {
                        for (int l = 0; l < 256; l++)
                        {
                            if (number == data_matrix[i][j])
                                count++;
                        }
                    }

                    probability_matrix[i][j] = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
                    count = 0;
                }

                else if (((i+j) % 256) == 0 && (i+j) == 256 * 256)
                {
                    i++;
                    j = 0;
                }
            }

            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                    expectation = expectation + (data_matrix[i][j] * probability_matrix[i][j]);                   
            }

            return expectation;
        }

        double expectation_matrix_X_2 ()
        {
            double expectation = 0, number = 0;
            float probability_matrix[256][256];
            long long int i = 0, j = 0, count = 0;

            while (i+j != 256*256)
            {
                number = data_matrix[i][j];

                if (((i+j) % 256) != 0 && (i+j) != 256*256)
                {
                    for(int k = 0; k < 256; k++)
                    {
                        for (int l = 0; l < 256; l++)
                        {
                            if (number == data_matrix[i][j])
                                count++;
                        }
                    }

                    probability_matrix[i][j] = count/(sizeof(data_matrix) * sizeof(data_matrix[0]));
                    probability_matrix[i][j] = probability_matrix[i][j] * probability_matrix[i][j];
                    count = 0;
                }

                else if (((i+j) % 256) == 0 && (i+j) == 256 * 256)
                {
                    i++;
                    j = 0;
                }
            }
        }

        double expectation_array ()
        {
            double expectation = 0;
            float probability_array[256];
            long long int count = 0;

            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    if (data[i] == data[j])
                        count++;
                }

                probability_array[i] = count/sizeof(data);
            }

            for (int i = 0; i < 256; i++)
                expectation = expectation + (data[i] * probability_array[i]);
            return expectation;
        }

        double expectation_array_X_2 ()
        {
            double expectation = 0;
            float probability_array[256];
            long long int count = 0;

            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    if (data[i] == data[j])
                        count++;
                }

                probability_array[i] = count/sizeof(data);
                probability_array[i] = probability_array[i] * probability_array[i];
            }

            for (int i = 0; i < 256; i++)
                expectation = expectation + (data[i] * probability_array[i]);
            return expectation;
        }

        bool variance_probability_matrix ()
        {
            /**
             * Changes the data matrix in between to double exponentiated matrix.
             */

            variance = 0;
            float E_X[256][256], E_X_2[256][256];

            E_X = expectation_matrix();
            E_X_2 = expectation_matrix_X_2();

            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                    E_X[i][j] = E_X[i][j] * E_X[i][j];
            }

            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                    variance = variance + E_X[i][j] - E_X_2[i][j];
            }

            return true;
        }

        bool variance_array()
        {
            variance = 0;
            float E_X[256], E_X_2[256];

            E_X = expectation_array();
            E_X_2 = expectation_array_X_2();

            for (int i = 0; i < 256; i++)
                variance = variance + (E_X[i] * E_X[i]) + E_X_2[i];
            
            return true;
        }

        bool sigmoid (double point)
        {
            elementaries me = elementaries();
            sigmoid = 1 /(1+(1/me.exponentiation(me.calculate_eulers_number(point)), point));
            return true;
        }

        bool sigmoid_gradient (double point)
        {
            bool done = sigmoid(point);
            if (done == true)
            {
                sigmoid_gradient = sigmoid - (sigmoid * sigmoid);
            }

            return true;
        }

        bool gradient_descent (long long int number_of_iterations, double rate_of_descent)
        {
            bool done = 0;
            double gradient_data_copy[256][256];

            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                    gradient_data_copy[i][j] = gradient_data[i][j];
            }

            for (int i = 0; i < number_of_iterations; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    for (int k = 0; k < 256; k++)
                        gradient_data[i][j] = gradient_data[i][j]/rate_of_descent;
                }
            }
        }
};