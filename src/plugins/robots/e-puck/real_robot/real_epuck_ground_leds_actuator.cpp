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

CRealEPuckRGBLEDsActuator::CRealEPuckRGBLEDsActuator() {

    m_tDeviceStream = OpenDevice(0x32);
    WriteRegister(m_tDeviceStream,0,64); // initialize
    WriteRegister(m_tDeviceStream,54,83); // misc reg

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

void CRealEPuckRGBLEDsActuator::SendData() {

    // SInt8 nData[9];
    // nData[0] = m_tLEDSettings[2].GetRed();
    // nData[1] = m_tLEDSettings[2].GetGreen();
    // nData[2] = m_tLEDSettings[2].GetBlue();
    // nData[3] = m_tLEDSettings[1].GetRed();
    // nData[4] = m_tLEDSettings[1].GetGreen();
    // nData[5] = m_tLEDSettings[1].GetBlue();
    // nData[6] = m_tLEDSettings[0].GetRed();
    // nData[7] = m_tLEDSettings[0].GetGreen();
    // nData[8] = m_tLEDSettings[0].GetBlue();
    // WriteData(m_tDeviceStream, nData, 9);

    // SInt8 nData[21];
    // nData[0] = 0; //0x00; //REG_CNTRL1
    // nData[1] = 64; //0x40;
    // nData[2] = 54; //0x36; //MIsc_reg
    // nData[3] = 83; //0x53;
    // nData[4] = 22; //0x16; //REG_D1_PWM
    // nData[5] = 100; //100; //pwm
    // nData[6] = 0x17; //REG_D2_PWM
    // nData[7] = 100; //pwm
    // nData[8] = 0x18; //REG_D3_PWM
    // nData[9] = 100; //pwm
    // nData[10] = 0x19; //REG_D4_PWM
    // nData[11] = 100; //pwm
    // nData[12] = 0x1a; //REG_D5_PWM
    // nData[13] = 100; //pwm
    // nData[14] = 0x1b; //REG_D6_PWM
    // nData[15] = 100; //pwm
    // nData[16] = 0x1c; //REG_D7_PWM
    // nData[17] = 100; //pwm
    // nData[18] = 0x1d; //REG_D8_PWM
    // nData[19] = 100; //pwm
    // nData[20] = 0x1e; //REG_D9_PWM
    // nData[21] = 100; //pwm
    // WriteData(m_tDeviceStream, nData, 5);

    WriteRegister(m_tDeviceStream,22,0);

    WriteRegister(m_tDeviceStream,23,0);

    WriteRegister(m_tDeviceStream,24,0);

    WriteRegister(m_tDeviceStream,28,0);

    //WriteRegister(m_tDeviceStream,26,100);

    //WriteRegister(m_tDeviceStream,27,100);


}

/****************************************/
/****************************************/

}
