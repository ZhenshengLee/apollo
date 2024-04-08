/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
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

#include "modules/planning/scenarios/traffic_light_protected/stage_approach.h"

#include "gtest/gtest.h"
#include "modules/planning/planning_interface_base/scenario_base/proto/scenario_pipeline.pb.h"
#include "cyber/common/file.h"
#include "cyber/common/log.h"
#include "modules/planning/scenarios/traffic_light_protected/context.h"

namespace apollo {
namespace planning {

class TrafficLightProtectedStageApproachTest : public ::testing::Test {
 public:
  virtual void SetUp() {
    config_.set_name("TRAFFIC_LIGHT_PROTECTED_APPROACH");
    injector_ = std::make_shared<DependencyInjector>();
  }

 protected:
  StagePipeline config_;
  std::shared_ptr<DependencyInjector> injector_;
  TrafficLightProtectedContext context_;
};

TEST_F(TrafficLightProtectedStageApproachTest, Init) {
  TrafficLightProtectedStageApproach traffic_light_protected_stage_approach;
  traffic_light_protected_stage_approach.Init(
      config_, injector_, "scenarios/raffic_light_protected/conf", &context_);
  EXPECT_EQ(traffic_light_protected_stage_approach.Name(),
            ("TRAFFIC_LIGHT_PROTECTED_APPROACH"));
}

}  // namespace planning
}  // namespace apollo