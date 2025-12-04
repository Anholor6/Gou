//#include <iostream>

struct buffers{
    __uint128_t image_buffer[256][256];
    __uint128_t colour_buffer[256][256];
    __uint128_t vertex_buffer[256][256];
    __uint128_t luminescence_buffer[256][256];
};

struct object{
    __uint128_t material[16000][16000];
    __uint128_t hue[16000][16000];
    __uint128_t luminessence[16000][16000];
    __uint128_t brightness[16000][16000];
};

struct film{
    __uint128_t R[256][256];
    __uint128_t G[256][256];
    __uint128_t B[256][256];
    __uint128_t Y[256][256];
    __uint128_t saturation [256][256];
};

class bounding_box{
    public:
        __uint128_t face1_length = 0, face1_width = 0, face2_length = 0, face2_width = 0, face3_length = 0, face3_width = 0, face4_length = 0, face4_width = 0, face5_length = 0, face5_width = 0, face6_length = 0, face6_width = 0;
        __uint128_t face1[face1_length][face1_width];
        __uint128_t face2[face2_length][face2_width];
        __uint128_t face3[face3_length][face3_width];
        __uint128_t face4[face4_length][face4_width];
        __uint128_t face5[face5_length][face5_width];
        __uint128_t face6[face6_length][face6_width];
};

class OpenGL{
    protected:
        __uint128_t screen [16000][16000];
    public:
        object initialize_object (__uint128_t **material, __uint128_t **hue, __uint128_t **luminessence, __uint128_t **brightness)
        {
            object object1;

            for (int i = 0; i < 16000; i++)
            {
                for (int j = 0; j < 16000; j++)
                {
                    object1.material[i][j] = material[i][j];
                    object1.hue[i][j] = hue[i][j];
                    object1.luminessence[i][j] = luminessence[i][j];
                    object1.brightness[i][j] = brightness[i][j];
                }
            }

            return object1;
        }

        bool rotation()
        {
            return true;
        }

        bool scaling()
        {
            return true;
        }

        bool shearing ()
        {
            return true;
        }

        bool deformation ()
        {
            return true;
        }

        bool fog()
        {
            return true;
        }
};

//int main()
//{
//
//}