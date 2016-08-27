//
// Created by goerver on 16-6-30.
//

#ifndef NODEADDONE_LESSION4_ADD_H
#define NODEADDONE_LESSION4_ADD_H
//Add.h
#include <node/node_object_wrap.h>
#include <node/node.h>
namespace CustomAdd{
    class Add: public node::ObjectWrap {
    public:
        static void Init(v8::Isolate* isolate);
        static void NewInstance(const v8::FunctionCallbackInfo<v8::Value>& args);

    private:
        explicit Add(double value=0);
        ~Add();
        static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
        static void PlusOne(const v8::FunctionCallbackInfo<v8::Value>& args);
        static v8::Persistent<v8::Function> constructor;
        double value_;

    };
}



#endif //NODEADDONE_LESSION4_ADD_H
