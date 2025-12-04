class numerical_methods{
    public:
        double calculate_integral(double data[256], int dimension_end)
        {
            int number_of_dimensions = sizeof(data)/dimension_end, at_index = 0, at_dimension = 0;
            double integral_results[number_of_dimensions], integration_result = 0;

            while (at_dimension != number_of_dimensions)
            {
                while (at_index % dimension_end)
                {
                    integral_results[at_dimension] = integral_results[at_dimension] + data[at_index + at_dimension];
                    at_index ++;
                }

                at_dimension ++;
            }

            for (long long int dimension = 0; dimension < number_of_dimensions; dimension++)
                integration_result = integration_result * integral_results[dimension];

            return integration_result;
        }

        double calculate_differential ()
        {
            double result = 0;
            return result;
        }

        double norm (double data[256])
        {
            elementaries me = new elementaries();
            double sum = 0;

            for (int i = 0; i < 256; i++)
                sum = sum + data[i];
            me.calculate_exponent(sum,0.5,5);
        }
};