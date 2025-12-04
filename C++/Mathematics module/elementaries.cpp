class elementaries{
    public:
        double calculate_logarithm(double base, double number, double precision)
        {
            double logarithm = 0;
            double at_precision = 0;

            while (at_precision != precision)
                logarithm = number/(base * precision);
            return logarithm;
        }

        double calculate_eulers_number (int precision)
        {
            if (precision < 0)
                precision = precision * (-1);

            double e = e + 1;
            for (int i = 1; i < precision; i++)
                e = e + (1/i);
            return e;
        }

        void sine (double base, double tangent)
        {
            sine = base/tangent;
        }

        void cos(double height, double tangent)
        {
            cos = height/tangent;
        }

        void tan(double height, double base)
        {
            tan = height/base;
        }

        void exponentiation (double number, double exponent, double precision) //Not sure if it works.
        {
            exponent = (number * exponent)/precision;
        }
};