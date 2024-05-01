#include <bitset>
#include <cstdio>
#include <cstring>
int main()
{
    std::bitset<4294967296> vip;
    FILE *ips;
    fopen_s(&ips, "ips.txt", "r");
    for (unsigned ip[4], mask; fscanf_s(ips, "%hu.%hu.%hu.%hu/%hu", ip, ip + 1, ip + 2, ip + 3, &mask);)
    {
        for (unsigned long long i = ip[0] << 24 | ip[1] << 16 | ip[2] << 8 | ip[3]; i ^ (i >> mask << mask) ^ (2 << mask - 1); i++)
            ;
    }
}
