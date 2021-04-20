#include "ahci.h"
#include "../BasicRenderer.h"

namespace AHCI{
    AHCIDriver::AHCIDriver(PCI::PCIDeviceHeader* pciBaseAddress){
        this->pciBaseAddress = pciBaseAddress;
        GlobalRenderer->Println("AHCI Driver Instance initialized");
    }

    AHCIDriver::~AHCIDriver(){

    }


}