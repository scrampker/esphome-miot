#pragma once

#include "esphome/core/component.h"
#include "esphome/components/binary_sensor/binary_sensor.h"
#include "../miot.h"

namespace esphome {
namespace miot {

class MiotBinarySensor : public binary_sensor::BinarySensor, public Component {
 public:
  void setup() override;
  void dump_config() override;

  void set_miot_config(Miot *parent, uint32_t siid, uint32_t piid, bool poll) {
    this->parent_ = parent;
    this->siid_ = siid;
    this->piid_ = piid;
    this->poll_ = poll;
  }

 protected:
  Miot *parent_;
  uint32_t siid_{0};
  uint32_t piid_{0};
  bool poll_{true};
};

}  // namespace miot
}  // namespace esphome