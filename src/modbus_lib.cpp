// modbus_lib.cpp
#include "modbus_lib.h"
#include <iostream>
#include <cerrno>
#include <cstring>
#include <unistd.h> // For sleep()

ModbusRTU2::ModbusRTU2(const char* serial_port, int baud_rate, char parity, int data_bits, int stop_bits) {
    mb_ = modbus_new_rtu(serial_port, baud_rate, parity, data_bits, stop_bits);
}

ModbusRTU2::~ModbusRTU2() {
    if (mb_) {
        modbus_close(mb_);
        modbus_free(mb_);
    }
}

bool ModbusRTU2::connect(int slave_id) {
    if (mb_ == nullptr) {
        std::cerr << "Modbus context not initialized" << std::endl;
        return false;
    }

    modbus_set_slave(mb_, slave_id);
    if (modbus_connect(mb_) == -1) {
        std::cerr << "Connection failed: " << modbus_strerror(errno) << std::endl;
        return false;
    }

    return true;
}

void ModbusRTU2::disconnect() {
    if (mb_) {
        modbus_close(mb_);
    }
}

bool ModbusRTU2::readRegisters(int address, int num_registers, uint16_t* tab_reg) {
    if (mb_ == nullptr) {
        std::cerr << "Modbus context not initialized" << std::endl;
        return false;
    }

    int rc = modbus_read_registers(mb_, address, num_registers, tab_reg);
    if (rc == -1) {
        std::cerr << "Read failed: " << modbus_strerror(errno) << std::endl;
        if (errno == EIO) {
            std::cerr << "Error: Invalid CRC or communication error" << std::endl;
        }
        return false;
    }

    return true;
}

void ModbusRTU2::printRegisters(const uint16_t* tab_reg, int num_registers) const {
    for (int i = 0; i < num_registers; i++) {
        std::cout << "Register " << i << ": " << tab_reg[i] << std::endl;
    }
}
