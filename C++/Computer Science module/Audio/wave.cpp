//#include <iostream>

//using namespace std;

class wave{
    public:
        long long int *audio_levels;
        long long int audio_level;

        bool generate_wave(long long int maximum_audio_level)
        {
            audio_levels[maximum_audio_level * 4];

            for (int i = 0; i <= maximum_audio_level; i++)
                audio_levels[i] = i;
            for (int i = maximum_audio_level - 1; i >=0 ; i++)
                audio_levels[i] = i;
            for (int i = 0; i >= -maximum_audio_level; i--)
                audio_levels[i] = i;
            for (int i = -maximum_audio_level+1; i <= 0; i++)
                audio_levels[i] = i;
            
            return true;
        }
};

//int main()
//{
//
//}