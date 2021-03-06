#include "ahci.h"
#include "../BasicRenderer.h"
#include "../paging/PageTableManager.h"

namespace AHCI{

    #define HBA_PORT_DEV_PRESENT 0x3
    #define HBA_PORT_IPM_ACTIVE 0x1
    #define SATA_SIG_ATAPI 0xEB140101
    #define SATA_SIG_ATA 0x000000101
    #define SATA_SIG_SEMB 0xC33C0101
    #define SATA_SIG_PM 0x96690101

    PortType CheckPortType(HBAPort* port){
        uint32_t sataStatus = port->sataStatus;

        uint8_t interfacePowerManagement = (sataStatus >> 8) & 0b111;
        uint8_t deviceDetection = sataStatus & 0b111;

        if(deviceDetection != HBA_PORT_DEV_PRESENT) return PortType::None;
        if(interfacePowerManagement != HBA_PORT_IPM_ACTIVE) return PortType::None;

        switch (port->signature){
        case SATA_SIG_ATAPI:
            return PortType::SATAPI;
        case SATA_SIG_ATA:
            return PortType::SATA;
        case SATA_SIG_PM:
            return PortType::PM;
        case SATA_SIG_SEMB:
            return PortType::SEMB;
        default:
            return PortType::None;
        }
    }

    void AHCIDriver::ProbePorts(){
        uint32_t portsImplemented = ABAR->portsImplemented;
        for(int i = 0; i<32;++i){
            if(portsImplemented & (1 << i)){
                PortType portType = CheckPortType(&ABAR->ports[i]);

                if(portType == PortType::SATA){
                    GlobalRenderer->Println("SATA DRIVE");
                }else if(portType == PortType::SATAPI){
                    GlobalRenderer->Println("SATAPI DRIVE");
                }else{
                    GlobalRenderer->Println("Not important now");
                }
           } 
        }
    }

    AHCIDriver::AHCIDriver(PCI::PCIDeviceHeader* pciBaseAddress){
        this->pciBaseAddress = pciBaseAddress;
        GlobalRenderer->Println("AHCI Driver Instance initialized");

        ABAR = (HBAMemory*)((PCI::PCIHeader0*)pciBaseAddress)->BAR5;

        GlobalPageTableManager.MapMemory(ABAR, ABAR);
        ProbePorts();
    }

    AHCIDriver::~AHCIDriver(){

    }


}