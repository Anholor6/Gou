class economics{
    public:
        double principal = 0, rate_of_interest = 0.0, number_of_payment_periods = 0, gradient = 0, future_value = 0, value_of_annuity = 0;
        double index_data[256][256], annuity_stream[256];

        bool future_value_of_single_amount ()
        {
            future_value = 0;
            rate_of_interest = 1+rate_of_interest;

            for (int i = 0; i < number_of_payment_periods; i++)
                rate_of_interest = rate_of_interest * rate_of_interest;
            future_value = principal + principal * rate_of_interest;

            return true;
        }

        bool calculate_future_value_of_annuity()
        {
            future_value = principal; 
            value_of_annuity = 0;

            for (int i = 0; i < sizeof(annuity_stream); i++)
            {
                for (int j = 0; j < i; i++)
                    value_of_annuity = value_of_annuity + annuity_stream[j] * (1+rate_of_interest);
                future_value = future_value + value_of_annuity;
            }

            return true;
        }

        bool calculate_arithmetic_gradient ()
        {
            future_value = 0;

            for (int i = 0; i < sizeof(annuity_stream); i++)
            {
                for (int j = 0; j < i; j++)
                    value_of_annuity = value_of_annuity + gradient * annuity_stream[j] * (1+rate_of_interest);
                future_value = future_value + value_of_annuity; 
            }

            return future_value;
        }

        double calculate_index_value ()
        {
            double index_values[sizeof(index_data)];
            
            for (int i = 0; i < sizeof(index_data); i++)
            {
                for (int j = 0; j < sizeof(index_data[0]); i++)
                    index_values[i] = index_values[i] + index_data[i][j];
                index_values[i] = index_values[i] ** (0.5);
            }

            double index = 0;

            for (int i = 0; i < sizeof(index_data); i++)
                index = index + index_values[i];
            index = index/sizeof(index_data);

            return index;
        }

        double calculate_FICO_score (double index)
        {
            double FICO_score = index * (9/200);
            return FICO_score;
        }
};