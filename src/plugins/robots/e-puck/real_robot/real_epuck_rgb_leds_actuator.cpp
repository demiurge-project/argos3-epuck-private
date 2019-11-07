/**
 * @file <argos3/plugins/robot/e-puck/real_robot/real_epuck_rgb_leds_actuator.h>
 *
 * @author Lorenzo Garattoni - <lgaratto@ulb.ac.be>
 */

#include "real_epuck_rgb_leds_actuator.h"
#include <argos3/core/utility/logging/argos_log.h>

namespace argos {

/****************************************/
/*******************
*********************/
enum LedDriverRegisters {
    REG_CNTRL1 = 0x00,
    REG_MISC   = 0x36,
    REG_D1_PWM = 0x16,
    REG_D2_PWM = 0x17
};

CRealEPuckRGBLEDsActuator::CRealEPuckRGBLEDsActuator() {

    m_tDeviceStream = OpenDevice(0x32); // device address of LP55231

}

/****************************************/
/****************************************/

CRealEPuckRGBLEDsActuator::~CRealEPuckRGBLEDsActuator() {

    SetColors(CColor::BLACK);
    SendData();
    CloseDevice(m_tDeviceStream);

}

/****************************************/
/****************************************/

CRealEPuckRGBLEDsActuator::SetEnableBit(){
  WriteRegister(m_tDeviceStream, REG_CNTRL1, 0x40);
}

/****************************************/
/****************************************/

CRealEPuckRGBLEDsActuator::SetMiscReg(){
  WriteRegister(m_tDeviceStream, REG_MISC, 0x53);
}

/****************************************/
/****************************************/

void CRealEPuckRGBLEDsActuator::SendData() {

    SInt8 nData[4];

    nData[0] = REG_D1_PWM;
    nData[1] = 200;
    nData[2] = REG_D2_PWM;
    nData[3] = 100;

/*  nData[0] = m_tLEDSettings[2].GetRed();
    nData[1] = m_tLEDSettings[2].GetGreen();
    nData[2] = m_tLEDSettings[2].GetBlue();
    nData[3] = m_tLEDSettings[1].GetRed();
    nData[4] = m_tLEDSettings[1].GetGreen();
    nData[5] = m_tLEDSettings[1].GetBlue();
    nData[6] = m_tLEDSettings[0].GetRed();
    nData[7] = m_tLEDSettings[0].GetGreen();
    nData[8] = m_tLEDSettings[0].GetBlue(); */
    WriteData(m_tDeviceStream, nData, 4);

}

/****************************************/
/****************************************/

}
