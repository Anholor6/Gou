struct node{
    __uint128_t weight;
    node *next;
    node *previous;
};

class graphs{
    public:
        __uint128_t undirected_graph[16000][16000], directed_graph [16000][16000], graph[256][256];

        void populate_graph(__uint128_t **adjacency_matrix)// For faster initialization.
        {
            for (int i = 0; i < 16000; i++)
            {
                for (int j = 0; j < 16000; j++)
                    adjacency_matrix[i][j] = adjacency_matrix[i][j];
            }
        }

        void generate_graph(int generation_interval, __uint128_t data_to_put_in[256])
        {

            int index = 0;

            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    if ((i+j) % generation_interval)
                    {
                        graph[i][j] = data_to_put_in[index];
                        index++;
                    }
                }
            }
        }

};

class routing{
    public:
        node* dijsktra (__uint128_t **adjacency_matrix, int start_row, int start_column, int end_row, int end_column)
        {
            node *root = new node();
            root->weight = adjacency_matrix[start_row][start_column];
            root->next = NULL;
            root->previous = NULL;
            node *current = root;

            int row = start_row, column = start_column;

            while (row != end_row && column != end_column)
            {
                if (row++ < sizeof(adjacency_matrix) && column++ < sizeof(adjacency_matrix[0]) && row-- < sizeof(adjacency_matrix) && column-- < sizeof(adjacency_matrix))
                {
                    if (adjacency_matrix[row++][column] <= adjacency_matrix[row++][column++] <= adjacency_matrix[row--][column] <= adjacency_matrix[row--][column--])
                    {
                        node *new_node = new node();
                        new_node -> weight = adjacency_matrix[row++][column];
                        new_node -> next = NULL;
                        new_node -> previous = current;
                        current -> next = new_node;
                        current = current -> next;
                        row = row++;
                    }

                    else if (adjacency_matrix[row++][column++] <= adjacency_matrix[row++][column] <= adjacency_matrix[row--][column] <= adjacency_matrix[row--][column--])
                    {
                        node *new_node = new node();
                        new_node -> weight = adjacency_matrix[row++][column++];
                        new_node -> next = NULL;
                        new_node -> previous = current;
                        current -> next = new_node;
                        current = current -> next;
                        row = row++;
                        column = column++;
                    }

                    else if (adjacency_matrix[row--][column] <= adjacency_matrix[row++][column++] <= adjacency_matrix[row][column] <= adjacency_matrix[row--][column--])
                    {
                        node *new_node = new node();
                        new_node -> weight = adjacency_matrix[row--][column];
                        new_node -> next = NULL;
                        new_node -> previous = current;
                        current -> next = new_node;
                        current = current -> next;
                        row = row--;
                    }

                    else if (adjacency_matrix[row--][column--] <= adjacency_matrix[row++][column++] <= adjacency_matrix[row][column] <= adjacency_matrix[row--][column])
                    {
                        node *new_node = new node();
                        new_node -> weight = adjacency_matrix[row--][column--];
                        new_node -> next = NULL;
                        new_node -> previous = current;
                        current -> next = new_node;
                        current = current -> next;
                        row = row--;
                        column = column--;
                    }
                }
            }

            return root;
        }

        node* bellman_ford (__uint128_t **adjacency_matrix, int start_row, int start_column, int end_row, int end_column) // Nearby nodes.
        {
            node *root = new node();
            root->weight = adjacency_matrix[start_row][start_column];
            root->next = NULL;
            root->previous = NULL;
            node *current = root;

            int row = start_row, column = start_column;

            while (row != end_row && column != end_column)
            {
                if (row++ < sizeof(adjacency_matrix) && column++ < sizeof(adjacency_matrix[0]) && row-- < sizeof(adjacency_matrix) && column-- < sizeof(adjacency_matrix))
                {
                    if (adjacency_matrix[row++][column] <= adjacency_matrix[row++][column++] <= adjacency_matrix[row--][column] <= adjacency_matrix[row--][column--])
                    {
                        node *new_node = new node();
                        new_node -> weight = adjacency_matrix[row++][column];
                        new_node -> next = NULL;
                        new_node -> previous = current;
                        current -> next = new_node;
                        current = current -> next;
                        row = row++;
                    }

                    else if (adjacency_matrix[row++][column++] <= adjacency_matrix[row++][column] <= adjacency_matrix[row--][column] <= adjacency_matrix[row--][column--])
                    {
                        node *new_node = new node();
                        new_node -> weight = adjacency_matrix[row++][column++];
                        new_node -> next = NULL;
                        new_node -> previous = current;
                        current -> next = new_node;
                        current = current -> next;
                        row = row++;
                        column = column++;
                    }

                    else if (adjacency_matrix[row--][column] <= adjacency_matrix[row++][column++] <= adjacency_matrix[row][column] <= adjacency_matrix[row--][column--])
                    {
                        node *new_node = new node();
                        new_node -> weight = adjacency_matrix[row--][column];
                        new_node -> next = NULL;
                        new_node -> previous = current;
                        current -> next = new_node;
                        current = current -> next;
                        row = row--;
                    }

                    else if (adjacency_matrix[row--][column--] <= adjacency_matrix[row++][column++] <= adjacency_matrix[row][column] <= adjacency_matrix[row--][column])
                    {
                        node *new_node = new node();
                        new_node -> weight = adjacency_matrix[row--][column--];
                        new_node -> next = NULL;
                        new_node -> previous = current;
                        current -> next = new_node;
                        current = current -> next;
                        row = row--;
                        column = column--;
                    }
                }
            }
            
            return root;
        }
};