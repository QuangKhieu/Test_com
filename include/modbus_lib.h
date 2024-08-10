// modbus_lib.h
#ifndef MODBUS_LIB_H
#define MODBUS_LIB_H

#include <modbus/modbus.h>
#include <cstdint>

class ModbusRTU2 {
public:
    ModbusRTU2(const char* serial_port, int baud_rate, char parity, int data_bits, int stop_bits);
    ~ModbusRTU2();

    bool connect(int slave_id);
    void disconnect();

    bool readRegisters(int address, int num_registers, uint16_t* tab_reg);
    void printRegisters(const uint16_t* tab_reg, int num_registers) const;

private:
    modbus_t* mb_;
};

#endif // MODBUS_LIB_H
