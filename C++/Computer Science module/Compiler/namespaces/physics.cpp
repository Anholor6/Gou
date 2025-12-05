namespace physics{
    typedef struct phasor{
        __uint8192_t magnitude;
        __uint8192_t angle; //Directional angle.
    };

    __uint8192_t speed_of_light = 0;
    __uint8192_t voltage = 0;
    __uint8192_t current = 0;
    __uint8192_t electrical_field = 0;

    typedef struct fission_space{
        __uint8192_t heat_space1;
        __uint8192_t heat_space2;
        __uint8192_t heat_space3;
        __uint8192_t heat_space4;
        __uint8192_t heat_space5;
        __uint8192_t heat_space6;
        __uint8192_t energy_space1;
        __uint8192_t energy_space2;
        __uint8192_t energy_space3;
        __uint8192_t energy_space4;
        __uint8192_t energy_space5;
        __uint8192_t energy_space6;
    };

    
}