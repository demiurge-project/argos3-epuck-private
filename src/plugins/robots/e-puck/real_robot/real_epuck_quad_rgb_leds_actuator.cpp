/**
 * @file <argos3/plugins/robot/e-puck/real_robot/real_epuck_rgb_leds_actuator.h>
 *
 * @author Lorenzo Garattoni - <lgaratto@ulb.ac.be>
 */

#include "real_epuck_quad_rgb_leds_actuator.h"
#include <argos3/core/utility/logging/argos_log.h>

namespace argos {

/****************************************/
enum GLEDsRegisters {
// REGISTER ADDRESSES
 MODE1 0x00      /**< Mode Register 1 */
 MODE2 0x01      /**< Mode Register 2 */
//LED0
 LED0_ON_L 0x06  /**< LED0 on tick, low byte*/
 LED0_ON_H 0x07  /**< LED0 on tick, high byte*/
 LED0_OFF_L 0x08 /**< LED0 off tick, low byte */
 LED0_OFF_H 0x09 /**< LED0 off tick, high byte */
// etc all 16:  LED15_OFF_H 0x45
 ALLLED_ON_L 0xFA  /**< load all the LEDn_ON registers, low */
 ALLLED_ON_H 0xFB  /**< load all the LEDn_ON registers, high */
 ALLLED_OFF_L 0xFC /**< load all the LEDn_OFF registers, low */
 ALLLED_OFF_H 0xFD /**< load all the LEDn_OFF registers,high */
 PRESCALE 0xFE     /**< Prescaler for PWM output frequency */
 TESTMODE 0xFF     /**< defines the test mode to be entered */

// MODE1 bits
 MODE1_ALLCAL 0x01  /**< respond to LED All Call I2C-bus address */
 MODE1_SUB3 0x02    /**< respond to I2C-bus subaddress 3 */
 MODE1_SUB2 0x04    /**< respond to I2C-bus subaddress 2 */
 MODE1_SUB1 0x08    /**< respond to I2C-bus subaddress 1 */
 MODE1_SLEEP 0x10   /**< Low power mode. Oscillator off */
 MODE1_AI 0x20      /**< Auto-Increment enabled */
 MODE1_EXTCLK 0x40  /**< Use EXTCLK pin clock */
 MODE1_RESTART 0x80 /**< Restart enabled */
// MODE2 bits
 MODE2_OUTNE_0 0x01 /**< Active LOW output enable input */
 MODE2_OUTNE_1 0x02 /**< Active LOW output enable input - high impedience */
 MODE2_OUTDRV 0x04 /**< totem pole structure vs open-drain */
 MODE2_OCH 0x08    /**< Outputs change on ACK vs STOP */
 MODE2_INVRT 0x10  /**< Output logic state inverted */

 I2C_ADDRESS 0x40      /**< Default PCA9685 I2C Slave Address */
 FREQUENCY_OSCILLATOR 25000000 /**< Int. osc. frequency in datasheet */

 PRESCALE_MIN 3   /**< minimum prescale value */
 PRESCALE_MAX 255 /**< maximum prescale value */

};

/*******************
*********************/

CRealEPuckQuadRGBLEDsActuator::CRealEPuckQuadRGBLEDsActuator() {

    m_tDeviceStream = OpenDevice(I2C_ADDRESS);

}

/****************************************/
/****************************************/

CRealEPuckQuadRGBLEDsActuator::~CRealEPuckQuadRGBLEDsActuator() {

    SetColors(CColor::BLACK);
    SendData();
    CloseDevice(m_tDeviceStream);

}

/****************************************/
/****************************************/

void CRealEPuckQuadRGBLEDsActuator::SendData() {

    SInt8 nData[9];
    nData[0] = m_tLEDSettings[2].GetRed();
    nData[1] = m_tLEDSettings[2].GetGreen();
    nData[2] = m_tLEDSettings[2].GetBlue();
    nData[3] = m_tLEDSettings[1].GetRed();
    nData[4] = m_tLEDSettings[1].GetGreen();
    nData[5] = m_tLEDSettings[1].GetBlue();
    nData[6] = m_tLEDSettings[0].GetRed();
    nData[7] = m_tLEDSettings[0].GetGreen();
    nData[8] = m_tLEDSettings[0].GetBlue();
    WriteData(m_tDeviceStream, nData, 9);

}

/****************************************/
/****************************************/

}
