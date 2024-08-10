#include <iostream>
#include <modbus/modbus.h>
#include <cerrno>
#include <cstring>
#include <unistd.h> // For sleep()

int main() {
    // Serial port configuration
    const char *serial_port = "/dev/ttyUSB0";
    int baud_rate = 115200;
    char parity = 'N';
    int data_bits = 8;
    int stop_bits = 1;

    // Create a new Modbus context for RTU
    modbus_t *mb = modbus_new_rtu(serial_port, baud_rate, parity, data_bits, stop_bits);
    if (mb == nullptr) {
        std::cerr << "Unable to allocate modbus context" << std::endl;
        return -1;
    }

    // Set the Modbus RTU address (slave ID)
    modbus_set_slave(mb,80 ); // Replace 2 with the correct slave ID

    // Connect to the Modbus server
    if (modbus_connect(mb) == -1) {
        std::cerr << "Connection failed: " << modbus_strerror(errno) << std::endl;
        modbus_free(mb);
        return -1;
    }

    // Define registers and read them
    const int num_registers = 100;
    uint16_t tab_reg[num_registers];

    while (true) {
        // Read registers starting from address 0
        int rc = modbus_read_registers(mb, 0x00, 10, tab_reg);
        std::cout<<tab_reg;
        if (rc == -1) {
            std::cerr << "Read failed: " << modbus_strerror(errno) << std::endl;
            if (errno == EIO) {
                std::cerr << "Error: Invalid CRC or communication error" << std::endl;
            }
            // Optionally, you can retry after a short delay
            sleep(1); // Sleep for 1 second before retrying
            continue; // Skip to the next iteration
        }

        // Print the read registers
        for (int i = 0; i < rc; i++) {
            std::cout << "Register " << i << ": " << tab_reg[i] << std::endl;
        }

        // Delay between reads
        sleep(1); // Sleep for 1 second before the next read
    }

    // Close and free the Modbus context
    modbus_close(mb);
    modbus_free(mb);

    return 0;
}
