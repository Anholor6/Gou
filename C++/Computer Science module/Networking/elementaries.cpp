class elementaries{
    public:
        elementaries ch = new elementaries();
        elementaries ma = new elementaries();        
        double bandwidth = 0, nbits = 0, M = 0, signal_strength = 0, power_out = 0, power_in = 0;
        double thermal_noise = ch.boltzmanns_constant * ch.temperature;
        double nyquist_bandwidth = 2 * bandwidth * ma.calculate_logarithm(M,2,50);
        double SNR = signal_strength/thermal_noise;
        double SNR_db = 10 * ma.calculate_logarithm(SNR,10,50);
        double shannon_capacity = bandwidth * ma.calculate_logarithm((1+SNR),2,50);
        double gain_db = 10 * ma.calculate_logarithm(power_in/power_out,10,50);

        bool calculate_levels()
        {   
            M = 1;

            for (int i = 0; i < nbits; i++)
                M = M * 2;
            return true;
        }
};