//#include <iostream>

//using namespace std;

class fading{
    public:
        double rayleigh (double *white_noise_channels1, double *white_noise_channels2, double quadrature_wave)
        {
            double noise_channel_maxiumum1 = 0, noise_channel_maximum2 = 0;

            for (int i = 0; i < sizeof(white_noise_channels1); i++)
            {
                if (noise_channel_maxiumum1 < white_noise_channels1[i])
                    noise_channel_maxiumum1 = white_noise_channels1[i];
            }

            for (int i = 0; i < sizeof(white_noise_channels2); i++)
            {
                if (noise_channel_maximum2 < white_noise_channels2[i])
                    noise_channel_maximum2 = white_noise_channels2[i];
            }

            number_theory nt = new number_theory();
            double wave1_sum = 0, wave2_sum = 0;

            for (int i = 0; i < sizeof(white_noise_channels1); i++)
                sum = sum + white_noise_channels1[i];
            nt.divisibility_theorem(sum, noise_channel_maxiumum1);
            wave1_sum = nt.remainder;

            sum = 0;
            for (int i = 0; i < sizeof(white_noise_channels2); i++)
                sum = sum + white_noise_channels2[i];
            nt.divisibility_theorem(sum, noise_channel_maximum2);
            wave2_sum = nt.remainder;

            double mixed_wave1 = 0, mixed_wave2 = 0;
            mixed_wave1 = wave1_sum * quadrature_wave;
            mixed_wave2 = wave2_sum * quadrature_wave;

            double output_wave = mixed_wave1 + mixed_wave2;

            return output_wave;
        }
};

//int main()
//{
//
//}