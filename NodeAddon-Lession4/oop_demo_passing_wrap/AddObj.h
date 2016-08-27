//
// Created by goerver on 16-7-1.
//

#ifndef NODEADDONE_LESSION4_ADDOBJ_H
#define NODEADDONE_LESSION4_ADDOBJ_H

#include <node/node.h>
#include <node/node_object_wrap.h>
namespace demo {

    class MyObject : public node::ObjectWrap {
    public:
        static void Init(v8::Isolate* isolate);
        static void NewInstance(const v8::FunctionCallbackInfo<v8::Value>& args);
        inline double value() const { return value_; }

    private:
        explicit MyObject(double value = 0);
        ~MyObject();

        static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
        static v8::Persistent<v8::Function> constructor;
        double value_;
    };

}  // namespace demo

#endif //NODEADDONE_LESSION4_ADDOBJ_H
