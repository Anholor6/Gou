class fcfs_scheduling{
    public:
        bool schedule_process (process *current_node, __uint128_t process_queue[60], bool up, bool down, bool previous, bool next)
        {
            process *current_node_copy = current_node;

            if (up == true)
            {
                for (int i = 0; i < 60; i++)
                {
                    process_queue[i] = new process;
                    current_node_copy -> up = process_queue[i];
                }
            }

            else if (down == true)
            {
                for (int i = 0; i < 60; i++)
                {
                    process_queue[i] = new process;
                    current_node_copy -> down = process_queue[i];
                }
            }

            else if (previous == true)
            {
                for (int i = 0; i < 60; i++)
                {
                    process_queue[i] = new process;
                    current_node_copy -> previous = process_queue[i];
                }
            }

            else if (next == true)
            {
                for (int i = 0; i < 60; i++)
                {
                    process_queue[i] = new process;
                    current_node_copy -> next = process_queue[i];
                }
            }

            return true;
        }
};