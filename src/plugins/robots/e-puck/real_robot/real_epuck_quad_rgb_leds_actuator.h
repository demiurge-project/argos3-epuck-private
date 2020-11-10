/**
 * @file <argos3/plugins/robot/e-puck/real_robot/real_epuck_rgb_leds_actuator.h>
 *
 * @author Lorenzo Garattoni - <lgaratto@ulb.ac.be>
 */

#ifndef REAL_EPUCK_QUAD_RGB_LEDS_ACTUATOR_H
#define REAL_EPUCK_QUAD_RGB_LEDS_ACTUATOR_H

namespace argos {
   class CRealEPuckQuadRGBLEDsActuator;
}

#include <argos3/plugins/robots/e-puck/control_interface/ci_epuck_quad_rgb_leds_actuator.h>
#include <argos3/plugins/robots/e-puck/real_robot/real_epuck_i2c_actuator.h>

namespace argos {

   class CRealEPuckQuadRGBLEDsActuator : virtual public CCI_EPuckQuadRGBLEDsActuator,
                                     virtual public CRealEPuckI2CActuator {

   public:

      CRealEPuckQuadRGBLEDsActuator();
      virtual ~CRealEPuckQuadRGBLEDsActuator();

      virtual void SendData();

   private:

      TI2CDeviceStream m_tDeviceStream;

   };
}
#endif
