/**
 * @file <argos3/plugins/robot/e-puck/real_robot/real_epuck_ground_leds_actuator.h>
 *
 * @author Muhammad Salman - <Muhammad.Salman@ulb.ac.be>
 */

#include "real_epuck_ground_leds_actuator.h"
#include <argos3/core/utility/logging/argos_log.h>

namespace argos {

/****************************************/
/***
*Ground_leds_actuator is based on I2C controlled LEDs driver IC LP55231
*http://www.ti.com/lit/ds/symlink/lp55231.pdf
*********************/
enum GLEDsRegisters {
  REG_CNTRL1 = 0,  // Write 64 to this register to enable the chip
  REG_MISC   = 54,  // Write 83 enable internal clock & charge pump & write auto increment
  REG_D1_PWM  = 22, // Write UInt8 un_PWM value 0-255 (0% - 100%) to turn on D1 LED
  REG_D2_PWM  = 23, // Write UInt8 un_PWM value 0-255 (0% - 100%) to turn on D2 LED
  REG_D3_PWM  = 24, // Write UInt8 un_PWM value 0-255 (0% - 100%) to turn on D3 LED
  REG_D4_PWM  = 25, // Write UInt8 un_PWM value 0-255 (0% - 100%) to turn on D4 LED
  REG_D5_PWM  = 26, // Write UInt8 un_PWM value 0-255 (0% - 100%) to turn on D5 LED
  REG_D6_PWM  = 27, // Write UInt8 un_PWM value 0-255 (0% - 100%) to turn on D6 LED
  REG_D7_PWM  = 28, // Write UInt8 un_PWM value 0-255 (0% - 100%) to turn on D7 LED
  REG_D8_PWM  = 29, // Write UInt8 un_PWM value 0-255 (0% - 100%) to turn on D8 LED
  REG_D9_PWM  = 30, // Write UInt8 un_PWM value 0-255 (0% - 100%) to turn on D9 LED
  REG_D9_OUTPUT_CONTROL = 4, //
  REG_D1TOD8_OUTPUT_CONTROL = 5, //
  REG_RESET = 61   // Write 255 to reset the LED driver
};

enum DriverParameters{
  DRIVER_PWM = 220 // @param DRIVER_PWM Can be modified to set the brightness [0 - 255]
};


CRealEPuckGroundLEDsActuator::CRealEPuckGroundLEDsActuator() {

    m_tDeviceStream = OpenDevice(0x32);
    Init_LED_Driver();

}

/****************************************/
/****************************************/

CRealEPuckGroundLEDsActuator::~CRealEPuckGroundLEDsActuator() {

    SwitchAll(false);
    SendData();
    CloseDevice(m_tDeviceStream);

}

/****************************************/
/****************************************/
 void CRealEPuckGroundLEDsActuator::Init_LED_Driver(){

   WriteRegister(m_tDeviceStream,REG_CNTRL1,64); // initialize
   WriteRegister(m_tDeviceStream,REG_MISC,83); // misc reg
/***
* Disable all outputs of the Driver
***/
   WriteRegister(m_tDeviceStream,REG_D9_OUTPUT_CONTROL,0);
   WriteRegister(m_tDeviceStream,REG_D1TOD8_OUTPUT_CONTROL,0);
/***
* Set PWM of each LED
***/
  InitPWM(DRIVER_PWM);
 }

 /****************************************/
 /****************************************/

 void CRealEPuckGroundLEDsActuator::InitPWM(UInt8 un_PWM_Ground_LED) {
   WriteRegister(m_tDeviceStream,REG_D1_PWM,un_PWM_Ground_LED);
   WriteRegister(m_tDeviceStream,REG_D2_PWM,un_PWM_Ground_LED);
   WriteRegister(m_tDeviceStream,REG_D3_PWM,un_PWM_Ground_LED);
   WriteRegister(m_tDeviceStream,REG_D4_PWM,un_PWM_Ground_LED);
   WriteRegister(m_tDeviceStream,REG_D5_PWM,un_PWM_Ground_LED);
   WriteRegister(m_tDeviceStream,REG_D6_PWM,un_PWM_Ground_LED);
   WriteRegister(m_tDeviceStream,REG_D7_PWM,un_PWM_Ground_LED);
   WriteRegister(m_tDeviceStream,REG_D8_PWM,un_PWM_Ground_LED);
   WriteRegister(m_tDeviceStream,REG_D9_PWM,un_PWM_Ground_LED);
 }

/****************************************/
/****************************************/
void CRealEPuckGroundLEDsActuator::SendData() {

    WriteRegister(m_tDeviceStream,REG_D1TOD8_OUTPUT_CONTROL,GetD1ToD8());
    WriteRegister(m_tDeviceStream,REG_D9_OUTPUT_CONTROL,GetD9());
  }

/****************************************/
/****************************************/

void CRealEPuckGroundLEDsActuator::SetPWM(UInt8 un_PWM_Ground_LED){
  CCI_EPuckGroundLEDsActuator::SetPWM(un_PWM_Ground_LED);
  InitPWM(un_PWM_Ground_LED);
}

}
