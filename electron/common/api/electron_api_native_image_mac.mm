// Copyright (c) 2015 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/common/api/electron_api_native_image.h"

#import <Cocoa/Cocoa.h>

namespace electron {

namespace api {

void NativeImage::SetTemplateImage(bool setAsTemplate) {
  [image_.AsNSImage() setTemplate:setAsTemplate];
}

bool NativeImage::IsTemplateImage() {
  return [image_.AsNSImage() isTemplate];
}

}  // namespace api

}  // namespace electron