// Copyright (c) 2013 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/common/electron_command_line.h"

#include "base/command_line.h"
#include "node/deps/uv/include/uv.h"

namespace electron {

// static
std::vector<std::string> ElectronCommandLine::argv_;

// static
void ElectronCommandLine::Init(int argc, const char* const* argv) {
  // Hack around with the argv pointer. Used for process.title = "blah"
  char** new_argv = uv_setup_args(argc, const_cast<char**>(argv));
  for (int i = 0; i < argc; ++i) {
    argv_.push_back(new_argv[i]);
  }
}

#if defined(OS_LINUX)
// static
void ElectronCommandLine::InitializeFromCommandLine() {
  argv_ = base::CommandLine::ForCurrentProcess()->argv();
}
#endif

}  // namespace electron