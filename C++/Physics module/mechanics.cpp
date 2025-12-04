//#include <iostream>

//using namespace std;

class classical{
    public:
        double mass_of_body = 0, weight_of_body = 0, friction = 0, velocity = 0, kinematic_velocity = 0, energy = 0;

        bool calculate_kinematic_force ()
        {
            this -> kinematic_velocity = (mass_of_body * velocity * velocity)/2;
            return true;
        }
        
        bool calculate_energy (double weight_of_object, double gravitational_constant, double light_speed)
        {
            energy = (weight_of_body/gravitational_constant) * (light_speed * light_speed); // E = m*C^2
            return true;
        }
};

class quantum{
    public:
        double uncertainity = 0;
        double coupled_electrons[2];
        
        bool heisenbergs_uncertainity_principle (double deltax, double deltay, char operative)
        {
            uncertainity = 0;
            
            switch (operative)
            {
                case '+' :  uncertainity = deltax + deltay;
                            break;
                case '-' :  uncertainity = deltax - deltay;
                            break;
            }

            return true;
        }

        bool heisenbergs_cat (double wave[256])
        {
            bool alive = false;
            
            for (int i = 0; i < 256; i++)
            {
                if (wave[i] < 0)
                {
                    alive = false;
                    std::cout << "The cat is dead" << std::endl;
                }

                else if (wave[i] > 0)
                {
                    alive = true;
                    std::cout << "The cat is alive" << std::endl;
                }

                else if (wave[i] == 0)
                    std::cout << "Uncertain" << std::endl;
            }
        }

        bool feynman_radiation(double rate_of_transmission, int number_of_iterations)
        {
            for (int i = 0; i < number_of_iterations; i++)
            {
                coupled_electrons[0] = coupled_electrons[0] - (coupled_electrons[1] * rate_of_transmission);
                coupled_electrons[1] = coupled_electrons[1] - (coupled_electrons[1] * rate_of_transmission);

                if (coupled_electrons[0] >= 0.98 && coupled_electrons[1] >= 0.68)
                {
                    coupled_electrons[0] = coupled_electrons[0] + 0.2;
                    coupled_electrons[1] = coupled_electrons[1] + 0.3;
                } 
            }

            return true;
        }
};

//int main()
//{
//
//}