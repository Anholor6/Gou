//#include <iostream>

//using namespace std;

class sound{
    public:

        double quantum_wave[256], quantum_ADC[256];

        double* FT (double *ADC_values) // Fourier Transform.
        {
            double max_value = 0, ADC_copy[sizeof(ADC_values)];

            for (int i = 0; i < sizeof(ADC_values); i++)
            {
                if (ADC_values[i] > max_value)
                    max_value = ADC_values[i];
            }

            for (int i = 0; i < sizeof(ADC_values); i++)
                ADC_copy[i] = ADC_values[i]/max_value;

            return ADC_copy;
        }

        double* FFT(double *DAC_values) // Fast Fourier Transform.
        {
            double max_value = 0, DAC_copy[sizeof(DAC_values)];

            for (int i = 0; i < sizeof(DAC_values); i++)
            {
                if (DAC_values[i] > max_value)
                    max_value = DAC_values[i];
            }

            for (int i = 0; i < sizeof(DAC_values); i++)
                DAC_copy[i] = DAC_values[i]/max_value;

            return DAC_copy;
        }

        double wavefronts()
        {
        }
};

//int main()
//{
//
//}