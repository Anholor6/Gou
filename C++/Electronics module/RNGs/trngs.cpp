//#include <iostream>

class trngs{
    public:
        __uint128_t random_number = 0x0;

        void ring_oscillator (__uint128_t nnot_gates, __uint128_t nshift_registers, __uint128_t nxor_gates, char shift_direction)
        {
            if (shift_direction == 'r')
            {
                for (__uint128_t not_gate = 0x0; not_gate < nnot_gates; not_gate++)
                {
                    random_number = ~random_number;
                    random_number = random_number >> 1;
                    random_number = random_number ^ 1;
                }
            }

            else if (shift_direction == 'l')
            {
                for (__uint128_t not_gate = 0x0; not_gate < nnot_gates; not_gate++)
                {
                    random_number = ~random_number;
                    random_number = random_number << 1;
                    random_number = random_number ^ 1;
                }
            }
        }
};

int main()
{
    trngs tr = new trngs();
    tr.ring_oscillator(0x02,0x09,0x04,'r');
    __uint128_t random_number = tr.random_number;

    std::cout << random_number << std::endl;
}