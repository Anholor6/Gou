class number_theory{
    public:

        double quotient = 0;
        int remainder = 0;

        double sum_uptil_100(int number_to_stop_at)
        {
            double sum = (number_to_stop_at*(number_to_stop_at + 1))/2;
            return sum;
        }

        bool divisibility_theorem (double number, double divider)
        {
            quotient = number/divider;
            remainder = number - divider;
            return true;
        }
};