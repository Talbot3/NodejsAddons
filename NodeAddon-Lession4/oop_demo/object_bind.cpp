//
// Created by flyfishonline on 16-6-22.
//

#include "CustomObject.h"

namespace quit{

    using v8::Local;
    using v8::Object;

    void InitAll(Local<Object> exports) {
        CustomObject::Init(exports);
    }

    NODE_MODULE(addon, InitAll)

}  // namespace quit