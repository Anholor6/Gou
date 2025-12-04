//#include <iostream>

class  set_theory{
    public:
        double* return_union (double *set1,double *set2)
        {
            double union_set [sizeof(set1) + sizeof(set2)];
            
            for (int i = 0; i < (sizeof(set1) + sizeof(set2)); i++)
            {
                if (i < sizeof(set1))
                    union_set[i] = set1[i];
                else if (i > sizeof(set2))
                    union_set[i] = set2[i - sizeof(set1)];
            }

            return union_set;
        }

        double* return_intersection (double *set1, double *set2)
        {
            double intersection_set[(sizeof(set1) + sizeof(set2))/2];
            int intersection_index = 0;

            for (int i = 0 ; i < (sizeof(set1) + sizeof(set2)); i++)
            {
                if (i < sizeof(set1))
                {
                    for (int j = 0; j < sizeof(intersection_set); j++)
                    {
                        if (intersection_set[intersection_index] == set1[i])
                            continue;
                        else if(intersection_set[intersection_index] != set1[i])
                        {
                            intersection_set[intersection_index] = set1[i];
                            intersection_index++;
                        }
                    }
                }

                else if (i >= set1[i])
                {
                    for (int j = 0; j < sizeof(intersection_set); j++)
                    {
                        if (intersection_set[intersection_index] == set2[i])
                            continue;
                        else if(intersection_set[intersection_index] != set2[i])
                        {
                            intersection_set[intersection_index] = set2[i];
                            intersection_index++;
                        }
                    }
                }
            }

            return intersection_set;
        }
};

//int main()
//{
//
//}