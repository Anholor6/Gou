class QED{
    public:
        double quantum_wave = 0, ripple_strength = 0, ripple_wavefronts[256];
        
        void calculate_quantum_wave (double start_time, double end_time)
        {
            elementaries me = new elementaries();

            for (int i = start_time; i < end_time; i++)
            {
                quantum_wave = quantum_wave + me.sin(ripple_strength, i);
            }
        }

        void calculate_ripple_wavefronts (double ripple_wavefronts[256])
        {
            for (int i = 0; i < 256; i++)
                this->ripple_wavefronts[i] = ripple_wavefronts[i] * quantum_wave * 9;
        }

        double quantum_sound ()
        {
        }
};