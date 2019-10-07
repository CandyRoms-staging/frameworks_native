/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifndef FUZZ_LOG_TAG
#error "Must define FUZZ_LOG_TAG"
#endif

#define ENABLE_LOG_FUZZ 1
#define FUZZ_LOG() FuzzLog(FUZZ_LOG_TAG, ENABLE_LOG_FUZZ).log()

class FuzzLog {
public:
    FuzzLog(const std::string& tag, bool log) : mTag(tag), mLog(log) {}
    ~FuzzLog() {
        if (mLog) {
            std::cout << mTag << ": " << mOs.str() << std::endl;
        }
    }

    std::stringstream& log() {
        return mOs;
    }

private:
    std::string mTag;
    bool mLog;
    std::stringstream mOs;
};

std::string hexString(const void* bytes, size_t len);
std::string hexString(const std::vector<uint8_t>& bytes);