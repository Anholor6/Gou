class numerical_methods{
    public:
        double calculate_integral(double data[256][256], int dimension_end)
        {
            double integration_result = 0;

            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                    integration_result = integration_result + data[i][j];
            }

            return integration_result;
        }

        double calculate_differential (double data[256][256], int dimension_end)
        {
            double differentiation_result;

            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                    differentiation_result = differentiation_result - data[256][256];
            }

            return differentiation_result;
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