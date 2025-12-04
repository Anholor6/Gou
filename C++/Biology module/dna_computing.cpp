//#include <iostream>
//#include <string>

class dna_computing{
    public:
        char *splice_dna(char *strand1, char *strand2, long long int splicing_point)
        {
            std::string spliced_dna [2];

            if (splicing_point > 0)
            {
                long long int splicing_point = sizeof(strand1)/splicing_point;
                char strand_splice1[splicing_point], strand_splice2[splicing_point];

                for (int i = 0; i < sizeof(strand1)/splicing_point; i++)
                    strand_splice1[i] = strand1[i];
                for(int i = sizeof(strand2)/splicing_point; i < sizeof(strand2); i++)
                    strand_splice2[i] = strand2[i];
                
                spliced_dna[0] = strand_splice1;
                spliced_dna[1] = strand_splice2;
            }

            char *new_dna = spliced_dna[0] + spliced_dna[1];

            return new_dna;
        }
};

//int main()
//{
//
//}