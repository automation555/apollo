/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#pragma once

#include <memory>
#include <string>
#include <thread>

#include "modules/drivers/lidar/velodyne/proto/config.pb.h"
#include "modules/drivers/lidar/velodyne/proto/velodyne.pb.h"

#include "cyber/cyber.h"
#include "modules/drivers/lidar/velodyne/driver/driver.h"

namespace apollo {
namespace drivers {
namespace velodyne {

using apollo::cyber::Component;
using apollo::cyber::Reader;
using apollo::cyber::Writer;
using apollo::drivers::velodyne::VelodyneScan;

class VelodyneDriverComponent : public Component<> {
 public:
  ~VelodyneDriverComponent();
  bool Init() override;

 private:
  void device_poll();
  std::shared_ptr<std::thread> device_thread_;
  std::shared_ptr<VelodyneDriver> driver_;  ///< driver implementation class
  std::shared_ptr<apollo::cyber::Writer<VelodyneScan>> writer_;
};

CYBER_REGISTER_COMPONENT(VelodyneDriverComponent)

}  // namespace velodyne
}  // namespace drivers
}  // namespace apollo
