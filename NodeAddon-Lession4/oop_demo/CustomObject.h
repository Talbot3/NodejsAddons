//
// Created by goerver on 16-6-22.
//

#ifndef NODEADDONE_LESSION4_CUSTOM_OBJECT_H
#define NODEADDONE_LESSION4_CUSTOM_OBJECT_H
#include "node/node.h"
#include <node/node_object_wrap.h>
#include <node/v8.h>
namespace quit{
    class CustomObject:public node::ObjectWrap {
    public:
        //唯一一个公开的方法，Init函数
        static void Init(v8::Local<v8::Object> exports);

    private:
        explicit CustomObject(double value = 0);
        ~CustomObject();
        //此处函数参数 `&`,引用关键字不可少
        static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
        static void PlusOne(const v8::FunctionCallbackInfo<v8::Value>& args);
        static v8::Persistent<v8::Function> constructor;
        double value_;
    };
}
#endif //NODEADDONE_LESSION4_CUSTOM_OBJECT_H
