//#include <iostream>

class particle_physics{
    public:
        double gluon_strength = 0;
        double quark_charge = 0;
        double lepton_charge = 0;
        double neutrino_mass = 0;

        particle_physics(double gluon_strength, double quark_charge, double lepton_charge, double neutrino_mass)
        {
            this->gluon_strength = gluon_strength;
            this->quark_charge = quark_charge;
            this->lepton_charge = lepton_charge;
            this->neutrino_mass = neutrino_mass;
        }
};

//int main()
//{
//
//}