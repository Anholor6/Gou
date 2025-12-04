class electromagnetism{
    public:
        long long int voltage = 0;
        long long int current = 0;
        long long int resistance = 0;
        long long int quantum_resistance = 0; // Fluid resistance.
        long long int quantum_voltage = 0;
        long long int quantum_current = 0;
        long long int electrical_field = 0;
        long long int quantum_electrical_field = 0;
        long long int area_of_effect = 0;

        electromagnetism(long long int voltage, long long int current, long long int resistance, long long int electrical_field, long long int area_of_effect, long long int quantum_voltage, long long int quantum_current, long long int quantum_electrical_field, long long int quantum_resistance) // For faster initialization
        {
            this->voltage = voltage;
            this->current = current;
            this->resistance = resistance;
            this->electrical_field = electrical_field;
            this->area_of_effect = area_of_effect;
            this->quantum_voltage = quantum_voltage;
            this->quantum_electrical_field = quantum_electrical_field;
            this->quantum_current = quantum_current;
            this->quantum_resistance = quantum_resistance;
        }

        void calculate_electric_field (long long int charge)
        {
            electrical_field = charge * this->area_of_effect; //It is already cached
        }

        void calculate_voltage (long long int x_coordinate, long long int y_coordinate, long long int z_coordinate, long long int electrical_field)
        {
            if (electrical_field == 0)
                this->voltage = this->current * this->current * this->resistance;
            else if (electrical_field != 0)
                this->voltage = electrical_field;
        }

        void calculate_current ()
        {
            this->current = calculate_logarithm ((this->voltage)/(this->resistance));
        }

        void calculate_quantum_current()
        {
            this->quantum_current = calculate_logarithm((this->quantum_voltage)/(this->quantum_resistance));
        }
};