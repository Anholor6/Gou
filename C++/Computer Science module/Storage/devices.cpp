struct storage_device{
    std::string data[256][256];
    __uint128_t device_addresses[256];
    __uint128_t mount_point_addresses[256];
};


class devices{
    public:
        storage_device device_cluster[256][256];         
};