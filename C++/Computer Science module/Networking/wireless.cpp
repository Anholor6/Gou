class wireless_networking{
    public:
        elementaries ma = elementaries();
        light lt = new light();
        double frequency = 0, area_of_effect = 0, diameter_of_dish = 0, distance = 0, power_out = 0, power_in = 0, resistance_of_medium = 0, power_voltage = 0, recieving_antenna_area = 0, transmitting_antena_area = 0;
        double wavelength = frequency/lt.speed_of_light;
        double wireless_gain = (4 * (ma.pi) * frequency * area_of_effect)/lt.speed_of_light;
        double wireless_loss = ma.calculate_logarithm((4 * ma.pi * distance)/wavelength, 10, 50);
        double wireless_power_gain = power_out/power_in;
        double wireless_power_gain_db = 10 * ma.calculate_logarithm(wireless_power_gain,10,50);
        double wireless_power = (power_voltage * power_voltage)/resistance_of_medium;
        double line_of_sight_power_loss = (lt.speed_of_light * distance)/(frequency * frequency * recieving_antenna_area * transmitting_antena_area);

        double ASK ()
        {
            double shifted_wave = 0;
            return shifted_wave;
        }

        double BFSK ()
        {
            double shifted_wave = 0;
            return shifted_wave;
        }

        double MFSK ()
        {
            double shifted_wave = 0;
            return shifted_wave;
        }

        double BPSK ()
        {
            double shifted_wave = 0;
            return shifted_wave;
        }

        double QPSK ()
        {
            double shifted_wave = 0;
            return shifted_wave;
        }

        double QAM ()
        {
            double shifted_wave = 0;
            return shifted_wave;
        }

        double AM ()
        {
            double shifted_wave = 0;
            return shifted_wave;
        }

        double PM ()
        {
            double shifted_wave = 0;
            return shifted_wave;
        }

        double FM ()
        {
            double shifted_wave = 0;
            return shifted_wave;
        }
};