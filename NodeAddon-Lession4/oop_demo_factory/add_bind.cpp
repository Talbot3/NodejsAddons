//
// Created by goerver on 16-6-30.
// add_bind.cpp
//

#include <node/v8.h>
#include "Add.h"

namespace CustomAdd{
    using namespace v8;
    void CreateObject(const FunctionCallbackInfo<Value>& args){
        Add::NewInstance(args);
    }

    void InitAll(Local<Object> exports,Local<Object> module){
        Add::Init(exports->GetIsolate());
        NODE_SET_METHOD(module,"exports",CreateObject);
    }

    NODE_MODULE(Add,InitAll);
}