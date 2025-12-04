#include <iostream>

using namespace std;

struct process{
    __uint128_t processes[60000000000]; //For UNIX
    __uint128_t pong_processes[10];
    bool scheduled_or_not_array[60000000000];
    bool scheduled_pong_or_not_array[10];
    std::string content[60000000000];
    std::string pong_content[10];
    process *next;
    process *previous;
    process *below;
    process *above;
};

class process_class{
    public:

        process first_process;
        
        process_class(__uint128_t processes[60000000000], __uint128_t pong_processes[10], bool scheduled_or_not_array[60000000000], bool scheduled_pong_or_not_array[10], std::string content[60000000000], std::string pong_content[10])
        {
            for (int i = 0; i < 60000000000; i++)
            {
                this->first_process.processes[i] = processes[i];
                this->first_process.scheduled_or_not_array[i] = scheduled_or_not_array[i];
                this->first_process.content[i] = content[i];
            }

            for (int i = 0; i < 10; i++)
            {
                this->first_process.pong_processes[i] = pong_processes[i];
                this->first_process.scheduled_pong_or_not_array[i] = scheduled_pong_or_not_array[i];
                this->first_process.pong_content[i] = pong_content[i];
            }

        }
};

int main()
{

}