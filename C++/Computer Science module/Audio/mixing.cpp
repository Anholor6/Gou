//#include<iostream>

class mixing{
    public:
        long long int *mix_audio(long long int *audio_wave1, long long int *audio_wave2)
        {
            long long int mixed_audio[sizeof(audio_wave1) > sizeof(audio_wave2) ? sizeof(audio_wave1) : sizeof(audio_wave2)];
            long long int size_of_window = sizeof(audio_wave1) > sizeof(audio_wave2) ? sizeof(audio_wave1) : sizeof(audio_wave2);
            long long int mixed_audio_level = 0, max_audio_level = 0;

            if (sizeof(audio_wave1) == sizeof(audio_wave2))
            {

            }

            for (int i = 0; i < sizeof(audio_wave1); i++)
            {
                if (audio_wave1[i] > max_audio_level)
                    max_audio_level = audio_wave1[i];
            }

            for (int i = 0; i < sizeof(audio_wave2); i++)
            {
                if (audio_wave2[i] > max_audio_level)
                    max_audio_level = audio_wave2[i];
            }

            for (int i = 0; i < size_of_window; i++)
            {
                mixed_audio_level = audio_wave1[i] * audio_wave2[i];
                mixed_audio[i] = mixed_audio_level % max_audio_level;
            }

            return mixed_audio;
        }
};

//int main()
//{
//
//}