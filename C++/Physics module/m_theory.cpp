class m_theory {
    public:
        double energy = 0, gravitational_constant = 0, height_of_object = 0, pressure_of_object = 0, speed_of_light = 0;

        void init_speed_of_light()
        {
            speed_of_light = 8;

            for (int i = 0; i < 8; i++)
                speed_of_light = speed_of_light * 10;
        }

        void energy ()
        {
            energy = ((pressure_of_object * height_of_object)/gravitational_constant) * speed_of_light;
        }
};