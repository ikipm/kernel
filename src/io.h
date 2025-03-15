#ifndef IO_H
#define IO_H

// Get_port_value half (8 bits)
uint8_t gpvh(uint16_t port);
// Get_port_value word (16 bits)
uint16_t gpvw(uint16_t port);
// Get_port_value long (32 bits)
uint32_t gpvl(uint16_t port);

// Set_port_value half (8 bits)
void spvh(uint16_t port, uint8_t value);
// Set_port_value word (16 bits)
void spvw(uint16_t port, uint16_t value);
// Set_port_value long (32 bits)
void spvl(uint16_t port, uint32_t value);

#endif //IO_H
