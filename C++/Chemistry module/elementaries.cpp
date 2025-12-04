class elementaries{
    public:
        double pressure = 0, temperature = 0, volume = 0, number_of_moles = 0, number_of_particles = 0;
        double universal_gas_constant = (pressure * volume)/(number_of_moles * temperature);
        double avagadro_number = number_of_particles/3;
        double boltzmanns_constant = universal_gas_constant/avagadro_number;
};
