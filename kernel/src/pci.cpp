#include "pci.h"

namespace PCI{

    void EnumerateFunction(uint64_t deviceAddress, uint64_t function){

    }

    void EnumerateDevice(uint64_t busAddress, uint64_t device){

    }

    void EnumerateBus(uint64_t baseAddress, uint64_t bus){
        uint64_t offset = bus << 20;

        uint64_t busAddress = baseAddress + offset;
        GlobalPageTableManager.MapMemory((void*)busAddress, (void*)busAddress);

        PCIDeviceHeader* pciDeviceHeader = (PCIDeviceHeader*)busAddress;

        if(pciDeviceHeader->DeviceID == 0) return;
        if(pciDeviceHeader->DeviceID == 0xFFFF) return;

        for(uint64_t device = 0; device < 32; device++){
            EnumerateDevice(busAddress, device);
        }
    }

    void EnumeratePCI(ACPI::MCFGHeader* mcfg){
        int entries = ((mcfg->Header.Length) - sizeof(ACPI::MCFGHeader)) / sizeof(ACPI::DeviceConfig);
        for (int t = 0; t < entries; t++) {
            ACPI::DeviceConfig* newDeviceConfig = (ACPI::DeviceConfig*)((uint64_t)mcfg + sizeof(ACPI::MCFGHeader) + (sizeof(ACPI::DeviceConfig) * t));
            for (uint64_t bus = newDeviceConfig->StartBus; bus < newDeviceConfig->EndBus; bus++) {
                EnumerateBus(newDeviceConfig->BaseAddress, bus);
            }

        }
    }

}