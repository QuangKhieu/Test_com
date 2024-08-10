// // src/main.cpp
#include "modbus_lib.h"
#include <iostream>
#include <cstdint>
#include <unistd.h> // For sleep()

int main() {

    std::cout<<("yes");
    ModbusRTU2 modbus("/dev/ttyUSB0", 115200, 'N', 8, 1);

    if (!modbus.connect(80)) {
        return -1;
    }

    const int num_registers = 10;
    uint16_t tab_reg[num_registers];

    while (true) {
        if (!modbus.readRegisters(52, num_registers, tab_reg)) {
            sleep(1);
            continue;
        }

        modbus.printRegisters(tab_reg, num_registers);
        sleep(1);
    }

    modbus.disconnect();

    return 0;
}
// src/main.cpp
// src/main.cpp
//#include "hello.h"
// #include <modbus/modbus.h>
// #include <iostream>
// #include <stdexcept>
// #include "modbus_lib.h"
// int main() {
//     // Serial port configuration
//     const char *serial_port = "/dev/ttyUSB0";
//     int baud_rate = 115200;
//     char parity = 'N';
//     int data_bits = 8;
//     int stop_bits = 1;

//     // Create a new Modbus context for RTU
//     modbus_t *mb = modbus_new_rtu(serial_port, baud_rate, parity, data_bits, stop_bits);
//     if (mb == nullptr) {
//         std::cerr << "Unable to create Modbus context" << std::endl;
//         return 1;
//     }

//     // Set Modbus address (slave ID)
//     const int slave_id = 80;
//     modbus_set_slave(mb, slave_id);

//     // Connect to the Modbus server
//     if (modbus_connect(mb) == -1) {
//         std::cerr << "Connection failed: " << modbus_strerror(errno) << std::endl;
//         modbus_free(mb);
//         return 1;
//     }

//     std::cout << "Modbus connection established." << std::endl;

//     // Example of reading registers (address 0, count 1)
//     uint16_t tab_reg[32];
//     int num = modbus_read_registers(mb, 0, 10, tab_reg);
//     if (num == -1) {
//         std::cerr << "Read failed: " << modbus_strerror(errno) << std::endl;
//         modbus_close(mb);
//         modbus_free(mb);
//         return 1;
//     }

//     std::cout << "Register value: " << tab_reg[0] << std::endl;

//     // Close the Modbus connection
//     modbus_close(mb);
//     modbus_free(mb);

//     return 0;
// }
