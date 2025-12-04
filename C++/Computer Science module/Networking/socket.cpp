//#include <iostream>

//using namespace std;

struct socket{
    char *socket_name;
    __uint128_t IP_address[12];
    __uint128_t port_address;
    __uint128_t process_id;
    char socket_buffer[1000];
};

class socket_class{
    public:
        __uint128_t attach_to_process()
        {
            __uint128_t process_id;
            return process_id;
        }
};

//int main()
//{
//   
//}