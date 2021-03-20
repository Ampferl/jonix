#pragma once
#include <stdint.h>
#include "acpi.h"

namespace PCI{
    void EnumeratePCI(ACPI::MCFGHeader* mcfg);
}