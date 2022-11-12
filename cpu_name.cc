// Copyright(c)2022 Vishal Ahirwar.All rights reserved.
#include <iostream>

std::string get_cpu_name()
{
    uint32_t data[9] = {0};
    _asm {
        cpuid;
        mov data[0], ebx;
        mov data[4], edx;
        mov data[8], ecx;
    }
    return std::string((const char *)data);
};

int main()
{
    std::cout << "\nCPU Installed : " << get_cpu_name() << "\n";
    getchar();
    return 0;
};