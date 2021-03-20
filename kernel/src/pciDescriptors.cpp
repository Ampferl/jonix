#include <stdint.h>
#include "cstr.h"

namespace PCI{
    const char* DeviceClasses[]{
            "Unclassified",
            "Mass Storage Controller",
            "Network Controller",
            "Display Controller",
            "Multimedia Controller",
            "Memory Controller",
            "Bridge Device",
            "Simple Communication Controller",
            "Base System Peripheral",
            "Input Device Controller",
            "Docking Station",
            "Processor",
            "Serial Bus Controller",
            "Wireless Controller",
            "Intelligent Controller",
            "Satellite Communication Controller",
            "Encryption Controller",
            "Signal Processing Controller",
            "Processing Accelerator",
            "Non Essential Instrumentation"
    };

    const char* GetVendorName(uint16_t vendorID){
        switch (vendorID){
            case 0x1022:
                return "AMD";
            case 0x10DE:
                return "NVIDIA Corporation";
            case 0x8086:
                return "Intel Corp";
        }
        return to_hex_string(vendorID);
    }
}
