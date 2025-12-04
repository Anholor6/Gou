//#include <iostream>

//using namespace std;

class linear_algebra{
    public:
        long long int vector[256], matrix[256][256], lu_matrix[256][256], qr_matrix[256][256], lower_matrix[256][256], upper_matrix[256][256], inverse_matrix[256][256];

        bool determinant ()
        {
            return true;
        }

        bool matrix_inverse ()
        {

            return true;
        }

        bool lu_decomposition ()
        {
            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    if (i+j == 2*i)
                        continue;
                    else if ((i+j) > 2*i)
                        upper_matrix[i][j] = matrix[i][j];

                    else if ((i+j) < 2*i)
                        upper_matrix[i][j] = 0;
                }
            }

            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    if (i+j == 2*i)
                        continue;
                    else if ((i+j) > 2*i)
                        upper_matrix[i][j] = 0;

                    else if ((i+j) < 2*i)
                        upper_matrix[i][j] = matrix[i][j];
                }
            }

            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    lu_matrix[i][j] = lower_matrix[i][j] * upper_matrix[i][j];
                    lu_matrix[i][j] = lu_matrix[i][j] * vector[i];
                }
            }

            return true;
        }

        bool qr_decomposition()
        {
            return true;
        }
};

//int main ()
//{
//
//}