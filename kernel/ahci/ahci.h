#pragma once
#include <stdint.h>
#include "../pci.h"

namespace AHCI {
    class AHCIDriver{
        public:
            AHCIDriver(PCI::PCIDeviceHeader* pciBaseAddress);
            ~AHCIDriver();
            PCI::PCIDeviceHeader* pciBaseAddress;
    };
}