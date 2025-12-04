class quantum{
public:
    double deltax = 0, deltay = 0, deltaz = 0, x = 0, y = 0, z = 0, heisenbergs_uncertainity[6];

    bool calculate_heisenbergs_uncertainity ()
    {
        heisenbergs_uncertainity [0] = x + deltax;
        heisenbergs_uncertainity [1] = y + deltay;
        heisenbergs_uncertainity [2] = z + deltaz;
        heisenbergs_uncertainity [3] = x - deltax;
        heisenbergs_uncertainity [4] = y - deltay;
        heisenbergs_uncertainity [5] = z - deltaz;

        return true;
    }
};
