class codec{
    public:
        double* code (double audio_wave[256], double frequency_of_sampling)
        {
            for (int i = 0; i < 256; i++)
                audio_wave[i] = audio_wave[i]/frequency_of_sampling;
            return audio_wave;
        }

        double* decode (double audio_wave[256], double frequency_of_sampling)
        {
            for (int i = 0; i < 256; i++)
                audio_wave[i] = audio_wave[i]*frequency_of_sampling;
            return audio_wave;
        }
};