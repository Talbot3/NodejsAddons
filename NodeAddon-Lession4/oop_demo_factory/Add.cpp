//
// Created by goerver on 16-6-30.
// Add.cpp
//

#include "Add.h"

namespace CustomAdd {
    using v8::Context;
    using v8::Function;
    using v8::FunctionCallbackInfo;
    using v8::FunctionTemplate;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::Persistent;
    using v8::String;
    using v8::Value;

    Persistent<Function> Add::constructor;

    Add::Add(double value) : value_(value) { }

    Add::~Add() { }

    void Add::Init(v8::Isolate *isolate) {
        Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
        tpl->SetClassName(String::NewFromUtf8(isolate, "Add"));
        tpl->InstanceTemplate()->SetInternalFieldCount(1);

        NODE_SET_PROTOTYPE_METHOD(tpl, "plusOne", PlusOne);

        constructor.Reset(isolate, tpl->GetFunction());
    }

    void Add::New(const v8::FunctionCallbackInfo<v8::Value> &args) {
        Isolate *isolate = args.GetIsolate();

        if (args.IsConstructCall()) {
            double value = args[0]->IsUndefined()?0:args[0]->NumberValue();
            Add* add = new Add(value);
            add->Wrap(args.This());
            args.GetReturnValue().Set(args.This());
        } else {
            Add::NewInstance(args);
        }
    }

    void Add::NewInstance(const v8::FunctionCallbackInfo<v8::Value> &args) {
        Isolate* isolate = args.GetIsolate();
        const unsigned argc =1;
        Local<Value> argv[argc] = {args[0]};
        Local<Function> cons = Local<Function>::New(isolate,constructor);
        Local<Context> context = isolate->GetCurrentContext();
        Local<Object>  instance = cons->NewInstance(context,argc,argv).ToLocalChecked();
        args.GetReturnValue().Set(instance);
    }

    void Add::PlusOne(const v8::FunctionCallbackInfo<v8::Value> &args) {
        Isolate* isolate = args.GetIsolate();
        Add* add;
        add = node::ObjectWrap::Unwrap<Add>(args.Holder());
        ++add->value_;
        args.GetReturnValue().Set(Number::New(isolate,add->value_));
    }
}
