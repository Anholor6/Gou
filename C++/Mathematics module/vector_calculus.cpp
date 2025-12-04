struct vector1d{
    __uint128_t magnitude;
    double angle_of_direction;
};

struct rectangular_tensor{
    __uint128_t face1[256][256];
    __uint128_t face2[256][256];      
    __uint128_t face3[256][256];
    __uint128_t face4[256][256];
    __uint128_t face5[256][256];
    __uint128_t face6[256][256];
    __uint128_t face1_angle[256][256];
    __uint128_t face2_angle[256][256];
    __uint128_t face3_angle[256][256];
    __uint128_t face4_angle[256][256];
    __uint128_t face5_angle[256][256];
    __uint128_t face6_angle[256][256];
};

struct spheroidal_tensor{//Spheroidal tensor
    __uint128_t face1[256/3][256/3];
    __uint128_t face2[256/3][256/3];
    __uint128_t face3[256/3][256/3];
    __uint128_t face4[256/3][256/3];
    __uint128_t face5[256/3][256/3];
    __uint128_t face6[256/3][256/3];
    __uint128_t face1_angle[256/3][256/3];
    __uint128_t face2_angle[256/3][256/3];
    __uint128_t face3_angle[256/3][256/3];
    __uint128_t face4_angle[256/3][256/3];
    __uint128_t face5_angle[256/3][256/3];
    __uint128_t face6_angle[256/3][256/3];
};

struct rotation_tensor{
    __uint128_t face1_angle[256][256];
    __uint128_t face2_angle[256][256];
    __uint128_t face3_angle[256][256];
    __uint128_t face4_angle[256][256];
    __uint128_t face5_angle[256][256];
    __uint128_t face6_angle[256][256];
};

class vector_calculus{
    public:
        vector1d cross_product (vector1d vector1, vector1d vector2)
        {
            vector1d resultant_vector;
            resultant_vector.magnitude = vector1.magnitude * vector2.magnitude;
            resultant_vector = (vector1.angle_of_direction + vector2.angle_of_direction) % 360;
            return resultant_vector;
        }

        vector1d scalar_product (vector1d vector1, vector1d vector2)
        {
            vector1d resultant_vector;
            resultant_vector.magnitude = vector1.magnitude * vector2.magnitude;
            return resultant_vector;
        }

        bool rotate_vector (vector1d vector, double rotation_angle)
        {
            vector.angle_of_direction = (vector.angle_of_direction + rotation_angle) % 360;
            return true;
        }

        bool rotate_rectangular_tensor (rectangular_tensor tensor, rotation_tensor rtensor)
        {
            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    tensor.face1_angle[i][j] = (tensor.face1_angle[i][j] + rtensor.face1_angle[i][j]) % 360;
                    tensor.face2_angle[i][j] = (tensor.face2_angle[i][j] + rtensor.face2_angle[i][j]) % 360;
                    tensor.face3_angle[i][j] = (tensor.face3_angle[i][j] + rtensor.face3_angle[i][j]) % 360;
                    tensor.face4_angle[i][j] = (tensor.face4_angle[i][j] + rtensor.face4_angle[i][j]) % 360;
                    tensor.face5_angle[i][j] = (tensor.face5_angle[i][j] + rtensor.face5_angle[i][j]) % 360;
                    tensor.face6_angle[i][j] = (tensor.face6_angle[i][j] + rtensor.face6_angle[i][j]) % 360;
                }
            }

            return true;
        }
};